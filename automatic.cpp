/*
 * automatic.cpp
 *
 *  Created on: 07/nov/2015
 *      Author: erika
 */

#include "automatic.h"

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
	config();
}

Automatic::~Automatic() {
	// TODO Auto-generated destructor stub
}

void Automatic::config() {
	outputs[0]->config(4, DIMMABLE, LOW, 0);
	outputs[1]->config(5, DIGITAL, LOW, 0);
	outputs[2]->config(6, DIGITAL, LOW, 0);
	outputs[3]->config(7, DIGITAL, LOW, 0);
	outputs[4]->config(8, DIGITAL, LOW, 0);
	outputs[5]->config(9, DIGITAL, LOW, 0);
	inputs[0]->config(14, DIGITAL, LOW, 0, outputs[0]);
	inputs[1]->config(15, DIGITAL, LOW, 0, outputs[1]);
	inputs[2]->config(16, DIGITAL, LOW, 0, outputs[2]);
	inputs[3]->config(17, DIGITAL, LOW, 0, outputs[3]);
	inputs[4]->config(18, DIGITAL, LOW, 0, outputs[4]);
	inputs[5]->config(19, DIGITAL, LOW, 0, outputs[5]);
	//inputs[6]->config(A6, ANALOG, LOW, 0, NULL);
	//inputs[7]->config(A7, ANALOG, LOW, 0, NULL);
	//pinMode(A6, INPUT);
	//pinMode(A7, INPUT);
	emon[0]->current(A6, 20.73);       // Current: input pin, calibration.
	emon[1]->current(A7, 20.73);       // Current: input pin, calibration.
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

void Automatic::show() {
	send("SHOW", "ALIVE", "");
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
	const char null[] = "null\0";

	if (strcmp(data, "") == 0)
		d = (char *)null;
	else
		d = (char *)data;
	sprintf(msg, "{\"T\":%lu,\"C\":\"%s\",\"S\":\"%s\",\"D\":%s}", (unsigned long)now(), command, status, d);
	communication->write(msg);
}

void Automatic::execCommand() {
	#define COMMAND (char *)communication->tokens[0]
	#define COMMAND1 (char *)communication->tokens[1]
	#define COMMAND2 (char *)communication->tokens[2]

	const char* err = "ERR";
	const char* ok = "OK";

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
					send(COMMAND, err, "\"Value out of range 0..1\"");
				}
			} else {
				send(COMMAND, err, "\"Id out of range 0..6\"");
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
					send(COMMAND, err, "\"Value out of range 0..255\"");
				}
			} else {
				send(COMMAND, err, "\"Id out of range 0..6\"");
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
