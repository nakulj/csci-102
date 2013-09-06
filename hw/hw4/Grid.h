/* 
 * File:   Grid.h
 * Author: Nakul
 *
 * Created on February 17, 2011, 4:04 PM
 */

#include <fstream>
#include <vector>

using namespace std;

#ifndef GRID_H
#define	GRID_H

class Grid {
public:
    Grid(int r, int c, int t);
    void next(int steps);
    bool compact;
    void display();
    void toggle(int, int);
    void reset();
    bool prev(int steps);
    void setSleepTime(int time);
private:
    int sleepTime;//sleepTime
    vector< vector<bool> > grid;//2d vector of booleans
    int gen;//generation number
    int R, C;//number of rows and colums
    void next();//progress one step
    int countLiveNeighbours(int, int);//calculate the number of live neighbours
    vector<string> stack;//stack to store the previous states
    string getGridState();//returns a string of ones and zeroes corresponding to the grid state
};

#endif	/* GRID_H */
