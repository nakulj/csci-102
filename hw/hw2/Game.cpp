#include <iostream>
#include <iomanip>
#include <string>
#include "Game.h"

using namespace std;

string Game::getName() {
    return name;
}

int Game::getId() {
    return id;
}

int Game::setCategory(string category) {
    string cats[]={
        "Action", "Education","Fighting", "Music/Party",
        "Puzzle/Cards", "Roleplaying", "Shooter",
        "Simulation", "Sports", "Strategy", "Other"};//Categories
    for(int i=0; i<11; i++) {
        if(cats[i] == category) {
            cat= category;
            return(0);
        }//If category found, stop
    }//Only reaches this point if not found
    return -1;
}

int Game::setDate(int dd, int mm, int yy) {
    if(mm<1||mm>12||yy<1970||yy>9999)
        return -1;//month and year should be in range
    int days[]={31,(yy%4==0?(yy%100==0?(yy%400==0?29:28):29):28),31,30,31,30,31,31,30,31,30,31};
    //array containing number of days in a month, unary operator used to calculate number of days in February
    if(dd<0||dd>days[mm-1])
        return -1;//day should be in range
    //only reaches this point if date is valid
    d=dd;
    m=mm;
    y=yy;
    return 0;
}

int Game::setName(string n) {
    string temp= n;
    while(temp[0]==' '||temp[0]=='\t')
        temp.erase(temp.begin());//trimming leading spaces
    while(temp[temp.length()-1]==' '||temp[temp.length()-1]=='\t')
        temp.erase(temp.begin()+temp.length()-1);//trimming trailing spaces
    if(temp=="")
        return -1;
    name=n;
    return 0;
}

int Game::setPlatform(string platf) {
    string platfs[]= {"Xbox-360", "PS3", "DS", "Wii"};
    for(int i=0;i<4; i++) {
        if(platfs[i]==platf) {
            platform= platf;
            return 0;
        }//If platform is valid, set and return
    }//Only reaches this point if platform is invalid
    return -1;
}

int Game::setPrice(double p) {
    if(p<0)
        return -1;
    price= p;
    return 0;
}

int Game::setPublisher(string pub) {
    string temp= pub;
    while(temp[0]==' '||temp[0]=='\t')
        temp.erase(temp.begin());//trimming leading spaces
    while(temp[temp.length()-1]==' '||temp[temp.length()-1]=='\t')
        temp.erase(temp.begin()+temp.length()-1);//trimming trailing spaces
    if(temp=="")
        return -1;
    publisher= pub;
    return 0;
}

int Game::setRating(string rate) {
    string rates[]={"EC","E","E10+","T","M","AO","RP","PG","PG13","R","NC17"};
    for(int i=0; i<11; i++) {
        if(rates[i]==rate) {
            rating= rate;
            return 0;
        }//Find the rating in the index to check validity
    }//Only reaches this point if rating is invalid
    return -1;
}

void Game::print() {
    cout<<
            left<<setw(30)<<name<<'\t'<<
            left<<setw(8)<<platform<<'\t'<<
            left<<setw(10)<<cat<<'\t'<<
            left<<setw(20)<<publisher<<'\t'<<
            left<<setw(5)<<rating<<'\t'<<
            (m<10?"0":"")<<m<<"/"<<
            (d<10?"0":"")<<d<<"/"<<
            y<<'\t'<<
            setprecision(4)<<price<<
            endl;//print details
}

bool Game::operator ==(const Game &other) {
    if(name != other.name)
        return false;
    if(platform != other.platform)
        return false;
    if(publisher != other.publisher)
        return false;
    return true;
}

string Game::toFile(ofstream &file) {
    file<<
            name<<endl<<
            publisher<<endl<<
            cat<<endl<<
            rating<<endl<<
            platform<<endl<<
            d<<'\\'<<m<<'\\'<<y<<endl<<
            price<<endl<<
            id<<endl;
}

int Game::nextId= 0;
