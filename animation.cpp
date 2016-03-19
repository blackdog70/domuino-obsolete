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

Animation::Animation(Output *out, unsigned char state, unsigned char value) {
	config(out, state, value);
}

Animation::~Animation() {
	// TODO Auto-generated destructor stub
}

void Animation::config(Output *out, unsigned char state, unsigned char value) {
	Animation::out = out;
	Animation::state = state;
	Animation::value = value;
}

void Animation::setValue(byte value) {
	Animation::value = value;
	out->setValue(value);
}
