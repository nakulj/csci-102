/* 
 * File:   Grid.h
 * Author: Nakul
 *
 * Created on April 28, 2011, 1:29 PM
 */

#ifndef GRID_H
#define	GRID_H

#include <vector>
#include "creatures.h"

class Grid {
public:
    Grid(int r, int c);
    void next(int steps);
    void display();
    void reset();
    void set(int x, int y, Creature* crit);
private:
    vector< vector<Creature*> > grid;
    int R, C;
    int gen;
    void next();
};

#endif	/* GRID_H */

