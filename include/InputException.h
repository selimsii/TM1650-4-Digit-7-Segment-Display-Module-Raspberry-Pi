#ifndef INPUTEXCEPTION_H
#define INPUTEXCEPTION_H

#include <stdexcept>
#include <string>

class InputException : public std::invalid_argument{
public:
	explicit InputException(const std::string&message)
		:std::invalid_argument(message){}
};


inline bool checksymbols(const char&c){
switch(c){
case 'A':return true;break;	
case 'b':return true;break;	
case 'C':return true;break;	
case 'c':return true;break;	
case 'd':return true;break;	
case 'E':return true;break;	
case 'F':return true;break;	
case 'g':return true;break;	
case 'G':return true;break;	
case 'H':return true;break;	
case 'h':return true;break;	
case 'i':return true;break;	
case 'I':return true;break;	
case 'j':return true;break;	
case 'L':return true;break;	
case 'l':return true;break;
case 'n':return true;break;	
case 'N':return true;break;	
case 'O':return true;break;	
case 'o':return true;break;
case 'P':return true;break;	
case 'q':return true;break;
case 'r':return true;break;	
case 'S':return true;break;	
case 't':return true;break;	
case 'U':return true;break;	
case 'u':return true;break;	
case 'y':return true;break;
case '=':return true;break;
case '_':return true;break;
case '-':return true;break;
case '*':return true;break;
default:return false;break;
}	
}

inline void checkchar(const char& c){
		if(!isdigit(c)&&!checksymbols(c)){
			throw InputException("Input can contain numbers and specified symbols only");
		}
}

#endif


