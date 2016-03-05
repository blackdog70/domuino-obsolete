/*
 * outputs.h
 *
 *  Created on: 02/nov/2015
 *      Author: Sebastiano Bonisolo
 */

#ifndef OUTPUT_H_
#define OUTPUT_H_

#include "Arduino.h"

#define OUTPUTS 6

#define DIGITAL 0
#define DIMMABLE 1

class Output {
public:
	char pin;
	char mode;    	// 0: on/off 1: dimmable
	char state;   	// LOW: OFF HIGH: ON
	char value;   	// 0-255: value for dimmable lamp

	Output();
	void config(char pin, char mode, char state, char value);
	void set();
	void reset();
	void setValue(char value);

private:
};


#endif /* OUTPUT_H_ */
