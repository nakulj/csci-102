/* 
 * File:   creatures.h
 * Author: Nakul
 *
 * Created on April 28, 2011, 12:00 PM
 */

#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

#ifndef CREATURES_H
#define	CREATURES_H

class Creature {
public:
    int age, maxAge, starve, maxStarve, rank;
    string sym;
    Creature(){};
    Creature(const Creature& other){};
    virtual void spawn(int x, int y, int r, int c, int &newx, int &newy) =0;
    virtual void move(int x, int y, int r, int c, int &newx, int &newy) =0;
};

class Blank:public Creature {
public:
    Blank() {
        age=0;
        maxAge=-1;
        starve=0;
        maxStarve=-1;
        sym= " ";
        rank= 0;
    }
    Blank(const Blank& other){
        age= other.age;
        maxAge= other.maxAge;
        starve= other.starve;
        maxStarve= other.maxStarve;
        rank= other.rank;
        sym= other.sym;
    };
    void spawn(int x, int y, int r, int c, int &newx, int &newy) {
        newx= -1;
        newy= -1;
    }
    void move(int x, int y, int r, int c, int &newx, int &newy) {
        newx= -1;
        newy= -1;
    }
};

class Phyto:public Creature {
public:
    Phyto() {
        age=0;
        maxAge=50;
        starve=0;
        maxStarve=-1;
        sym= "-";
        rank= 1;
    }
    Phyto(const Phyto& other){
        age= other.age;
        maxAge= other.maxAge;
        starve= other.starve;
        maxStarve= other.maxStarve;
        rank= other.rank;
        sym= other.sym;
    };
    void spawn(int x, int y, int r, int c, int &newx, int &newy) {
        newx= -1;
        newy= -1;
    }
    void move(int x, int y, int r, int c, int &newx, int &newy) {
        newx= -1;
        newy= -1;
    }
};

class Zoo:public Creature {
public:
    Zoo() {
        age=0;
        maxAge=20;
        starve=0;
        maxStarve=5;
        sym= "+";
        rank= 2;
    }
    Zoo(const Zoo& other){
        age= other.age;
        maxAge= other.maxAge;
        starve= other.starve;
        maxStarve= other.maxStarve;
        rank= other.rank;
        sym= other.sym;
    };
    void spawn(int x, int y, int r, int c, int &newx, int &newy) {
        newx= -1;
        newy= -1;
        if(age==7||age==14) {
            newx=(x+1)%r;
            newy= y;
        }
    }
    void move(int x, int y, int r, int c, int &newx, int &newy) {
        srand(time(NULL));
        int dir= rand()/RAND_MAX;
        if(dir<0.5)
            newx= (x+1)%r;
        else
            newx= x-1;
        if(newx<0)
            newx+= r;

        dir= rand()/RAND_MAX;
        if(dir<0.5)
            newy= (y+1)%r;
        else
            newy= y-1;
        if(newy<0)
            newy+= c;
    }
};

class Krill:public Creature {
public:
    Krill() {
        age=0;
        maxAge= 15;
        starve=0;
        maxStarve= 4;
        sym= "X";
        rank= 3;
    }
    Krill(const Krill& other){
        age= other.age;
        maxAge= other.maxAge;
        starve= other.starve;
        maxStarve= other.maxStarve;
        rank= other.rank;
        sym= other.sym;
    };
    void spawn(int x, int y, int r, int c, int &newx, int &newy) {
        newx= -1;
        newy= -1;
        if(age==5 || age==10) {
            srand(time(NULL));
            int dir= rand()/RAND_MAX;
            if(dir<0.5)
                newx= (x+1)%r;
            else
                newx= x-1;
            if(newx<0)
                newx+= r;

            dir= rand()/RAND_MAX;
            if(dir<0.5)
                newy= (y+1)%r;
            else
                newy= y-1;
            if(newy<0)
                newy+= c;
        }
    }
    void move(int x, int y, int r, int c, int& newx, int& newy) {
        srand(time(NULL));
        int dir= rand()/RAND_MAX;
        if(dir<0.5)
            newx= (x+1)%r;
        else
            newx= x-1;
        if(newx<0)
            newx+= r;

        dir= rand()/RAND_MAX;
        if(dir<0.5)
            newy= (y+1)%r;
        else
            newy= y-1;
        if(newy<0)
            newy+= c;
    }
};

#endif	/* CREATURES_H */

