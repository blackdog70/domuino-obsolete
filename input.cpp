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
//	prev_state = LOW;
	prev_input = LOW;
//	toggle = LOW;
//	lastDebounce = millis();
}

void Input::config(unsigned char pin, unsigned char mode, unsigned char state, unsigned char value) {
	Input::pin = BASEIN + pin;
	Input::mode = mode;
	Input::state = state;
	Input::value = value;
}

int Input::get() {
	switch (mode) {
		case DIGITAL: {
			state = debounceRead();
//			if(state == HIGH && prev_state == LOW) {
			if(state == HIGH) {
				value = !value;
			}
//			prev_state = state;
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
//			toggle = state;
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
	char state = LOW;
	char input = digitalRead(pin);

	if(input == HIGH && prev_input == LOW) { // Detect rising edge
		lastDebounce = 0;
	}
//	if(input != prev_input) {
//		lastDebounce = millis();
//	}
//	if((millis() - lastDebounce) > DEBOUNCEDELAY) {
//		if(state != input) {
//			return input;
//		}
//	}
	if(lastDebounce > DEBOUNCEDELAY && input == HIGH) {
		state = HIGH;
	}
	prev_input = input;

	return state;
}
