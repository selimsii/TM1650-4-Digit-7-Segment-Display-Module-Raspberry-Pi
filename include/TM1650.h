#pragma once
#include <pigpio.h>
#include <unistd.h>
#include <stdexcept>
#include <iostream>
#include <string>
#include "InputException.h"

#ifndef TM1650_H
#define TM650_H 
#define TM1650_CMD_MODE 0x48
#define TM1650_8_SEGMENT 0x00
#define TM1650_ADDR_SET_CMD 0xC0

#define TM1650_BR_MSK 0x70
#define TM1650_BR0 0x10
#define TM1650_BR1 0x20
#define TM1650_BR2 0x30
#define TM1650_BR3 0x40
#define TM1650_BR4 0x50
#define TM1650_BR5 0x60
#define TM1650_BR60x70

#define TM1650_SEGMENT_MSK 0x40

#define	TM_DSP_ON 0x01
#define TM_DSP_OFF 0x00

#define _bitDelay 10


constexpr int DIG_ADDR[]= {0x68,0x6a,0x6c,0x6e};

constexpr int DIGITS[] {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

class TM1650{
	public:
	TM1650(uint8_t,uint8_t,uint8_t);
	
	void display();
	void clear();
	void Terminate();
	void display(unsigned int,const char&);
	void setBrightness(uint8_t);
	bool tm1650_init();
	
	private:
	void bitDelay();
	void start();
	void stop();
	void writeByte(uint8_t);
	void writeByteData(uint8_t,uint8_t);
	void checkinput(unsigned int,const char&);
	
	float _fractionvalue;
	void myThrow(std::string);
	uint8_t char_select(const char&);
	
	
	uint8_t DT;
	uint8_t CLK;
	uint8_t brightness;
};

#endif
