// Do not remove the include below
#include "domuino.h"

Communication communication(password);
EnergyMonitor emon[EMONS];
Scenery scenery[MAXSCENERIES];
Output output[PINS];
Input input[PINS];

char password[BLOCK_SIZE+1];
char domuino_id;

int zero = 2;
int dimming = 10;
int timer_freq = 70; // 10.000 us / 127 bit = 78
int dimmer_step = 0;

const char firstrun[] = "\"First run\"\0";
//#define FIRSTRUN strcpy_P( buffer, pgm_read_word( &(firstrun) ) );

const char err[] = "ERR\0";
const char ok[] = "OK\0";

//const char crcerror[] = "\"CRC\"\0";
//const char outrange01[] = "\"0..1\"\0";
//const char outrange06[] = "\"0..6\"\0";
//const char outrange0255[] = "\"0..255\"\0";

const char crcerror[] = "";
const char outrange01[] = "";
const char outrange06[] = "";
const char outrange0255[] = "";

// the setup function runs once when you press reset or power the board
void setup() {
	char *msg;

	Serial.setTimeout(100);
	Serial.begin(115200);
	pinMode(zero, INPUT);
	pinMode(13, OUTPUT);
	attachInterrupt(digitalPinToInterrupt(zero), zero_cross, RISING);
	Timer1.initialize(timer_freq);
	Timer1.stop();
	Timer1.attachInterrupt(timer_clk);
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
	automatic_on();
	communication.send("INIT", ok, msg);
}

// the loop function runs over and over again forever
void loop() {
	blink_13();
	execCommand();
//	delay(2000);
}

void zero_cross() {
	dimmer_step = 0;
	Timer1.start();
}

void timer_clk() {
	if(dimmer_step<127)
		dimmer_step++;
	for(int i=0; i<PINS; i++) {
		if(output[i].mode == DIMMABLE && output[i].state == HIGH && dimmer_step == 127 - output[i].value) {
			digitalWrite(output[i].pin, HIGH);
		}
	}
	for(int i=0; i<PINS; i++) {
		if(output[i].mode == DIMMABLE && dimmer_step == 127 - output[i].value) {
			digitalWrite(output[i].pin, LOW);
		}
	}
}

void blink_13() {
	digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
	delay(20);              // wait for a second
	digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
	delay(20);              // wait for a second
}

void execCommand() {
	#define COMMAND communication.tokens[0]
	#define COMMAND1 communication.tokens[1]
	#define COMMAND2 communication.tokens[2]

	if (!communication.read()) {
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
						output[id].reset();
						break;
					case 1:
						output[id].set();
						break;
					}
					if(value >=0 and value <= 1) {
						communication.send(COMMAND, ok, "");
					} else {
						communication.send(COMMAND, err, outrange01);
					}
				} else if (!strcmp(COMMAND+3, "V")) {
					int value = atoi(COMMAND2);
					if((value >= 0) && (value <= 255)) {
						output[id].value = value;
						communication.send(COMMAND, ok, "");
					} else {
						communication.send(COMMAND, err, outrange0255);
					}
				} else {
					communication.send(COMMAND, err, "");
				}
			} else {
				communication.send(COMMAND, err, outrange06);
			}
		} else {
			communication.send(COMMAND, err, "");
		}
	} else if(!strncmp(COMMAND, "EMON", 4)) {
		if(strcmp(COMMAND1, "") && strcmp(COMMAND2, "")) {
			int id = atoi(COMMAND1);
			if((id >= 0) && (id <= 1)) {
				if(!strcmp(COMMAND+4, "C")) {
					int value = atof(COMMAND2);

					emon[id].current((unsigned int) A6+id, (float)value / 100.0);
					communication.send(COMMAND, ok, "");
				} else {
					communication.send(COMMAND, err, "");
				}
			} else {
				communication.send(COMMAND, err, outrange01);
			}
		} else {
			communication.send(COMMAND, err, "");
		}
	} else if(!strncmp(COMMAND, "GET", 3)) {
		if(strcmp(COMMAND1, "")) {
			char data[26] = "[";
			char partial[3] = "";
			unsigned char value = 0;

			for(int i=0; i<PINS; i++) {
				if(!strcmp(COMMAND+3, "P")) {			//GETP
					if(!strcmp(COMMAND1, "I")) {
						value = input[i].state;
					} else if (!strcmp(COMMAND1, "O")) {
						value = output[i].state;
					}
				} else if (!strcmp(COMMAND+3, "V")) {	//GETV
					if(!strcmp(COMMAND1, "I")) {
						value = input[i].value;
					} else if (!strcmp(COMMAND1, "O")) {
						value = output[i].value;
					}
				} else {
					break;
				}
				sprintf(partial, "%3i,", value);
				strcat(data, partial);
			}
			if(strcmp(data, "[") != 0) {
				data[strlen(data)-1] = ']';
				communication.send(COMMAND, ok, data);
			} else {
				communication.send(COMMAND, err, "");
			}
		} else {
			communication.send(COMMAND, err, "");
		}
	} else if(!strncmp(COMMAND, "SC", 2)) {
		if(strcmp(COMMAND1, "")) {
			int id = atoi(COMMAND1);
			if((id >= 0) && (id <= 6)) {
				if(!strcmp(COMMAND+2, "ON")) {
					scenery[id].start();
					communication.send(COMMAND, ok, "");
				} else if(!strcmp(COMMAND+2, "OFF")) {
					scenery[id].stop();
					communication.send(COMMAND, ok, "");
				} else {
					communication.send(COMMAND, err, "");
				}
			} else {
				communication.send(COMMAND, err, outrange06);
			}
		} else {
			communication.send(COMMAND, err, "");
		}
	}  else if (!strcmp(COMMAND, "TIME")) {
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
			communication.send(COMMAND, ok, "");
		} else {
			communication.send(COMMAND, err, "");
		}
	} else if (!strcmp(COMMAND, "POWER")) {
		char data[20] = "[";
		char partial[10];

		for (int i=0; i<EMONS; i++) {
			double Irms = emon[i].calcIrms(1480);  // Calculate Irms only
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
		communication.send(COMMAND, ok, data);
	} else if (!strcmp(COMMAND, "FREEMEM")) {
		char data[6];
		sprintf(data, "%4u", freeMemory());
		communication.send(COMMAND, ok, data);
	} else {
		communication.send(COMMAND, err, "");
	}
}

void automatic_on() {
	for(int i=0; i<PINS; i++) {
		pinMode(output[i].pin, OUTPUT);
		pinMode(input[i].pin, INPUT);
	}
	pinMode(10, OUTPUT);    // CPU pin
	digitalWrite(10, HIGH); // Set CPU pin ON
}
