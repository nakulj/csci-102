/* 
 * File:   BadInput.h
 * Author: Nakul
 *
 * Created on February 10, 2011, 3:58 PM
 */

#include <iostream>
#include <string>

using namespace std;

#ifndef BADINPUT_H
#define	BADINPUT_H

class BadInput {
private:
    string message;
public:
    BadInput(int);
    BadInput(char);
    string what();
};

#endif	/* BADINPUT_H */

