#include <iostream>
#include <string>
#include <unistd.h>
#include<stdlib.h> 
#include<time.h> 
using namespace std;
//place notations - 0: shop; 1: jump to other place; 2: monster
int choice[5]={};//record players' choices
int num, status;
int choose1[5], choose2[5];
//choose1 is array with chooses on leftside, choose2 is array with chooses on rightside

void makepath(){
    //int a[2], b[2], c[2], d[2], e[2];
    //int choose[5];
    for (int j=0; j<5; j++){
        //for (int i = 0; i < 2; ++i)
        choose1[j]=rand() % 3;
	choose2[j]=rand() % 3;
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
    if (direction==2){
            place=choose2[num];
	    cout<<"         |?"<<endl;
	    choice[num]=2;
    }
    cout<<"Are you sure? Yes Or No"<<endl;
    cin>>answer;
    while (answer=="No"){
        choosedirection(num);
    }
    return place;
}

void map(int place){
    if (place==0){
        //shop system
    }
    if (place==1){
	if (status<11){
            status=status+rand()%(13-status);
	}
    }
    if (place==2){
        //boss system
    }
}

void showmap(){
    for (int i=0; i<num; i++){
        if (status<3){
            cout<<"     |     "<<endl;
            break;
        }else{
            if (choice[i]==1){
                cout<<"     |     "<<endl;
                cout<<"|          "<<endl;
                cout<<choose1[i]<<"     "<<choose2[i]<<endl;
            }else{
                cout<<"     |     "<<endl;
                cout<<"          |"<<endl;
                cout<<choose1[i]<<"     "<<choose2[i]<<endl;
            }
        }
    }
    cout<<"---------------"<<endl;
}

int main() {
	makepath();
	int status=1, num=0;
	//num is number of choices
	int change, place;
	//change are shown below in string
	cout<<"You can go upward(input 0) OR check map(input 1) OR savegame and quit game(input 2) OR quit game without savegame(input 3) OR check bag(input 4)"<<endl;
	while (status!=0){
	    cin>>change;
	    if (change==1){
	        showmap();
	    }
	    if (change==2){
	        //save and quit;
	    }
	    if (change==3){
		//quit;
	    }
	    if (change==4){
		//bagfunction;
	    }
	    if (change==0){
	        status++;
		cout<<"     |     "<<endl;
	        if (status%3==0 && status!=15){
		    //cout<<choose1[num]<<"     "<<choose2[num]<<endl;
	            choosedirection(num);
		    num++;
	            map(place);
	        }
	        if (status==15){
	            status=0;
	            //final boss
	            break;
	        }
	    }
	    if (change!=0){
	        cout<<"You can go upward"<<endl;
	        continue;
	    }
	}
	return 0;
}
