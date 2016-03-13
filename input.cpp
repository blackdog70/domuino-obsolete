/*
 * inputs.cpp
 *
 *  Created on: 02/nov/2015
 *      Author: Sebastiano Bonisolo
 */

#include "input.h"

Input::Input() {
	pin = 0;
	mode = DIGITAL;
	state = LOW;
	value = 0;
	prev_state = LOW;
	prev_input = LOW;
	toggle = LOW;
	lastDebounce = millis();
	debounceDelay = 50; //ms
}

void Input::config(unsigned char pin, unsigned char mode, unsigned char state, unsigned char value) {
	Input::pin = pin;
	Input::mode = mode;
	Input::state = state;
	Input::value = value;
}

int Input::get() {
	switch (mode) {
		case DIGITAL: {
			state = debounceRead();
			if(state == HIGH && prev_state == LOW) { // Detect rising edge
				value = !value;
			}
			prev_state = state;
			break;
		}
		case ANALOG: {
			int new_value = analogRead(pin);
			if(value!=new_value) {
				state = HIGH;
				value = new_value;
			} else {
				state = LOW;
			}
			toggle = state;
			break;
		}
	}
	return value;
}

/*
 * Read input debounced.
 * \param value: byte with previous input value
 * \param pin: byte with pin address for the new reading
 * \return byte debounced input value
 */
char Input::debounceRead() {
	char input = digitalRead(pin);

	if(input != prev_input) {
		lastDebounce = millis();
	}
	if((millis() - lastDebounce) > debounceDelay) {
		if(state != input) {
			return input;
		}
	}
	prev_input = input;

	return state;
}
