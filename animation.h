/*
 * animation.h
 *
 *  Created on: 02/nov/2015
 *      Author: Sebastiano Bonisolo
 */

#ifndef ANIMATION_H_
#define ANIMATION_H_

#include "Arduino.h"
#include "output.h"

#define TOGGLE 2

class Animation {
public:
	Output* out;
	unsigned char state;   	// LOW: OFF HIGH: ON
	unsigned char value;   	// 0-255: value for dimmable lamp

	Animation();
	Animation(Output*, unsigned char, unsigned char);
	virtual ~Animation();
	void config(Output*, unsigned char, unsigned char);
	virtual void start() = 0;
	virtual void stop() = 0;
	virtual void refresh() = 0;
	void setValue(unsigned char value);

private:
};


#endif /* ANIMATION_H_ */
