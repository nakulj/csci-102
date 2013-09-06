/* 
 * File:   BadInput.cpp
 * Author: Nakul
 * 
 * Created on February 10, 2011, 3:58 PM
 */
#include <string>
#include <sstream>
#include "BadInput.h"

using namespace std;

BadInput::BadInput(int i) {
    std::stringstream out;
    out<<i;
    message= "Invalid quantity: \"";
    message+= out.str();
    message+= "\"";
}

BadInput::BadInput(char c) {
    message= "Invalid ticket type: \"";
    message+= c;
    message+= "\"";
}

string BadInput::what() {
    return message;
}
