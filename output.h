/*
 * outputs.h
 *
 *  Created on: 02/nov/2015
 *      Author: Sebastiano Bonisolo
 */

#ifndef OUTPUT_H_
#define OUTPUT_H_

#include "Arduino.h"

#define DIGITAL 0
#define DIMMABLE 1

class Output {
public:
	unsigned char pin;
	unsigned char mode;    			// 0: on/off 1: dimmable
	unsigned char state;   	// LOW: OFF HIGH: ON
	unsigned char value;   			// 0-255: value for dimmable lamp

	Output();
	void config(unsigned char pin, unsigned char mode, unsigned char state, unsigned char value);
	void set();
	void reset();
	void setValue(char value);

private:
};


#endif /* OUTPUT_H_ */
