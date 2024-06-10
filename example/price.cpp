using namespace std;

#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>
#include "../include/TM1650.h"
#include "../include/TimeoutException.h"
#include "../include/GpioException.h"


int main(int argc, char*argv[]){
	
	TM1650 display(23,24,7);
	
	if(display.tm1650_init()){
			try {   
				display.display((argv[1][0])-48,argv[2][0]);
				display.Terminate();
			}
			catch (const GpioException& ex) {
				cerr << "Failed to connect to TM1650 chip" << endl;
				return EXIT_FAILURE;
			}
			catch (const TimeoutException& ex) {
				cerr << "Failed to connect to TM1650 chip" << endl;
				return EXIT_FAILURE;
			}	
		
	}
	else{
		cerr<<"Failed to connect to TM1650 chip";
	}
	
return 0;
}
