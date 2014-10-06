/*
 * gsTCLLib.cpp
 *
 *  Created on: Sep 20, 2014
 *      Author: Gowri Somanath (http://thepositronicbrain.blogspot.com/)
 *
 *      Library for operating the LED pixels from Total Control Lighting, using the Intel IoT Dev Kit.
 *      *      Usage: Must sent an empty frame at the begining and ending.
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


#include "gsTCLLib.h"

gsTCLLib::gsTCLLib()
{
	spi = new mraa::Spi(1);
}

gsTCLLib::~gsTCLLib()
{
delete spi;
}

void gsTCLLib::sendEmpty() {
	spi->write(0x00);
	spi->write(0x00);
	spi->write(0x00);
	spi->write(0x00);
}

void gsTCLLib::sendColor(char r, char g, char b) {
	char flag = 0;
	flag = (r & 0xC0) >> 6;
	flag |= ((g & 0xC0) >> 4);
	flag |= ((b & 0xC0) >> 2);
	flag = ~flag;
	spi->write(flag);
	spi->write(b);
	spi->write(g);
	spi->write(r);
}



