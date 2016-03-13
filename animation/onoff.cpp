/*
 * default.cpp
 *
 *  Created on: 05/nov/2015
 *      Author: erika
 */

#include "onoff.h"

OnOff::OnOff(): Animation() {
		// TODO Auto-generated constructor stub
}

OnOff::~OnOff() {
	// TODO Auto-generated destructor stub
}

void OnOff::start() {
	if(out != NULL) {
		out->value = value;
		out->set();
	}
}

void OnOff::stop() {
	if(out != NULL) {
		out->reset();
	}
}
