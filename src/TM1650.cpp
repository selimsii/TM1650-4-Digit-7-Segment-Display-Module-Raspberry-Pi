#include "../include/TM1650.h"


using namespace std;


TM1650::TM1650(uint8_t DT,uint8_t CLK,uint8_t brightness){	
this->DT=DT;
this->CLK=CLK;
this->brightness=brightness;
if(tm1650_init())setBrightness(this->brightness);
}


void TM1650::writeByte(uint8_t data){

	for (int i = 0; i < 8; i++) {
		gpioWrite(CLK, 0);
		bitDelay();
        gpioWrite(DT, (data & 0x80) ? 1:0);
        data<<=1;
        gpioWrite(CLK, 1);
        bitDelay();
    }

    // Wait for ACK
    gpioWrite(CLK,0);
    gpioSetMode(DT,PI_INPUT);
    bitDelay();
    
    gpioWrite(CLK,1);
    bitDelay();
    uint8_t ack=gpioRead(DT);
    if(ack==0)gpioSetMode(DT,PI_OUTPUT);
	bitDelay();
}



void TM1650::writeByteData(uint8_t cmd1,uint8_t cmd2){	
start();
writeByte(cmd1);
writeByte(cmd2);
stop();
}

void TM1650::clear(){
	
	for(int i=0;i<4;i++){
		writeByteData(2*i+0x68,0);
	}
	
}


void TM1650::bitDelay(){	
usleep(_bitDelay);
}

void TM1650::stop(){
	
///////////////DATA STOP
gpioWrite(CLK,0);
bitDelay();
gpioWrite(DT,0);
bitDelay();
gpioWrite(CLK,1);
bitDelay();
gpioWrite(DT,1);
bitDelay();
}

void TM1650::start(){
	
///////////////DATA START
gpioWrite(CLK,1);
bitDelay();
gpioWrite(DT,1);
bitDelay();
gpioWrite(DT,0);
bitDelay();
gpioWrite(CLK,0);
bitDelay();
}

void TM1650::display(unsigned int pos,const char& symbol){
	checkinput(pos,symbol);
	writeByteData(0x68+2*(pos-1),isdigit(symbol)?DIGITS[symbol-48]:char_select(symbol));
}

void TM1650::checkinput(unsigned int pos,const char& numeral){
try {
		checkchar(numeral);
		switch(pos){
		case 1:break;
		case 2:break;
		case 3:break;
		case 4:break;
		default:myThrow("Display position is out of index");break;	
		}
	}catch(const InputException&e) {
		std::cerr<<numeral<<" is invalid input type:"<<e.what()<<std::endl;
	}	
}

uint8_t TM1650::char_select(const char&c){
switch(c){
case 'A':return 0x77;break;	
case 'b':return 0x7C;break;	
case 'C':return 0x39;break;	
case 'c':return 0x58;break;	
case 'd':return 0x5E;break;	
case 'E':return 0x79;break;	
case 'F':return 0x71;break;	
case 'g':return 0x6F;break;	
case 'G':return 0x3D;break;	
case 'H':return 0x76;break;	
case 'h':return 0x74;break;	
case 'i':return 0x05;break;	
case 'I':return 0x06;break;	
case 'j':return 0x0D;break;	
case 'L':return 0x38;break;	
case 'l':return 0x30;break;
case 'n':return 0x54;break;	
case 'N':return 0x37;break;	
case 'O':return 0x3F;break;	
case 'o':return 0x5C;break;
case 'P':return 0x73;break;	
case 'q':return 0x67;break;
case 'r':return 0x50;break;	
case 'S':return 0x6D;break;	
case 't':return 0x78;break;	
case 'U':return 0x3E;break;	
case 'u':return 0x1C;break;	
case 'y':return 0x6E;break;
case '=':return 0x48;break;
case '_':return 0x08;break;
case '-':return 0x40;break;
case '*':return 0x63;break;
default:return false;break;
}
}

void TM1650::myThrow(string message){
throw std::invalid_argument(message);	
}

void TM1650::setBrightness(uint8_t brightness){
this->brightness=(brightness&0x07);
writeByteData(TM1650_CMD_MODE,TM1650_8_SEGMENT|TM_DSP_ON|this->brightness);
}

bool TM1650::tm1650_init(){
if(gpioInitialise()<0){
	return 0;
}
gpioSetMode(CLK,PI_OUTPUT);
gpioSetMode(DT,PI_OUTPUT);
gpioWrite(CLK,0);
gpioWrite(DT,0);
return 1; 
}

void TM1650::Terminate(){
gpioTerminate();
}

bool isMinus(string str){
	return (str.find("-")!=string::npos)|(str.find("-")!=string::npos);
}
