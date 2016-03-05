/*
 * raising.cpp
 *
 *  Created on: 05/nov/2015
 *      Author: erika
 */

#include <raising.h>

Raising::Raising(Output* out, byte state, byte value, unsigned long time): Animation(out, state, value) {
	start_timer = 0;
	duration = time;
}

Raising::~Raising() {
	// TODO Auto-generated destructor stub
}

void Raising::config(Output* out, byte state, byte value, unsigned long time) {
	Animation::config(out, state, value);
	duration = time;
}

void Raising::start() {
	if(out != NULL) {
		out->value = 1; // 1 to avoid blink on animation start
		out->state = HIGH;
		//		out->set();
		start_timer = millis();
	}
}

void Raising::stop() {
	if(out != NULL) {
//		out->reset();
		out->state = LOW;
	}
}

void Raising::refresh() {
	unsigned long timer = millis();

	if(timer - start_timer <= duration) {
		out->value = map(timer - start_timer, 0, duration, 0, value);
	} else {
		out->value = value;
	}
}
