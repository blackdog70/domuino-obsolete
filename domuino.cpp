// Do not remove the include below
#include "domuino.h"

EnergyMonitor emon[EMONS];
Scenery scenery[MAXSCENERIES];
Output output[PINS];
Input input[PINS];
char inputsbuffer[PINS];

char password[BLOCK_SIZE+1];
char domuino_id;

int zero = 2;
int dimming = 10;
int timer_freq = 70; // 10.000 us / 127 bit = 78
int dimmer_step = 0;

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.setTimeout(100);
	Serial.begin(115200);
	pinMode(zero, INPUT);
	pinMode(13, OUTPUT);
	attachInterrupt(digitalPinToInterrupt(zero), zero_cross, RISING);
	Timer1.initialize(timer_freq);
	Timer1.stop();
	Timer1.attachInterrupt(timer_clk);
	exec_init();
	automatic_on();
}

// the loop function runs over and over again forever
void loop() {
	blink_13();
//TODO: Reset inputsbuffer after a while
	for(int i=0; i<PINS; i++) {
		int value = input[i].get();
		if (value > 0) {
			inputsbuffer[i] = value;
		}
	}
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

void automatic_on() {
	for(int i=0; i<PINS; i++) {
		pinMode(output[i].pin, OUTPUT);
		pinMode(input[i].pin, INPUT);
	}
	pinMode(10, OUTPUT);    // CPU pin
	digitalWrite(10, HIGH); // Set CPU pin ON
}
