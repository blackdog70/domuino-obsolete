/*
 * default.h
 *
 *  Created on: 05/nov/2015
 *      Author: Sebastiano Bonisolo
 */

#ifndef ONOFF_H_
#define ONOFF_H_

#include "../animation.h"

class OnOff: public Animation {
public:
	OnOff() : Animation() {};
	OnOff(Output* out, byte state, byte value) : Animation(out, state, value) {};
//	virtual ~OnOff();

	void start();
	void stop();
	void refresh();
};

#endif /* ONOFF_H_ */
