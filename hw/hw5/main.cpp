/* 
 * File:   main.cpp
 * Author: Nakul
 *
 * Created on April 28, 2011, 12:12 PM
 */

#include <cstdlib>
#include <iostream>
#include "Grid.h"

using namespace std;

/*
 * 
 */

void edit(Grid& grid);
void replace(string&, string delim);
void tokenize(const string&, vector<string>&, const string&);

int main(int argc, char** argv) {
    int R= 12; int C=32;
    if(argc != 1) {
        string arg;
        string argType;
        if(argc>3) {
            cout<<"Too many arguments"<<endl;
            return -1;
        }//There can only be 4 arguments
        for(int i=1; i<argc; i++) {
            arg= argv[i];
            argType= arg.substr(0,3);
            if(argType == "-h="){
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
    Grid grid(R, C);
    grid.reset();
    int ch, n;
    do {
        cout<<"Please enter one of the following commands:"<<endl;
        cout<<"(1) Step one generation forward"<<endl;
        cout<<"(2) Step multiple generations forward"<<endl;
        cout<<"(3) Add or remove creatures (and reset the generation number)"<<endl;
        cout<<"(4) Clear the grid (and reset the generation number)"<<endl;
        cout<<"(5) Quit"<<endl;
        cin>>ch;
        //Display options
        switch(ch) {
            case 6:
                grid.display(); break;
            case 1: grid.next(1); break;
            case 2:
                cout<<"Enter the number of generations to progress"<<endl;
                cin>>n;
                grid.next(n);
                break;
            case 3:
                edit(grid);
                grid.display();
                break;
            case 4:
                grid.reset();
                break;
            case 5:
                return 0;
            default: cout<<"Invalid choice, please try again"<<endl;
        }//Process input
    }while(true);
    return 0;
}

void edit(Grid& grid) {
    int creatureType;
    Creature* ptr;
    cout<<"Enter the cells to edit."<<endl;
    vector<string> tokens;
    string str;
    cin.ignore();
    getline(cin, str);
    cin.clear();
    replace(str, "(");
    replace(str, ",");
    replace(str, ")");//Turn seperators into spaces
    tokenize(str, tokens, " ");//Split into tokens and add to tokens vector
    cout<<"What creature do you want at these cells?"<<endl;
    cout<<"1. Phytoplankton"<<endl;
    cout<<"2. Zooplankton"<<endl;
    cout<<"3. Krill"<<endl;
    cout<<"4. None"<<endl;
    cin>>creatureType;
    if(creatureType<1 || creatureType>4) {
        cout<<"Invalid type. Please try again."<<endl;
        return;
    }
    for(int i=0; i<tokens.size(); i+=2) {
        switch(creatureType) {
            case 1: ptr= new Phyto(); break;
            case 2: ptr= new Zoo(); break;
            case 3: ptr= new Krill(); break;
            case 4: ptr= new Blank(); break;
        }
        grid.set(atoi(tokens[i+1].c_str()),atoi(tokens[i].c_str()),ptr);
    }
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
