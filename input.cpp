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
	output = NULL;
	prev_state = LOW;
	prev_input = LOW;
	toggle = LOW;
	lastDebounce = millis();
	debounceDelay = 50; //ms
}

void Input::config(unsigned char pin, unsigned char mode, unsigned char state, unsigned char value, Output* output) {
	Input::pin = pin;
	Input::mode = mode;
	Input::state = state;
	Input::value = value;
	Input::output = output;
}

/*
 * Read all inputs and save state.
 * The state can be ON or OFF, the input is debounced.
 * The input can be digital or analog.
 * With analog input the state change to ON every time the value is changed, then value is saved.
 */
void Input::get() {
	switch (mode) {
		case DIGITAL: {
//			state = debounceRead();
			if(state == HIGH && prev_state == LOW) { // Detect rising edge
				toggle = !toggle;
				if(toggle == HIGH) {
					output->set();
				} else {
					output->reset();
				}
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
		default:
			break;
	}
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

void Input::refresh() {
	get();
}
