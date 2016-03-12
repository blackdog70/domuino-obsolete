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

#define DIGITAL 0
#define ANALOG 1

class Input {
public:
	unsigned char pin;
	unsigned char mode;    	// 0: on/off 1: dimmable
	unsigned char state;   	// LOW: OFF HIGH: ON
	unsigned char value;   	// 0-255: value for dimmable lamp
	Output* output;

	Input();
	void config(unsigned char pin, unsigned char mode, unsigned char state, unsigned char value, Output* output);
	void get();
	void refresh();

private:
	unsigned long lastDebounce;
	unsigned long debounceDelay; // ms

	unsigned char prev_state;
	unsigned char prev_input;
	unsigned char toggle;
	char debounceRead();
};



#endif /* INPUT_H_ */
