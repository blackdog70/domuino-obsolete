/*
 * automatic.cpp
 *
 *  Created on: 07/nov/2015
 *      Author: erika
 */

#include "automatic.h"

const char firstrun[] = "\"First run.\"\0";
//#define FIRSTRUN strcpy_P( buffer, pgm_read_word( &(firstrun) ) );

const char err[] = "ERR\0";
const char ok[] = "OK\0";
const char null[] = "null\0";

//const char crcerror[] = "\"EEProm CRC error. Firmware defaults used.\"\0";
//const char outrange01[] = "\"Value out of range 0..1\"\0";
//const char outrange06[] = "\"Id out of range 0..6\"\0";
//const char outrange0255[] = "\"Value out of range 0..255\"\0";

const char crcerror[] = "";
const char outrange01[] = "";
const char outrange06[] = "";
const char outrange0255[] = "";


const char msgfmt[] = "{\"T\":%lu,\"C\":\"%s\",\"S\":\"%s\",\"D\":%s}";

Automatic::Automatic() {
	for(int i=0; i<OUTPUTS; i++) {
		outputs[i] = new Output();
	};
	for(int i=0; i<INPUTS; i++) {
		inputs[i] = new Input();
	};
	for(int i=0; i<EMONS; i++) {
		emon[i] = new EnergyMonitor();
	}
	communication = new Communication();
	switch (get_config()) {
		case 1:
			send("INIT", ok, firstrun);
			break;
		case 2:
			send("INIT", err, crcerror);
			break;
		default:
			send("INIT", ok, "");
			break;
	};
	for (int i=0; i<OUTPUTS; i++) {
		outputs[i]->config(4+i, eeconfig.outputs[i].mode, eeconfig.outputs[i].state, eeconfig.outputs[i].value);
	}
	for (int i=0; i<INPUTS; i++) {
		inputs[i]->config(14+i, eeconfig.inputs[i].mode, eeconfig.inputs[i].state, eeconfig.inputs[i].value, outputs[eeconfig.io_relation[i]]);
	}
	for (int i=0; i<EMONS; i++) {
		emon[i]->current((unsigned int) A6+i, eeconfig.emon_calib[i]);
	}
}

Automatic::~Automatic() {
	// TODO Auto-generated destructor stub
}

void Automatic::on() {
	for(int i=0; i<OUTPUTS; i++) {
		pinMode(outputs[i]->pin, OUTPUT);
	}
	for(int i=0; i<INPUTS; i++) {
		pinMode(inputs[i]->pin, INPUT);
	}
	pinMode(10, OUTPUT);    // CPU pin
	digitalWrite(10, HIGH); // Set CPU pin ON
}

void Automatic::refresh() {
	for(int i=0; i<INPUTS; i++) {
		inputs[i]->refresh();
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
	communication->write(msg);
}

void Automatic::execCommand() {
	#define COMMAND (char *)communication->tokens[0]
	#define COMMAND1 (char *)communication->tokens[1]
	#define COMMAND2 (char *)communication->tokens[2]

	if (!communication->read()) {
		return;
	}

	if(!strcmp(COMMAND, "SET")) {
		if(strcmp(COMMAND1, "") && strcmp(COMMAND2, "")) {
			if(strcmp(COMMAND1, "0") >= 0 && strcmp(COMMAND1, "6") <= 0) {
				byte id = atoi(COMMAND1);
				if(!strcmp(COMMAND2, "0")) {
					outputs[id]->reset();
					send(COMMAND, ok, "");
				} else if (!strcmp(COMMAND2, "1")) {
					outputs[id]->set();
					send(COMMAND, ok, "");
				} else {
					send(COMMAND, err, outrange01);
				}
			} else {
				send(COMMAND, err, outrange06);
			}
		} else {
			send(COMMAND, err, "");
		}
	} else if(!strcmp(COMMAND, "DIMMER")) {
		if(strcmp(COMMAND1, "") && strcmp(COMMAND2, "")) {
			if(strcmp(COMMAND1, "0") >= 0 && strcmp(COMMAND1, "6") <= 0) {
				byte id = atoi(COMMAND1);
				if(strcmp(COMMAND2, "000") >= 0 && strcmp(COMMAND2, "255") <= 0) {
					byte value = atoi(COMMAND2);
					outputs[id]->value = value;
					send(COMMAND, ok, "");
				} else {
					send(COMMAND, err, outrange0255);
				}
			} else {
				send(COMMAND, err, outrange06);
			}
		} else {
			send(COMMAND, err, "");
		}
	} else if(!strcmp(COMMAND, "GETS")) {
		if(strcmp(COMMAND1, "")) {
			char data[] = "[0,0,0,0,0,0]";
			int pos = 1;

			if(!strcmp(COMMAND1, "I")) {
				for(int i=0; i<INPUTS; i++) {
					data[pos] = inputs[i]->state + '0';
					pos += 2;
				}
				send(COMMAND, ok, data);
			} else if(!strcmp(COMMAND1, "O")) {
				for(int i=0; i<OUTPUTS; i++) {
					data[pos] = outputs[i]->state + '0';
					pos += 2;
				}
				send(COMMAND, ok, data);
			} else {
				send(COMMAND, err, "");
			}
		}
	} else if(!strcmp(COMMAND, "GETV")) {
		if(strcmp(COMMAND1, "")) {
			char data[] = "[000,000,000,000,000,000]";
			char partial[4];
			int pos = 1;

			if(!strcmp(COMMAND1, "I")) {
				for(int i=0; i<INPUTS; i++) {
					sprintf(partial, "%3u", inputs[i]->value);
					memcpy(data+pos, partial, 3);
				   	pos += 4;
				}
				send(COMMAND, ok, data);
			} else if(!strcmp(COMMAND1, "O")) {
				for(int i=0; i<OUTPUTS; i++) {
					sprintf(partial, "%3u", outputs[i]->value);
					memcpy(data+pos, partial, 3);
				   	pos += 4;
				}
				send(COMMAND, ok, data);
			} else {
				send(COMMAND, err, "");
			}
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
		char data[] = "[00000.00,00000.00]";
		char partial[9];
		int pos = 1;

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

			sprintf(partial, "%5u.%-2u", module, remainder);
			memcpy(data+pos, partial, 8);
		   	pos += 9;
		}
		send(COMMAND, ok, data);
	} else if (!strcmp(COMMAND, "FREEMEM")) {
		char data[6];
		sprintf(data, "%u", freeMemory());
		send(COMMAND, ok, data);
	} else {
		send(COMMAND, err, "");
	}
}
