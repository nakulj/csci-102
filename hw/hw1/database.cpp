/* 
 * File:   database.cpp
 * Author: Nakul
 *
 * Created on January 30, 2011, 2:27 PM
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include "Game.h"

using namespace std;

/*
 * 
 */


void print(vector<Game> &games, vector<int> &favs, int ch) {
    //ch is 0 to print whole database
    //ch is 1 to print the favorites list
    if(ch==0 && games.size()==0) {
        cout<<"The game database is currently empty."<<endl;
        return;
    }
    if(ch==1 && favs.size()==0) {
        cout<<"The favorites list is currently empty"<<endl;
        return;
    }
    cout<<
            left<<setw(30)<<"Name"<<'\t'<<
            left<<setw(6)<<"Platform"<<'\t'<<
            left<<setw(10)<<"Category"<<'\t'<<
            left<<setw(20)<<"Publisher"<<'\t'<<
            left<<setw(5)<<"Rating"<<'\t'<<
            left<<setw(10)<<"Date"<<'\t'<<
            left<<"Price"<<
            endl;//1st row of table
    if(ch==0) {
        for(int i=0; i<games.size(); i++) {
            games[i].print();
        }//print all games
        return;
    }
    //only reaches this point if ch is 1
    for(int i=0; i<favs.size(); i++) {
        games[favs[i]].print();
    }//print games in database
}

void add(vector<Game> &games) {
    Game temp;
    string name;
    int x,y,z, flag;
    double price;

    cout<<"Enter the name of the game"<<endl;
    cin.ignore();
    getline(cin, name);
    while(temp.setName(name)==-1) {
        cout<<"Invalid name, please try again"<<endl;
        cin>>name;
    }//keep prompting till good name received

    cout<<"Enter the platform"<<endl;
    cin>> name;
    flag= temp.setPlatform(name);
    while(flag == -1) {
        cout<<"Invalid platform, please try again"<<endl;
        cin>>name;
        flag= temp.setPlatform(name);
    }//keep prompting till good platform name received

    cout<<"Enter the category"<<endl;
    cin>> name;
    flag= temp.setCategory(name);
    while(flag == -1) {
        cout<<"Invalid category, please try again"<<endl;
        cin>>name;
        flag= temp.setCategory(name);
    }//keep prompting till good category received

    cout<<"Enter the name of the publisher"<<endl;
    cin.ignore();
    getline(cin, name);
    flag= temp.setPublisher(name);
    while(flag == -1) {
        cout<<"Invalid name, please try again"<<endl;
        cin>>name;
        flag= temp.setPublisher(name);
    }//keep prompting till good publisher name received

    cout<<"Enter the game's rating"<<endl;
    cin>> name;
    flag= temp.setRating(name);
    while(flag == -1) {
        cout<<"Invalid rating, please try again"<<endl;
        cin>>name;
        flag= temp.setRating(name);
    }//keep prompting till good rating received

    flag=-1;
    cout<<"Enter the date of purchase(MM/DD/YYYY)"<<endl;
    while(flag == -1) {
        cin>>name;
        if(name.length() != 10 || name[2]!='/' || name[5]!= '/') {
            cout<<"Invalid date, please try again."<<endl;
            continue;
        }
        x= atoi(name.substr(0,2).c_str());
        y= atoi(name.substr(3,5).c_str());
        z= atoi(name.substr(6,10).c_str());
        //If any of the atoi() calls fail to process the integers, they will return zeros which will cause the setDate() to fail
        flag= temp.setDate(y, x, z);
        if(flag == -1)
            cout<<"Invalid date, please try again."<<endl;
    }//keep prompting till good date received

    flag= -1;
    cout<<"Enter the price"<<endl;
    input:
    cin>>name;
    y=0; z=0;
    for(int i=0; i<name.size(); i++) {
        if((name[i]<'0' || name[i]>'9') && name[i]!='.') {
            cout<<"Invalid price, please try again"<<endl;
            goto input;
        }//all characters must be either numbers or dots
        if(name[i] == '.') {
            y++; x=i;
            if(i==0 || name.length()>(i+3)) {
                cout<<"Invalid price, please try again"<<endl;
                goto input;
            }//the first character cannot be a dot, there must be only two digits after the dot
        }
        if(y>1) {
            y=0;
            cout<<"Invalid price, please try again"<<endl;
            goto input;
        }//there shouldn't be more than one dot
    }
    if(y==0) {
        temp.setPrice(atoi(name.c_str()));
    }//if there is no decimal point, the input is the price
    else {
        price= atoi(name.substr(0,x).c_str());
        price+= atof(name.substr(x+1,name.length()).c_str())/100;
        temp.setPrice(price);
    }//otherwise, the input is fragmented around the decimal point and added appropriately


    //only reaches this point when the game data is complete and valid.
    games.push_back(temp);
}

void add(vector<Game> &games, vector<int> &favs) {
    string name;
    cout<<"Enter the name of the game to be added to the favorites list"<<endl;
    cin>>name;
    for(int i=0; i<games.size(); i++) {
        if(name==games[i].getName()) {
            for(int j=0; j<favs.size(); j++) {
                if(i == favs[j]) {
                    cout<<"The game is already in the favorites list."<<endl;
                    return;
                }//if game is already added, print message and return
            }//Check that the game is not already added
            favs.push_back(i);
            return;
        }//if game is found, add its index to to favorites list and return
    }//only reaches this point if game not found
    cout<<"Sorry, the game you are looking for is not currently in the database."<<endl;
}

void rem(vector<Game> &games, vector<int> &favs) {
    string name;
    cout<<"Enter the name of the game to be removed from the favorites list"<<endl;
    cin>>name;
    for(int i=0; i<favs.size(); i++) {
        if(name==games[favs[i]].getName()) {
            favs.erase(favs.begin()+i);
            return;
        }
    }//Only reaches this point if game is not in the favorites
    cout<<"Sorry, "<<name<<" is not currently in the favorites list"<<endl;
}

int main(int argc, char** argv) {
    vector<Game> games;
    vector<int> favs;
    int choice=0;
    while(choice!=6) {
        cout<<
                "1. Print games"<<endl<<
                "2. Print favorites"<<endl<<
                "3. Add a game"<<endl<<
                "4. Add a game to favorites list"<<endl<<
                "5. Remove a game from the favorites list"<<endl<<
                "6. Quit"<<endl;
        cin>>choice;
        if(cin.fail()) {
            cout<<"Invalid choice, please try again"<<endl;
            continue;
        }
        switch(choice) {
            case 1: print(games, favs, 0); break;
            case 2: print(games, favs, 1); break;
            case 3: add(games); break;
            case 4: add(games, favs); break;
            case 5: rem(games, favs); break;
            case 6: break;
            default: cout<<"Invalid choice, please try again"<<endl;
        }
    }
    return 0;
}

