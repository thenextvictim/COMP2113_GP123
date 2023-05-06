#include <iostream>
#include <string>
#include <unistd.h>
#include<stdlib.h>
#include<time.h>
#include <iomanip>
#include "header.h"
using namespace std;
//place notations - 0: shop; 1: jump to other place/ portal; 2: monster; 3: other places

int choice[5]={};//this choice array is used to store player's choices(left or right) when they meet forks
int num=0;//number of forks the player met
int status=1;//player's current status, total: 15
int choose1[5]={};//this array is used to store all choices on the left that player can choose
int choose2[5]={};//this array is used to store all choices on the right that player can choose
//there are 5 forks in total
//player can only choose left (5 choices saved by choose1 array) or right (5 choices saved by choose2 array)

//makepath is a function that randomly generate map, and it is run before player starts playing game
//For each game, the map does not change, so saving a game will record information about the entire map.
void makepath(){
    //int a[2], b[2], c[2], d[2], e[2];
    //int choose[5];
    for (int j=0; j<5; j++){
        //for (int i = 0; i < 2; ++i)
        choose1[j]=rand() % 4; 
	choose2[j]=rand() % 4;
	//randomly generate places and saved as integral numbers in arries
    }
}

//choosedirection is used to distinguish whether the player's choice is left of right
//it returns corresponding integral number of places
int choosedirection(int num){
    int place;
    string answer;
    cout<<"Choose your direction: Left (input 1) OR Right (intput 2)"<<endl;
    int direction;
    cin>>direction;
    if (direction==1){
	    cout<<"|         ?"<<endl;
            place=choose1[num];
	    choice[num]=1;
    }
    else if (direction==2){
            place=choose2[num];
	    cout<<"         |?"<<endl;
	    choice[num]=2;
    }
    /*
    cout<<"Are you sure? Yes Or No"<<endl;
    cin>>answer;
    while (answer=="No"){
        choosedirection(num);
    }
    */
    return place;
}


void showmap(){
    for (int i=0; i<num; i++){
        if (status<3){
	    cout<<"     |     "<<endl;
            break;
        }
        else {
            if (choice[i]==1){
                cout<<"     |     "<<endl;
                cout<<"|          "<<endl;
                cout<<choose1[i]<<"     "<<choose2[i]<<endl;
            }
            else {
                cout<<"     |     "<<endl;
                cout<<"          |"<<endl;
                cout<<choose1[i]<<"     "<<choose2[i]<<endl;
            }
        }
    }
    cout<<"---------------"<<endl;
}

//drawRoad is function to show the current place of player and whole map/road of game
void drawlRoad(int num) {
    string road = "_ _ ? _ _ ? _ _ ? _ _ ? _ _ !";
    cout << road << endl;
    cout << setw(num*2-1) << right << "@" << endl;
    cout << setw(num*2-1+6) << right << "You are here" << endl;
}
