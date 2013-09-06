/* 
 * File:   Grid.cpp
 * Author: Nakul
 * 
 * Created on February 17, 2011, 4:04 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Grid.h"

using namespace std;



Grid::Grid(int r, int c, int t) {
    compact= false;
    R= r;
    C= c;
    for(int i=0; i<R; i++) {
        grid.push_back(vector<bool>(C,false));
    }
    sleepTime= t;
}//Initialize values

void Grid::reset() {
    gen= 0;
    stack.clear();
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            grid[i][j]= false;
        }
    }
    //Set generation number to zero, clear the stack, and set all cells to dead
}

void Grid::next(int steps) {
    for(int i=1; i<=steps; i++) {
        next();//progress one step
        display();//print out the grid
        usleep(sleepTime*1000);//pause
    }
}

void Grid::next() {
    stack.push_back(getGridState());//push the current state
    bool nextGrid[R][C];
    int n;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            n= countLiveNeighbours(i,j);//count the live neighbours
            nextGrid[i][j]= grid[i][j];
            if(grid[i][j]) {
                if(n<2 || n>3)
                    nextGrid[i][j]= false;
                continue;
            }
            if(n==3)
                nextGrid[i][j]= true;
            //Calculate next state of the cell
        }
        cout<<endl;
    }//for every cell in the grid
    cout<<endl;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            grid[i][j]= nextGrid[i][j];
        }
    }//apply the new state to all cells simultaneously
    gen++;//increment the generation
}

int Grid::countLiveNeighbours(int x, int y) {
    int n= 0;
    bool colBeg= (y==0);
    bool colEnd= (y==(C-1));
    bool rowBeg= (x==0);
    bool rowEnd= (x==(R-1));

    n+= grid[rowBeg?(R-1):x-1][colBeg?(C-1):y-1]?1:0;
    n+= grid[rowBeg?(R-1):x-1][y]?1:0;
    n+= grid[rowBeg?(R-1):x-1][colEnd?0:y+1]?1:0;
    //Add top neighbours

    n+= grid[x][colBeg?(C-1):y-1]?1:0;
    n+= grid[x][colEnd?0:y+1]?1:0;
    //Add left and right neighbours

    n+= grid[rowEnd?0:x+1][colBeg?(C-1):y-1]?1:0;
    n+= grid[rowEnd?0:x+1][y]?1:0;
    n+= grid[rowEnd?0:x+1][colEnd?0:y+1]?1:0;
    //Add bottom neighbours

    return n;
}

void Grid::display() {
    string border=compact?"+":(R<9?"  +":"   +");
    for(int i= 0; i<C; i++) {
        border+=compact?"-":"-+";
    }
    border+=compact?"+":"";
    cout<<"Generation: "<<gen<<endl;
    if(!compact) {
        cout<<(R<9?"   ":"    ");
        for(int i=0; i<C; i++) {
            if(i>9)
                cout<<i/10;
            else
                cout<<" ";
            cout<<" ";
        }
        cout<<endl;
        cout<<(R<9?"   ":"    ");
        for(int i=0; i<C; i++)
            cout<<(i%10)<<" ";
        cout<<endl;
    }
    cout<<border<<endl;
    for(int i=0; i<R; i++) {
        if(!compact)
            cout<<right<<setw(R<9?1:2)<<i<<" ";
        cout<<"|";
        for(int j=0; j<C; j++)
            cout<<(grid[i][j]?"@":" ")<<(compact?"":"|");
        cout<<(compact?"|":"")<<endl;
        if(!compact)
            cout<<border<<endl;
    }
    if(compact)
        cout<<border<<endl;
    cout<<endl;
}//print the grid

void Grid::toggle(int x, int y) {
    grid[x][y]= !grid[x][y];
    gen= 0;
}//flip the cell and reset the generation number

string Grid::getGridState() {
    string str="";
    for(int i= 0; i<R; i++)
        for(int j=0; j<C; j++)
            str+=grid[i][j]?'1':'0';
    return str;
}//return a string containing the states of all characters

bool Grid::prev(int steps) {
    if(steps>stack.size())
        return false;//Check the number of steps isn't too large
    string state;
    int ctr;
    for(int h=0; h<steps; h++) {
        ctr=0;
        state= stack.back();
        for(int i=0; i<R; i++)
            for(int j=0; j<C; j++)
                grid[i][j]= (state[ctr++]=='1')?true:false;
        stack.pop_back();
        gen--;
        display();
        usleep(sleepTime*1000);
    }
    return true;
}