/* 
 * File:   Grid.h
 * Author: Nakul
 *
 * Created on February 17, 2011, 4:04 PM
 */

#include <fstream>

using namespace std;

#ifndef GRID_H
#define	GRID_H

class Grid {
public:
    Grid();
    void next(int steps);//Progress simulation
    bool compact;//Display mode
    void display();//To display the grid
    void toggle(int, int);//To switch the life status of a cell
    void reset();//Reset grid
    void save(ofstream&);//To file
    void load(ifstream&);//From file
private:
    bool grid[12][32];//State of all cells
    int gen;//Generation number
    void next();//Progress simulation by a step
    int countLiveNeighbours(int, int);//Number of live neighbours of each cell
};

#endif	/* GRID_H */
