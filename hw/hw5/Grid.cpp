/* 
 * File:   Grid.cpp
 * Author: Nakul
 * 
 * Created on April 28, 2011, 1:29 PM
 */

#include "Grid.h"
#include "creatures.h"
#include <iostream>

using namespace std;

Grid::Grid(int r, int c) {
    gen= 0;
    R= r;
    C= c;
    for(int i=0; i<R; i++) {
        grid.push_back(vector<Creature*>(C));
        for(int j=0; j<C; j++)
            grid[i][j]= new Blank();
    }
}//Initialize

void Grid::reset() {
    gen= 0;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            delete grid[i][j];
            grid[i][j]= new Blank();
        }
    }
}//Reset

void Grid::display() {
    string border= "+";
    for(int i= 0; i<C; i++) {
        border+= "-";
    }
    border+="+";
    cout<<"Generation: "<<gen<<endl;
    cout<<border<<endl;
    for(int i=0; i<R; i++) {
        cout<<"|";
        for(int j=0; j<C; j++)
            cout<<(grid[i][j]->sym);
        cout<<"|"<<endl;
    }
    cout<<border<<endl<<endl;
}//Print

void Grid::set(int x, int y, Creature* crit) {
    delete grid[x][y];
    grid[x][y]= crit;
    for(int i= 0; i<R; i++) {
        for(int j= 0; j<C; j++) {
            grid[i][j]->age= 0;
            grid[i][j]->starve= 0;
        }
    }
}//Add a creature

void Grid::next(int steps) {
    for(int i=1; i<=steps; i++) {
        next();//progress one step
        display();//print out the grid
        usleep(500000);//pause
    }
}//Loop

void Grid::next() {
    gen++;

    vector< vector<Creature*> > nextGrid;
    for(int i=0; i<R; i++) {
        nextGrid.push_back(vector<Creature*>(C));
        for(int j=0; j<C; j++) {
            if(grid[i][j]->rank == 0)
                nextGrid[i][j]= new Blank();
            else if(grid[i][j]->rank == 1)
                nextGrid[i][j]= new Phyto();
            else if(grid[i][j]->rank == 2)
                nextGrid[i][j]= new Zoo();
            else if(grid[i][j]->rank == 3)
                nextGrid[i][j]= new Krill();
            nextGrid[i][j]->age= (grid[i][j]->age);
            nextGrid[i][j]->starve= (grid[i][j]->starve);
        }
    }
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {

            if(grid[i][j]->rank == 0 && grid[i][j]->age== 4) {
                delete nextGrid[i][j];
                nextGrid[i][j]= new Phyto();
                continue;
            }//If a space is blank for four generations, add a Phytoplanktonand continue

            if((grid[i][j]->age == grid[i][j]->maxAge) || (grid[i][j]->starve == grid[i][j]->maxStarve)) {
                delete nextGrid[i][j];
                nextGrid[i][j]= new Blank();
                continue;
            }//If a creature dies due to age or starvation, replace it with a blank and continue.

            if(grid[i][j]->rank <2) {
                nextGrid[i][j]->age++;
                nextGrid[i][j]->starve++;
                continue;
            }//Blank cells and Phytoplankton can't move or reproduce, so increment their age and continue

            //Code to handle motion

            int newx, newy;
            grid[i][j]->move(i, j, R, C, newx, newy);
            Creature *move;
            if(grid[i][j]->rank == 2)
                move= new Zoo();
            else
                move= new Krill();
            //Only Zooplankton and Krill can move
            move->age= grid[i][j]->age;
            move->starve= grid[i][j]->starve;

            if(grid[i][j]->rank > nextGrid[newx][newy]->rank) {
                if(nextGrid[newx][newy]->rank != 0)
                    move->starve= 0;
                else
                    (move->starve)++;
                //The creature is only fed if the cell it eats is not blank
                delete nextGrid[newx][newy];
                nextGrid[newx][newy]= move;
                (nextGrid[newx][newy]->age)++;
                delete nextGrid[i][j];
                nextGrid[i][j]= new Blank();
            }//eat
            else if(grid[i][j]->rank < nextGrid[newx][newy]->rank) {
                delete nextGrid[i][j];
                nextGrid[i][j]= new Blank();
                nextGrid[newx][newy]->starve= 0;
                (nextGrid[newx][newy]->age)++;
                continue;
            }//get eaten

            //Code to handle reproduction


            nextGrid[i][j]->spawn(i,j,R,C,newx,newy);
            if(newx == -1) {
                continue;
            }//The creature does not reproduce
            Creature* child;
            if(nextGrid[i][j]->rank == 2)
                child= new Zoo();
            else
                child= new Krill();

            if(nextGrid[newx][newy]->rank < child->rank) {
                if(nextGrid[newx][newy]->rank != 0)
                    child->starve= 0;
                else
                    (child->starve)++;
                //The creature is only fed if the cell it eats is not blank
                delete nextGrid[newx][newy];
                nextGrid[newx][newy]= child;
                (nextGrid[newx][newy]->age)++;
            }

            else if(nextGrid[newx][newy]->rank > child->rank) {
                nextGrid[newx][newy]->starve= 0;
            }//Feed the child to the greater creature

        }
    }
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {

            if(nextGrid[i][j]->rank == 0)
                grid[i][j]= new Blank();
            else if(nextGrid[i][j]->rank == 1)
                grid[i][j]= new Phyto();
            else if(nextGrid[i][j]->rank == 2)
                grid[i][j]= new Zoo();
            else if(nextGrid[i][j]->rank == 3)
                grid[i][j]= new Krill();

            grid[i][j]->age= nextGrid[i][j]->age;
            grid[i][j]->starve= nextGrid[i][j]->starve;
            delete nextGrid[i][j];
        }
    }//Copy the next vector to the current vector
}
