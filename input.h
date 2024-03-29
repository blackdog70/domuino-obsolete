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

#define BASEIN 14
#define DIGITAL 0
#define ANALOG 1
#define DEBOUNCEDELAY 50 //ms

class Input {
public:
	unsigned char pin;
	unsigned char mode;    	// 0: on/off 1: dimmable
	unsigned long counter;  // Count number of raising

	/*
	 * Read all inputs and save state.
	 * The state can be ON or OFF, the input is debounced.
	 * The input can be digital or analog.
	 * With analog input the state change to ON every time the value is changed, then value is saved.
	 */
	Input();
	void config(unsigned char, unsigned char);
	int get();

private:
	unsigned char lastDebounce;
	unsigned char prev_input;
	char debounceRead();
};



#endif /* INPUT_H_ */
