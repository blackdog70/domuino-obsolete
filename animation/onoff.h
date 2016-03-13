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
	OnOff();
	virtual ~OnOff();

	virtual void start();
	virtual void stop();
};

#endif /* ONOFF_H_ */
