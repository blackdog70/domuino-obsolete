/*
 * exec.cpp
 *
 *  Created on: Apr 9, 2016
 *      Author: sebastiano
 */
#include "exec.h"

Communication communication(password);

const char firstrun[] = "\"First run\"\0";
//#define FIRSTRUN strcpy_P( buffer, pgm_read_word( &(firstrun) ) );

const char err[] = "ERR\0";
const char ok[] = "OK\0";

//const char crcerror[] = "\"CRC\"\0";
//const char outrange01[] = "\"0..1\"\0";
//const char outrange05[] = "\"0..5\"\0";
//const char outrange0255[] = "\"0..255\"\0";

const char crcerror[] = "";
const char outrange01[] = "";
const char outrange05[] = "";
const char outrange0255[] = "";

void exec_toggle(char *param1) {
	if (strcmp(param1, "")) {
		int id = atoi(param1);
		if ((id >= 0) && (id <= 5)) {
			char param[2] = "O";

			output[id].toggle();
			exec_get_pin(param);
		} else {
			communication.send(outrange05);
		}
	} else {
		communication.send(err);
	}
}

void exec_set(char *type, char *param1, char *param2) {
	if (strcmp(param1, "") && strcmp(param2, "")) {
		int id = atoi(param1);
		if ((id >= 0) && (id <= 5)) {
			if (!strcmp(type, "P")) {
				int value = atoi(param2);

				if (value >= 0 and value <= 1) {
					switch(value) {
						case 0:
							output[id].reset();
							break;
						case 1:
							output[id].set();
							break;
					}
					communication.send(ok);
				} else {
					communication.send(outrange01);
				}
			} else if (!strcmp(type, "V")) {
				int value = atoi(param2);
				if ((value >= 0) && (value <= 255)) {
					output[id].value = value;
					communication.send(ok);
				} else {
					communication.send(outrange0255);
				}
			} else {
				communication.send(err);
			}
		} else {
			communication.send(outrange05);
		}
	} else {
		communication.send(err);
	}
}

void exec_emon(char *param1, char *param2) {
	if (strcmp(param1, "") && strcmp(param2, "")) {
		int id = atoi(param1);
		if ((id >= 0) && (id <= 1)) {
			float value = atof(param2);

			emon[id].current((unsigned int) A6 + id, (float) value / 100.0);
			communication.send(ok);
		} else {
			communication.send(outrange01);
		}
	} else {
		communication.send(err);
	}
}

void exec_get_pin(char *param1) {
	if (strcmp(param1, "")) {
		char data[27] = "[";
		char partial[5] = "";
		unsigned char value = 0;

		for (int i = 0; i < PINS; i++) {
			if (!strcmp(param1, "I")) {
				value = inputsbuffer[i];
			} else if (!strcmp(param1, "O")) {
				value = output[i].state;
			}
			sprintf(partial, "%3i,", value);
			strcat(data, partial);
		}
		if (strcmp(data, "[") != 0) {
			data[strlen(data) - 1] = ']';
			communication.send(data);
		} else {
			communication.send(err);
		}
	} else {
		communication.send(err);
	}
}

void exec_get_counter(char *param1, char *param2) {
	if (strcmp(param1, "")) {
		char data[27] = "";

		int id = atoi(param2);
		if ((id >= 0) && (id <= 1)) {
			if (!strcmp(param1, "I")) {
				sprintf(data, "%lu,", input[id].counter);
			} else if (!strcmp(param1, "O")) {
				sprintf(data, "%lu,", output[id].counter);
			}

			if (strcmp(data, "") != 0) {
				communication.send(data);
			} else {
				communication.send(err);
			}
		} else {
			communication.send(outrange01);
		}
	} else {
		communication.send(err);
	}
}

void exec_time(char *param1) {
	if (strcmp(param1, "")) {
		const unsigned long DEFAULT_TIME = 1357041600; // Jan 1 2013
		errno = 0;
		unsigned long pctime = atol(param1);
		if (errno == ERANGE) {
			pctime = DEFAULT_TIME;
		}
		if (pctime >= DEFAULT_TIME) { // check the integer is a valid time (greater than Jan 1 2013)
			setTime(pctime); // Sync Arduino clock to the time received on the serial port
		}
		communication.send(ok);
	} else {
		communication.send(err);
	}
}

void exec_power() {
	char data[20] = "[";
	char partial[10];
	for (int i = 0; i < EMONS; i++) {
		double Irms = emon[i].calcIrms(1480);  // Calculate Irms only
		double power = Irms * 229.0;

		if (power == NAN) {
			power = -1.0;
		} else if (power <= 600.0) {
			power *= 0.95;
		}
		int module = (int) power;
		int remainder = (int) ((power - module) * 100);

		sprintf(partial, "%5u.%-2u,", module, remainder);
		strcat(data, partial);
	}
	data[strlen(data) - 1] = ']';
	communication.send(data);
}

//TODO: Save config on eeprom
void exec_config(char *type, char *param1, char *param2) {
	if (strcmp(param1, "") && strcmp(param2, "")) {
		int id = atoi(param1);
		if ((id >= 0) && (id <= 5)) {
			int value = atoi(param2);

			if (!strcmp(type, "I")) {
				input[id].mode = value;
				communication.send(ok);
			} else if (!strcmp(type, "O")) {
				output[id].mode = value;
				communication.send(ok);
			}
			communication.send(err);
		} else {
			communication.send(outrange05);
		}
	} else {
		communication.send(err);
	}
}

void execCommand() {
	#define COMMAND communication.tokens[0]
	#define COMMAND1 communication.tokens[1]
	#define COMMAND2 communication.tokens[2]

	if (!communication.read()) {
		return;
	}

	if(!strncmp(COMMAND, "SET", 3)) {
		exec_set(COMMAND + 3, COMMAND1, COMMAND2);
	} else if(!strncmp(COMMAND, "CONF", 4)) {
		exec_config(COMMAND + 4, COMMAND1, COMMAND2);
	} else if(!strcmp(COMMAND, "TOGGLE")) {
		exec_toggle(COMMAND1);
	} else if(!strncmp(COMMAND, "EMON", 4)) {
		exec_emon(COMMAND1, COMMAND2);
	} else if(!strcmp(COMMAND, "GETP")) {
		exec_get_pin(COMMAND1);
	} else if(!strcmp(COMMAND, "GETC")) {
		exec_get_counter(COMMAND1, COMMAND2);
	} else if (!strcmp(COMMAND, "TIME")) {
		exec_time(COMMAND1);
	} else if (!strcmp(COMMAND, "POWER")) {
		exec_power();
	} else if (!strcmp(COMMAND, "FREEMEM")) {
		char data[6];
		sprintf(data, "%4u", freeMemory());
		communication.send(data);
	} else {
		communication.send(err);
	}
}

void exec_init() {
	char *msg;

	switch (load_config()) {
	case 1:
		msg = (char *)firstrun;
		break;
	case 2:
		msg = (char *)crcerror;
		break;
	default:
		msg = (char *)ok;
	}
	communication.send(msg);
}
