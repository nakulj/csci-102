/* 
 * File:   main.cpp
 * Author: Nakul
 *
 * Created on February 21, 2011, 11:20 AM
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include "Grid.h"

using namespace std;

/*
 * 
 */

void toggle(Grid&);
void replace(string&, string delim);
void tokenize(const string&, vector<string>&, const string&);

int main(int argc, char** argv) {
    int sleepTime= 1000, R= 12, C= 32;//default values
    if(argc != 1) {
        string arg;
        string argType;
        if(argc>4) {
            cout<<"Too many arguments"<<endl;
            return -1;
        }//There can only be 4 arguments
        for(int i=1; i<argc; i++) {
            arg= argv[i];
            argType= arg.substr(0,3);
            if(argType == "-s=") {
                sleepTime= atoi(arg.substr(3,arg.size()).c_str());
                if(sleepTime<10 || sleepTime>30000) {
                    cout<<"Invalid parameter to argument \'-s\'"<<endl;
                    return -1;
                }
            }
            else if(argType == "-h="){
                R= atoi(arg.substr(3,arg.size()).c_str());
                if(R<3 || R>60) {
                    cout<<"Invalid parameter to argument \'-h\'"<<endl;
                    return -1;
                }
            }
            else if(argType == "-w=") {
                C= atoi(arg.substr(3,arg.size()).c_str());
                if(C<4 || C>132) {
                    cout<<"Invalid parameter to argument \'-w\'"<<endl;
                    return -1;
                }
            }
            else{
                cout<<"Invalid arguments"<<endl;
                return -1;
            }
        }//parse arguments, alter defaults if necessary
    }
    Grid grid(R, C, sleepTime);//Create a new grid
    grid.reset();//Initialize
    int ch;
    int n;
    grid.display();
    do {
        cout<<"Please enter one of the following commands:"<<endl;
        cout<<"(1) Step one generation forward"<<endl;
        cout<<"(2) Step multiple generations forward"<<endl;
        cout<<"(3) Step one generation backward"<<endl;
        cout<<"(4) Step multiple generations backward"<<endl;
        cout<<"(5) Toggle states of grid cells (and reset the generation number)"<<endl;
        cout<<"(6) Clear the grid (and reset the generation number)"<<endl;
        cout<<"(7) Switch "<<(grid.compact?"out of":"to")<<" compact display mode"<<endl;
        cout<<"(8) Quit"<<endl;
        cin>>ch;
        //Display options
        switch(ch) {
            //case 9: grid.display();break;
            //For debug only
            case 1: grid.next(1); break;
            case 2:
                cout<<"Enter the number of generations to progress"<<endl;
                cin>>n;
                grid.next(n);
                break;
            case 3:
                if(!grid.prev(1))
                    cout<<"Cannot go before start of grid"<<endl;
                break;
            case 4:
                cout<<"Enter the number of generations to regress"<<endl;
                cin>>n;
                if(!grid.prev(n))
                    cout<<"Cannot go before start of grid"<<endl;
                break;
            case 5:
                toggle(grid);
                grid.display();
                break;
            case 6: grid.reset(); break;
            case 7: grid.compact= !grid.compact; break;
            case 8: return 0;
            default: cout<<"Invalid choice, please try again"<<endl;
        }//Process input

    }while(ch!=8);

    return 0;
}

void toggle(Grid& grid) {
    vector<string> tokens;
    string str;
    cout<<"Enter the cells to toggle"<<endl;
    cin.ignore();
    getline(cin, str);
    cin.clear();
    replace(str, "(");
    replace(str, ",");
    replace(str, ")");//Turn seperators into spaces
    tokenize(str, tokens, " ");//Split into tokens and add to tokens vector
    for(int i=0; i<tokens.size(); i+=2) {
        grid.toggle(atoi(tokens[i+1].c_str()), atoi(tokens[i].c_str()));
    }//this step fails if there are invalid characters in the input
}

void replace(string &str, std::string delim) {
    vector<string> tokens;
    tokenize(str, tokens, delim);
    str="";
    for(int i=0; i<tokens.size(); i++) {
        str+= tokens[i]+" ";
    }
}

void tokenize(const string& str, vector<string>& tokens, const string& delimiters) {
    // Skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}