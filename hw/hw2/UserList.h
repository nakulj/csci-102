/* 
 * File:   UserList.h
 * Author: Nakul
 *
 * Created on February 12, 2011, 4:11 PM
 */

#include <vector>
#include <string>
#include "Game.h"
using namespace std;

#ifndef USERLIST_H
#define	USERLIST_H

class UserList {
public:
    UserList(string);
    int add(int);
    int rem(int);
    void del(int);
    void print(vector<Game>&);
    string getName();
    bool empty();
    void toFile(ofstream&);
private:
    vector<int> ids;
    string name;
};

#endif	/* USERLIST_H */

