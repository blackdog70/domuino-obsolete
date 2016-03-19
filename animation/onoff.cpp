/*
 * default.cpp
 *
 *  Created on: 05/nov/2015
 *      Author: erika
 */

#include "onoff.h"

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

void OnOff::refresh() {
}
