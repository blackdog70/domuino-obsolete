// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef _domuino_H_
#define _domuino_H_
#include "Arduino.h"
//add your includes for the project domino here

#include "automatic.h"
#include "TimerOne.h"

//end of add your includes here
#ifdef __cplusplus
extern "C" {
#endif
void loop();
void setup();
#ifdef __cplusplus
} // extern "C"
#endif

//add your function definitions for the project domino here

//TODO: check necessary double pointer or it can be simplified
Automatic* automatic;
Output** outputs;
Input** inputs;

void config();
void start();
void timer_clk();
void dimmer_test();
void zero_cross();
void blink_13();
void pstate();

//Do not add code below this line
#endif /* _domino_H_ */
