/* 
 * File:   Game.h
 * Author: Nakul
 *
 * Created on January 29, 2011, 1:05 PM
 */

using namespace std;

#ifndef GAME_H
#define	GAME_H

class Game {
private:
    string name,
           publisher,
           cat,
           rating,
           platform;
    int d, m, y;
    double price;
public:
    int setName(string);
    int setPublisher(string);
    int setCategory(string);
    int setRating(string);
    int setDate(int, int, int);
    int setPlatform(string);
    int setPrice(double);
    //setters
    string getName();
    //getter
    void print();
};

#endif	/* GAME_H */

