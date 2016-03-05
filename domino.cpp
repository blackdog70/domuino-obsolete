// Do not remove the include below
#include "domino.h"

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
	config();
}

// the loop function runs over and over again forever
void loop() {
//	pstate();

	automatic->refresh();
	blink_13();

//	delay(2000);
}

void config() {
	automatic = new Automatic();
	automatic->on();
	automatic->show();
	outputs = automatic->outputs;
	inputs = automatic->inputs;
}

void pstate() {
	Serial.println("-----------");
	Serial.println("INPUTS");
	Serial.println("-----------");
	Serial.println("1 2 3 4 5 6");
	for(int i=0; i<INPUTS; i++) {
		Serial.print(inputs[i]->state);
		Serial.print(" ");
	}
	Serial.println();
}

void zero_cross() {
	dimmer_step = 0;
	Timer1.start();
}

void timer_clk() {
	if(dimmer_step<127)
		dimmer_step++;
	for(int i=0; i<OUTPUTS; i++) {
		if(outputs[i]->mode == DIMMABLE && outputs[i]->state == HIGH && dimmer_step == 127 - outputs[i]->value) {
			digitalWrite(outputs[i]->pin, HIGH);
		}
	}
	for(int i=0; i<OUTPUTS; i++) {
		if(outputs[i]->mode == DIMMABLE && dimmer_step == 127 - outputs[i]->value) {
			digitalWrite(outputs[i]->pin, LOW);
		}
	}
}

void blink_13() {
	digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
	delay(20);              // wait for a second
	digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
	delay(20);              // wait for a second
}
