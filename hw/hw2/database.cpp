/* 
 * File:   database.cpp
 * Author: Nakul
 *
 * Created on January 30, 2011, 2:27 PM
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include "Game.h"
#include "UserList.h"

using namespace std;

/*
 * 
 */


void print(vector<Game> &games) {
    
    if(games.size()==0) {
        cout<<"The game database is currently empty."<<endl;
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
    
    for(int i=0; i<games.size(); i++) {
        games[i].print();
    }//print all games

}

void print(vector<Game> &games, vector<UserList> &lists) {
    string listName;
    bool valid= false;
    if(lists.empty()) {
        cout<<"There are no lists in the database."<<endl;
        return;
    }
    cout<<"Enter name of the list to print"<<endl;
    while(!valid) {
        cin.ignore();
        getline(cin, listName);
        for(int i= 0; i<lists.size(); i++) {
            if(listName == lists[i].getName()) {
                lists[i].print(games);
                return;
            }
        }//Prints the list if found

        //Only reaches this point if list not found
        cout<<"The list you entered does not exist, please try again."<<endl;
    }
}

void add(vector<Game> &games) {
    Game temp;
    string name;
    int x,y,z, flag;
    string frac;
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

    for(int i=0; i<games.size(); i++) {
        if(temp == games[i]) {
            cout<<"The game you are trying to add is already in the database."<<endl;
            return;
        }
    }//Check if game is already in database

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
        frac= name.substr(x+1,name.length());
        price+= atof(frac.c_str())/(frac.length()==1?10:100);
        //if there is one digit after the decimal point, divide the fractional by 10, otherwise divide by a hundred
        temp.setPrice(price);
    }//otherwise, the input is fragmented around the decimal point and added appropriately


    //only reaches this point when the game data is complete and valid.
    games.push_back(temp);
}

void add(vector<Game> &games, vector<UserList> &lists) {
    if(lists.empty()) {
        cout<<"There are no lists in the database."<<endl;
        return;
    }
    string
        listName,
        gameName, platform, publisher;
    int listIndex;
    Game temp;
    bool valid= false;

    cout<<"Enter the name of the list that you want to add a game to"<<endl;
    while(!valid) {
        cin.ignore();
        getline(cin, listName);
        for(int i= 0; i<lists.size(); i++) {
            if(listName == lists[i].getName()) {
                valid= true;
                listIndex= i;
                break;
            }
        }//Find the list to be modified
        if(!valid)
            cout<<listName<<" does not exist. Please try again."<<endl;
    }//Prompt user for valid list name
    cin.clear();
    while(true) {
        cout<<"Enter the name, platform and publisher of the game to add."<<endl;
        getline(cin, gameName);
        getline(cin, platform);
        getline(cin, publisher);
        temp.setName(gameName);
        cout<<gameName<<endl;
        temp.setPlatform(platform);
        cout<<platform<<endl;
        temp.setPublisher(publisher);
        cout<<publisher<<endl;
        for(int i= 0; i<games.size(); i++) {
            if(temp == games[i]) {
                lists[listIndex].add(games[i].getId());
                return;
            }//if game found, add to list
        }//search for game id

        //only reaches this point if game not found
        cout<<"The game you entered does not exist. Please try again"<<endl;
    }//prompt user for valid game

}

void add(vector<UserList> &lists) {
    string listName;
    cout<<"Enter the name of the list to add"<<endl;
    cin.ignore();
    getline(cin, listName);
    lists.push_back(UserList(listName));
}

void rem(vector<UserList> &lists, vector<Game> &games) {
    if(games.empty()) {
        cout<<"There are no games in the database"<<endl;
        return;
    }
    string gameName, platform, publisher;
    Game temp;
    while(true) {
        cout<<"Enter the name, platform and publisher of the game to remove."<<endl;
        cin.clear();
        getline(cin, gameName);
        getline(cin, platform);
        getline(cin, publisher);
        
        temp.setName(gameName);
        temp.setPlatform(platform);
        temp.setPublisher(publisher);
        for(int i= 0; i<games.size(); i++) {
            if(temp == games[i]) {
                for(int j= 0; j<lists.size(); j++) {
                    lists[i].del(games[i].getId());
                }//erase from all lists
                games.erase(games.begin() + i);
                return;
            }//if game found, erase
        }//search for game

        //only reaches this point if game not found
        cout<<"The game you entered does not exist. Please try again"<<endl;
    }//prompt user for valid game
}

void rem(vector<Game> &games, vector<UserList> &lists) {
    if(games.empty()) {
        cout<<"There are no games to remove."<<endl;
        return;
    }
    if(lists.empty()) {
        cout<<"There are no lists to remove games from"<<endl;
        return;
    }
    string
        listName,
        gameName, platform, publisher;
    int listIndex;
    Game temp;
    bool valid= false;

    cout<<"Enter the name of the list that you want to remove a game from"<<endl;
    while(!valid) {
        cin.ignore();
        getline(cin, listName);
        
        for(int i= 0; i<lists.size(); i++) {
            if(listName == lists[i].getName()) {
                valid= true;
                listIndex= i;
                break;
            }
        }//Find the list to be modified
        cout<<listName<<" does not exist. Please try again."<<endl;
    }//Prompt user for valid list name
    if(lists[listIndex].empty()) {
        cout<<"There are no games in this list"<<endl;
        return;
    }
    while(true) {
        cout<<"Enter the name, platform and publisher of the game to remove."<<endl;
        cin.ignore();
        getline(cin, gameName);
        
        getline(cin, platform);
        
        getline(cin, publisher);
        
        temp.setName(gameName);
        temp.setPlatform(platform);
        temp.setPublisher(publisher);
        for(int i= 0; i<games.size(); i++) {
            if(temp == games[i]) {
                lists[listIndex].rem(games[i].getId());
                return;
            }//if game found, remove list
        }//search for game id

        //only reaches this point if game not found
        cout<<"The game you entered does not exist. Please try again"<<endl;
    }//prompt user for valid game
}

void rem(vector<UserList> &lists) {
    if(lists.empty()) {
        cout<<"There are no lists to remove"<<endl;
        return;
    }
    string listName;
    cout<<"Enter the name of the list that you want to remove"<<endl;
    while(true) {
        cin.ignore();
        getline(cin, listName);
        for(int i= 0; i<lists.size(); i++) {
            if(listName == lists[i].getName()) {
                lists.erase(lists.begin() + i);
                return;
            }
        }//Find the list to be removed

        //Only reaches this point if list does not exist
        cout<<listName<<" does not exist. Please try again."<<endl;
    }//Prompt user for valid list name
}

void exp(vector<Game> &games, vector<UserList> &lists) {
    string filename;
    ofstream file;
    cout<<"Enter then name of the file to export to"<<endl;
    cin>>filename;
    file.open(filename.c_str());
    cout<<"Exporting games..."<<endl;
    for(int i= 0; i<games.size(); i++) {
        games[i].toFile(file);
    }
    file<<"----"<<endl;
    cout<<"Exporting lists..."<<endl;
    for(int i= 0; i<lists.size(); i++) {
        lists[i].toFile(file);
    }
    file.close();
}

int main(int argc, char** argv) {
    vector<Game> games;
    vector<UserList> lists;
    int choice=0;
    while(choice!=6) {
        cout<<
                " 1. Print games"<<endl<<
                " 2. Print a list"<<endl<<
                " 3. Add a game"<<endl<<
                " 4. Remove a game"<<endl<<
                " 5. Add a game to a list"<<endl<<
                " 6. Remove a game from a list"<<endl<<
                " 7. Add a list"<<endl<<
                " 8. Remove a list"<<endl<<
                " 9. Export database"<<endl<<
                "10. Quit"<<endl;
        cin>>choice;
        if(cin.fail()) {
            cout<<"Invalid choice, please try again"<<endl;
            continue;
        }
        switch(choice) {
            case 1: print(games); break;
            case 2: print(games, lists); break;
            case 3: add(games); break;
            case 4: rem(lists, games); break;
            case 5: add(games, lists); break;
            case 6: rem(games, lists); break;
            case 7: add(lists); break;
            case 8: rem(lists); break;
            case 9: exp(games, lists); break;
            case 10: return 0;
            default: cout<<"Invalid choice, please try again"<<endl;
        }
    }
}

