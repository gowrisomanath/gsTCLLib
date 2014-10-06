/*
 * gsTCLLib.h
 *
 *  Created on: Sep 20, 2014
 *      Author: Gowri Somanath
 *
 *      Library for operating the LED pixels from Total Control Lighting, using the Intel IoT Dev Kit.
 *
 *      Usage: Must sent an empty frame at the begining and ending.
 *      Each sendColor in between will affect the next LED in sequence.
 *      For example, the below will affect 3 leds where the first is set to red, second to green and 3rd to blue.
 *      gsTCLLib tcl;
 *      tcl.sendEmpty();
 *      tcl.sendColor(255,0,0);
 *      tcl.sendColor(0,255,0);
 *      tcl.sendColor(0,0,255);
 *      tcl.sendEmpty();
 *
 */

#ifndef GSTCLLIB_H_
#define GSTCLLIB_H_
#include "mraa/spi.hpp"

class gsTCLLib
{
public:
	gsTCLLib();
	~gsTCLLib();
	void sendEmpty() ;
	void sendColor(char r, char g, char b);

private:
	mraa::Spi *spi;
};


#endif /* GSTCLLIB_H_ */
