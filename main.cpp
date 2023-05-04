#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <math.h>
#include <cstdlib>
#include <unistd.h>
#include <time.h>
#include "header.h"
using namespace std;

int choice[5]={};
int num=0, status=1, nchoice=0;
int choose1[5], choose2[5], bifurcation[5]={0, 1, 2, 3, 4};
int status, num, change, place;
role role1, boss;

int main(){
    cout << "Oh traveler who is lost in confusion, your soul has been reborn into a different world." << endl;
    cout << "Now choose your legend and embark on a new adventure." << endl;
    cout << "Please choose a existing game (Input 1) or choose a new game (Input 2) or quit the whole game(Input 0)" << endl;
    int a, end;
    bool g;
    ifstream fin;
    string savename;
    cin >> a;
    while (a != 0 ){
        while (a != 1 && a != 2){
            cout << "Error. Please input a correct number." << endl;
            cin >> a;
            }
        g = true;
        // load game
        if ( a == 1 ){
            
            fin.open("game_menu.txt");
            if (fin.fail()){
                cout << "No existing game, please create a game first.";
                g = false;
            }
            else {
                cout << "Fornign traveller, you come back to your adventure!" << endl;
                savename = choosegame();
                loadgame(savename);
            }
        }

        // new game
        else if ( a == 2 ){
            cout << "Fornign traveller, your advanture starts!" << endl; 
            makepath();
            cout << " Maze is initialized." << endl;
            makerole(role &role1);
            status=1;
            num=0;
        }

        if (g){
            cout<<"You can go upward(input 0) OR check map(input 1) OR savegame and quit game(input 2) OR quit game without savegame(input 3) OR check bag(input 4)" << endl;
            while (status!=0){
                cin>>change;
                //showmap
                if (change==1){
                    showmap();
                }
                //savegame
                else if (change==2){
                    gamesave();
                    break;
                }
                //quit
                else if (change==3){
                    //quit;
                    break;
                }
                //display bag
                else if (change==4){
                    display_bag(role role1);
                }
                else if (change==0){
                    status++;
                    cout<<"     |     "<<endl; //
                    if (status%3==0 && status!=15){
                        //int nchoose;
                        //cout<<choose1[num]<<"     "<<choose2[num]<<endl;
                        place = choosedirection(num);
                        num++;
                        map(place);
                    }
                    //final boss
                    else if (status==15){
                        status=0;
                        cout << "You meet the final boss of the maze." << endl;
                        role boss = create_dragon();
                        end = fight(role role1, role boss);
                        if (end==1){
                        //TE
                        cout << "You defeat the boss, but youself become the new Prince of the Devils." << endl;
                        cout << "You get to end of the maze and your soul is pulled to a unknown place again......" << endl;
                        break;
                        }
                    }
                    cout<<"You can go upward(input 0) OR check map(input 1) OR savegame and quit game(input 2) OR quit game without savegame(input 3) OR check bag(input 4)" << endl;
                }
                else {
                    cout<<"You can only go upward"<<endl;
                    continue;
                }
            }
            //制作名单
            sleep(3);
            cout << "Please choose a existing game (Input 1) or choose a new game (Input 2) or quit the whole game(Input 0)" << endl;
            cin >> a;
        }
    }
    return 0;
}
