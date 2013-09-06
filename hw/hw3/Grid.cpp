/* 
 * File:   Grid.cpp
 * Author: Nakul
 * 
 * 32reated on February 17, 2011, 4:04 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Grid.h"

using namespace std;

Grid::Grid() {
    compact= false;
}

void Grid::reset() {
    gen= 0;
    for(int i=0; i<12; i++) {
        for(int j=0; j<32; j++) {
            grid[i][j]= false;
        }
    }
}

void Grid::next(int steps) {
    for(int i=1; i<=steps; i++) {
        next();//Progress one step
        display();//Display the grid
        sleep(1);//Pause one second
    }//Repeat
}

void Grid::next() {
    bool nextGrid[12][32];//Holds the next state
    int n;
    for(int i=0; i<12; i++) {
        for(int j=0; j<32; j++) {
            n= countLiveNeighbours(i,j);
            nextGrid[i][j]= grid[i][j];
            if(grid[i][j]) {
                if(n<2 || n>3)
                    nextGrid[i][j]= false;
                //cell dies if it has less than two or more than three live neighbours
                continue;
            }//If cell is alive
            if(n==3)
                nextGrid[i][j]= true;
            //if cell is dead and has three neighbours, make it alive
        }//for every column
        cout<<endl;
    }//for every row
    cout<<endl;
    for(int i=0; i<12; i++) {
        for(int j=0; j<32; j++) {
            grid[i][j]= nextGrid[i][j];
        }
    }//Copy over from next to current
    gen++;
    //Increment generation
}

int Grid::countLiveNeighbours(int x, int y) {
    int n= 0;
    bool colBeg= (y==0);
    bool colEnd= (y==(32-1));

    if(x!=0) {
        n+= colBeg?0:(grid[x-1][y-1]?1:0);
        n+= grid[x-1][y]?1:0;
        n+= colEnd?0:(grid[x-1][y+1]?1:0);
    }//Add top neigbours

    n+= colBeg?0:(grid[x][y-1]?1:0);
    n+= colEnd?0:(grid[x][y+1]?1:0);
    //Add left and right neighbours

    if(x!=11) {
        n+= colBeg?0:(grid[x+1][y-1]?1:0);
        n+= grid[x+1][y]?1:0;
        n+= colEnd?0:(grid[x+1][y+1]?1:0);
    }//Add bottom neigbours

    return n;
}

void Grid::display() {
    string border= "   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
    //Top and bottom border
    if(compact) {
        border= "+--------------------------------+";
    }
    cout<<"Generation: "<<gen<<endl;
    //Display generation number
    if(!compact) {
        cout<<"                        1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 3 3"<<endl;
        cout<<"    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1"<<endl;
    }//Column numbers
    cout<<border<<endl;
    for(int i=0; i<12; i++) {
        if(!compact)
            cout<<right<<setw(2)<<i<<" ";
        cout<<"|";
        for(int j=0; j<32; j++)
            cout<<(grid[i][j]?"@":" ")<<(compact?"":"|");//Columns
        cout<<(compact?"|":"")<<endl;//Seperators
        if(!compact)
            cout<<border<<endl;
    }//Rows
    if(compact)
        cout<<border<<endl;
    cout<<endl;
}

void Grid::toggle(int x, int y) {
    grid[x][y]= !grid[x][y];
    gen= 0;
    //Toggle
}

void Grid::save(ofstream& out) {
    for(int i= 0; i<12; i++) {
        for(int j= 0; j<32; j++)
            out<<(grid[i][j]?'1':'0');
    }
}

void Grid::load(ifstream& in) {
    char ch;
    for(int i= 0; i<12; i++) {
        for(int j=0; j<32; j++) {
            in>>ch;
            grid[i][j]= (ch=='1'?true:false);
        }
    }
}
