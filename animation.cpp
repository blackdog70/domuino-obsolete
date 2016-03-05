/*
 * animation.cpp
 *
 *  Created on: 02/nov/2015
 *      Author: Sebastiano Bonisolo
 */

#include "animation.h"

Animation::Animation() {
	out = NULL;
	state = LOW;
	value = 0;
}

Animation::Animation(Output *out, byte state, byte value) {
	config(out, state, value);
}

Animation::~Animation() {
	// TODO Auto-generated destructor stub
}

void Animation::config(Output *out, byte state, byte value) {
	Animation::out = out;
	Animation::state = state;
	Animation::value = value;
}

void Animation::setValue(byte value) {
	Serial.print("Set out ");
	Serial.print(out->pin);
	Serial.print(" value ");
	Serial.println(value);
	Animation::value = value;
	out->setValue(value);
}
