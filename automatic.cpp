/*
 * automatic.cpp
 *
 *  Created on: 07/nov/2015
 *      Author: erika
 */

#include "automatic.h"

const char firstrun[] = "\"First run\"\0";
//#define FIRSTRUN strcpy_P( buffer, pgm_read_word( &(firstrun) ) );

const char err[] = "ERR\0";
const char ok[] = "OK\0";
const char null[] = "null\0";

const char crcerror[] = "\"CRC\"\0";
const char outrange01[] = "\"0..1\"\0";
const char outrange06[] = "\"0..6\"\0";
const char outrange0255[] = "\"0..255\"\0";

const char msgfmt[] = "{\"T\":%lu,\"C\":\"%s\",\"S\":\"%s\",\"D\":%s}";

Automatic::Automatic() {
	for(int i=0; i<PINS; i++) {
		outputs[i] = new Output();
		inputs[i] = new Input();
	};
	for(int i=0; i<EMONS; i++) {
		emon[i] = new EnergyMonitor();
	}
	communication = new Communication();
	load_config();
}

Automatic::~Automatic() {
	// TODO Auto-generated destructor stub
}

void Automatic::load_config() {
	Config eeconfig;
	char data[15] = "";

	switch (get_config(eeconfig)) {
		case 1:
			strcpy(data, firstrun);
			break;
		case 2:
			strcpy(data, crcerror);
			break;
	};
	send("INIT", ok, data);
	for (int i=0; i<PINS; i++) {
		outputs[i]->config(4+i, eeconfig.outputs[i].mode, eeconfig.outputs[i].state, eeconfig.outputs[i].value);
		inputs[i]->config(14+i, eeconfig.inputs[i].mode, eeconfig.inputs[i].state, eeconfig.inputs[i].value);
	}
	for (int i=0; i<EMONS; i++) {
		emon[i]->current((unsigned int) A6+i, eeconfig.emon_calib[i]);
	}

	strcpy(password, eeconfig.password);
}

void Automatic::save_config() {
	Config eeconfig;

	eeconfig.domuino_id = domuino_id;
	for (int i=0; i<PINS; i++) {
		eeconfig.outputs[i].mode = outputs[i]->mode;
		eeconfig.outputs[i].state = outputs[i]->state;
		eeconfig.outputs[i].value = outputs[i]->value;

		eeconfig.inputs[i].mode = inputs[i]->mode;
		eeconfig.inputs[i].state = inputs[i]->state;
		eeconfig.inputs[i].value = inputs[i]->value;

		eeconfig.io_relation[i] = i;
	}
	for (int i=0; i<EMONS; i++) {
		eeconfig.emon_calib[i] = 20.73;
	}
	store_config(eeconfig);
}

void Automatic::on() {
	for(int i=0; i<PINS; i++) {
		pinMode(outputs[i]->pin, OUTPUT);
		pinMode(inputs[i]->pin, INPUT);
	}
	pinMode(10, OUTPUT);    // CPU pin
	digitalWrite(10, HIGH); // Set CPU pin ON
}

void Automatic::refresh() {
	for(int i=0; i<PINS; i++) {
		inputs[i]->get();
	}
	execCommand();
}

void Automatic::send(const char *command, const char *status, const char *data) {
	char msg[MSGLEN];
	char *d;

	if (strcmp(data, "") == 0)
		d = (char *)null;
	else
		d = (char *)data;
	sprintf(msg, msgfmt, (unsigned long)now(), command, status, d);
	communication->write(password, msg);
}

void Automatic::execCommand() {
	#define COMMAND (char *)communication->tokens[0]
	#define COMMAND1 (char *)communication->tokens[1]
	#define COMMAND2 (char *)communication->tokens[2]

	if (!communication->read(password)) {
		return;
	}

	if(!strncmp(COMMAND, "SET", 3)) {
		if(strcmp(COMMAND1, "") && strcmp(COMMAND2, "")) {
			int id = atoi(COMMAND1);
			if((id >= 0) && (id <= 6)) {
				if(!strcmp(COMMAND+3, "P")) {
					int value = atoi(COMMAND2);

					switch(atoi(COMMAND2)) {
					case 0:
						outputs[id]->reset();
						break;
					case 1:
						outputs[id]->set();
						break;
					}
					if(value >=0 and value <= 1) {
						send(COMMAND, ok, "");
					} else {
						send(COMMAND, err, outrange01);
					}
				} else if (!strcmp(COMMAND+3, "V")) {
					int value = atoi(COMMAND2);
					if((value >= 0) && (value <= 255)) {
						outputs[id]->value = value;
						send(COMMAND, ok, "");
					} else {
						send(COMMAND, err, outrange0255);
					}
				} else {
					send(COMMAND, err, "");
				}
			} else {
				send(COMMAND, err, outrange06);
			}
		} else {
			send(COMMAND, err, "");
		}
	} else if(!strncmp(COMMAND, "GET", 3)) {
		if(strcmp(COMMAND1, "")) {
			char data[26] = "[";
			char partial[3] = "";
			unsigned char value = 0;

			for(int i=0; i<PINS; i++) {
				if(!strcmp(COMMAND+3, "P")) {			//GETP
					if(!strcmp(COMMAND1, "I")) {
						value = inputs[i]->state;
					} else if (!strcmp(COMMAND1, "O")) {
						value = outputs[i]->state;
					}
				} else if (!strcmp(COMMAND+3, "V")) {	//GETV
					if(!strcmp(COMMAND1, "I")) {
						value = inputs[i]->value;
					} else if (!strcmp(COMMAND1, "O")) {
						value = outputs[i]->value;
					}
				} else {
					break;
				}
				sprintf(partial, "%3i,", value);
				strcat(data, partial);
			}
			if(strcmp(data, "[") != 0) {
				data[strlen(data)-1] = ']';
				send(COMMAND, ok, data);
			} else {
				send(COMMAND, err, "");
			}
		} else {
			send(COMMAND, err, "");
		}
	} else if (!strcmp(COMMAND, "TIME")) {
		if(strcmp(COMMAND1, "")) {
			const unsigned long DEFAULT_TIME = 1357041600; // Jan 1 2013
			errno = 0;
			unsigned long pctime = atol(COMMAND1);
			if (errno == ERANGE) {
				pctime = DEFAULT_TIME;
			}
			if( pctime >= DEFAULT_TIME) { // check the integer is a valid time (greater than Jan 1 2013)
				setTime(pctime); // Sync Arduino clock to the time received on the serial port
			}
			send(COMMAND, ok, "");
		} else {
			send(COMMAND, err, "");
		}
	} else if (!strcmp(COMMAND, "POWER")) {
		char data[20] = "[";
		char partial[10];

		for (int i=0; i<EMONS; i++) {
			double Irms = emon[i]->calcIrms(1480);  // Calculate Irms only
			double power = Irms * 229.0;

			if(power == NAN) {
				power = -1.0;
			} else if(power <= 600.0) {
				power *= 0.95;
			}
			int module = (int)power;
			int remainder = (int)((power - module) * 100);

			sprintf(partial, "%5u.%-2u,", module, remainder);
			strcat(data, partial);
		}
		data[strlen(data)-1] = ']';
		send(COMMAND, ok, data);
	} else if (!strcmp(COMMAND, "FREEMEM")) {
		char data[6];
		sprintf(data, "%4u", freeMemory());
		send(COMMAND, ok, data);
	} else {
		send(COMMAND, err, "");
	}
}
