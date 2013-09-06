/* 
 * File:   Game.h
 * Author: Nakul
 *
 * Created on January 29, 2011, 1:05 PM
 */

#include <fstream>

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
    int id;
    static int nextId;
public:
    Game() {
        id= nextId++;
    }
    int setName(string);
    int setPublisher(string);
    int setCategory(string);
    int setRating(string);
    int setDate(int, int, int);
    int setPlatform(string);
    int setPrice(double);
    //setters
    string getName();
    int getId();
    //getters
    void print();
    string toFile(ofstream&);
    bool operator==(const Game&);
};

#endif	/* GAME_H */
