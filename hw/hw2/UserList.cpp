/* 
 * File:   UserList.cpp
 * Author: Nakul
 * 
 * Created on February 12, 2011, 4:11 PM
 */

#include <iostream>
#include <iomanip>
#include "UserList.h"

using namespace std;

UserList::UserList(string name) {
    this->name= name;
}

int UserList::add(int id) {
    for(int i= 0; i<ids.size(); i++) {
        if(id == ids[i])
            return -1;
    }
    ids.push_back(id);
    return 0;
}

int UserList::rem(int id) {
    for(int i= 0; i<ids.size(); i++) {
        if(id == ids[i]) {
            ids.erase(ids.begin() + i);
            return 0;
        }
    }
    return -1;
}

string UserList::getName() {
    return name;
}

void UserList::print(vector<Game> &games) {
    if(ids.empty()) {
        cout<<name<<" is empy"<<endl;
        return;
    }
    cout<<name<<":"<<endl;
    cout<<
            left<<setw(30)<<"Name"<<'\t'<<
            left<<setw(6)<<"Platform"<<'\t'<<
            left<<setw(10)<<"Category"<<'\t'<<
            left<<setw(20)<<"Publisher"<<'\t'<<
            left<<setw(5)<<"Rating"<<'\t'<<
            left<<setw(10)<<"Date"<<'\t'<<
            left<<"Price"<<
            endl;//1st row of table
    for(int i= 0; i<ids.size(); i++) {
        for(int j= 0; j<games.size(); j++) {
            if(games[j].getId() == ids[i]) {
                games[j].print();
                break;
            }
        }
    }
}

void UserList::del(int id) {
    for(int i= 0; i<ids.size(); i++) {
        if(ids[i] == id) {
            ids.erase(ids.begin() + i);
            return;
        }
    }
}

bool UserList::empty() {
    return ids.empty();
}

void UserList::toFile(ofstream &file) {
    cout<<name<<endl;
    file<<name<<':';
    for(int i=0; i<ids.size(); i++) {
        file<<' '<<ids[i];
    }
    file<<endl;
}
