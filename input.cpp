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
	prev_input = 0;
	lastDebounce = 0;
	counter = 0;
}

void Input::config(unsigned char pin, unsigned char mode) {
	Input::pin = BASEIN + pin;
	Input::mode = mode;
}

int Input::get() {
	int value;

	switch (mode) {
		case DIGITAL: {
			int previous = value;
			value = debounceRead();
			if (previous == LOW && value == HIGH) {
				counter++;
			}
			break;
		}
		case ANALOG: {
			value = analogRead(pin);
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
