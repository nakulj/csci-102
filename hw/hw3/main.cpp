/* 
 * File:   main.cpp
 * Author: Nakul
 *
 * Created on February 21, 2011, 11:20 AM
 */

#include <iostream>
#include <vector>
#include <fstream>
#include "Grid.h"

using namespace std;

/*
 * 
 */

void toggle(Grid&);
void save(Grid&);
void load(Grid&);
void tokenize(const string&, vector<string>&, const string&);

int main(int argc, char** argv) {
    Grid grid;
    grid.reset();
    //initialize grid
    int ch;
    int n;
    grid.display();
    do {
        cout<<"Please enter one of the following commands:"<<endl;
        cout<<"(1) Step one generation forward"<<endl;
        cout<<"(2) Step multiple generations forward"<<endl;
        cout<<"(3) Toggle states of grid cells (and reset the generation number)"<<endl;
        cout<<"(4) Clear the grid (and reset the generation number)"<<endl;
        cout<<"(5) Switch "<<(grid.compact?"out of":"to")<<" compact display mode"<<endl;
        cout<<"(6) Save cell state"<<endl;
        cout<<"(7) Load cell state"<<endl;
        cout<<"(8) Quit"<<endl;
        cin>>ch;
        //Display menu
        switch(ch) {
            //case 9: grid.display();break;
            //case 9 for debugging only, removed from final code
            case 1: grid.next(1); break;
            case 2:
                cout<<"Enter the number of generations to progress"<<endl;
                cin>>n;
                grid.next(n);
                break;
            case 3:
                toggle(grid);
                grid.display();
                break;
            case 4: grid.reset(); break;
            case 5: grid.compact= !grid.compact; break;
            case 6: save(grid); break;
            case 7:
                grid.reset();
                load(grid);
                break;
            case 8: break;
            default:cout<<"Invalid entry, please try again"<<endl;
        }

    }while(ch!=8);
    //Display menu again after processing last choice, unless user quits

    return 0;
}

void toggle(Grid& grid) {
    vector<string> tokens;
    string str;
    cout<<"Enter the cells to toggle"<<endl;
    cin.ignore();
    getline(cin, str);
    cin.clear();
    //Accept coordinates
    for(int i=0; i<str.length(); i++)
        str[i]=(str[i]<'0'||str[i]>'9')?' ':str[i];
    //Replace all non-integers with spaces
    tokenize(str, tokens, " ");
    //Isolate numbers and place into a vector
    if (tokens.empty()||(tokens.size()%2==1)) {
        cout<<"Invalid entry"<<endl;
        return;
    }//If the number of numbers is zero or odd, then the entry is invalid
    for(int i=0; i<tokens.size(); i+=2) {
        grid.toggle(atoi(tokens[i+1].c_str()), atoi(tokens[i].c_str()));
    }//Otherwise use even indices as rows and odd indices as columns
}

void tokenize(const string& str, vector<string>& tokens, const string& delimiters) {
    string::size_type lastPos= str.find_first_not_of(delimiters, 0);
    string::size_type pos= str.find_first_of(delimiters, lastPos);
    //Skip initial delimiters, find first integer
    while (string::npos != pos || string::npos != lastPos) {
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        //Push found tokens back to the vector
        lastPos = str.find_first_not_of(delimiters, pos);
        //Skip delimiters
        pos = str.find_first_of(delimiters, lastPos);
        //Find next "non-delimiter"
    }
}

void save(Grid& grid) {
    string name;
    cout<<"Enter the name of the file to save to"<<endl;
    cin.ignore();
    getline(cin, name);
    cin.clear();
    //Accept filename
    ofstream out;
    out.open(name.c_str());
    grid.save(out);
    //Call the Grid object's save method
    out.close();
}

void load(Grid& grid) {
    string name;
    cout<<"Enter the name of the file to load"<<endl;
    cin.ignore();
    getline(cin, name);
    cin.clear();
    //Accept filename
    ifstream in;
    in.open(name.c_str());
    grid.load(in);
    //Call the Grid object's load method
    in.close();
}
