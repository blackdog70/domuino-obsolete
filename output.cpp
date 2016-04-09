/*
 * outputs.cpp
 *
 *  Created on: 02/nov/2015
 *      Author: Sebastiano Bonisolo
 */

#include "output.h"

Output::Output() {
	Output::pin = 0;
	Output::mode = DIGITAL;
	Output::state = LOW;
	Output::value = 0;
}

void Output::config(unsigned char pin, unsigned char mode, unsigned char value) {
	Output::pin = BASEOUT + pin;
	Output::mode = mode;
	Output::value = value;
}

void Output::toggle() {
	state = 1 - state;
	digitalWrite(pin, state);
}

void Output::set() {
	state = HIGH;
	digitalWrite(pin, state);
}

void Output::reset() {
	state = LOW;
	digitalWrite(pin, state);
}

void Output::setValue(char value) {
	Output::value = value;
}
