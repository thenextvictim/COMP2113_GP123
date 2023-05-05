#include <iostream>
#include <string>
#include <unistd.h>
#include<stdlib.h>
#include<time.h>
#include <iomanip>
#include "header.h"
using namespace std;
//place notations - 0: shop; 1: jump to other place; 2: monster
int choice[5]={};
int num=0;
int status=1;
int choose1[5]={};
int choose2[5]={};


void makepath(){
    //int a[2], b[2], c[2], d[2], e[2];
    //int choose[5];
    for (int j=0; j<5; j++){
        //for (int i = 0; i < 2; ++i)
        choose1[j]=rand() % 4;
		choose2[j]=rand() % 4;
    }
}

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

void drawlRoad(int num) {
    string road = "_ _ ? _ _ ? _ _ ? _ _ ? _ _ !";
    cout << road << endl;
    cout << setw(num*2-1) << right << "@" << endl;
    cout << setw(num*2-1+6) << right << "You are here" << endl;
}
