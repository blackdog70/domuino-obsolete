/*
 * inputs.h
 *
 *  Created on: 02/nov/2015
 *      Author: Sebastiano Bonisolo
 */

#ifndef INPUT_H_
#define INPUT_H_

#include "Arduino.h"
#include "output.h"

#define INPUTS 6
#define DIGITAL 0
#define ANALOG 1

class Input {
public:
	char pin;
	char mode;    	// 0: on/off 1: dimmable
	char state;   	// LOW: OFF HIGH: ON
	char value;   	// 0-255: value for dimmable lamp
	Output* output;

	Input();
	void config(char pin, char mode, char state, char value, Output* output);
	void get();
	void refresh();

private:
	unsigned long lastDebounce;
	unsigned long debounceDelay; // ms

	char prev_state;
	char prev_input;
	char toggle;
	char debounceRead();
};



#endif /* INPUT_H_ */
