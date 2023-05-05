#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <math.h>
#include <cstdlib>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include "header.h"
using namespace std;



int main(){
    srand((unsigned int)time(NULL));
    cout << "###################################" << endl;
    cout << "#                                 #" << endl;
    cout << "#         Welcome to the          #" << endl;
    cout << "# Text Adventure Game - Dungeon   #" << endl;
    cout << "#                                 #" << endl;
    cout << "###################################" << endl;
    
    //cout << "Please choose a existing game (Input 1) or choose a new game (Input 2) or quit the whole game(Input 0)" << endl;
    cout << "   - 1. [Continue]\n   - 2. [New Game]\n   - 3. [Quit]\n";
    bool g;
    int end, place;
    string savename, command, Places[4]={};
    role boss;
    ifstream fin;
    cout << "Please select an option: ";
    cin >> command;
    while (command != "3" ){
        while (command != "1" && command != "2"){
            cout << "Error. Please input a correct number." << endl;
            cin >> command;
            }
        
        // load game
        if ( command == "1" ){
            fin.open("game_menu.txt");
            g = true;
            if (fin.fail()){
                cout << "No existing game, please create a game first." << endl;
                g = false;
                cin >> command;
            }
            else {
                savename = choosegame();
                g = loadgame(savename);
                cout << "Fornign traveller, you come back to your adventure!" << endl;
            }
        }

        // new game
        else if ( command == "2" ){
            makepath();
            cout << "Maze is initialized." << endl;
            cout << "Oh traveler who is lost in confusion, your soul has been reborn into a different world." << endl;
            cout << "Now choose your legend and embark on a new adventure." << endl;
            g = false;
            sleep(2);
            while (g == false){
                makerole(role1);
                if (role1.legend == "Human warrior"){
                    cout << "     /|___________\n()___) >_________/\n     \\|\n";
                }
                else if (role1.legend == "Elf magician"){
                    cout << "    /\\\\\n   // \\\\\n  //   \\\\\n  ||   ||\n  ||   ||\n  ||   ||\n  \\\\___/\n";
                }
                else if (role1.legend == "Giant tank"){
                    cout << "   /_\\\n //_ _\\\\\n||     ||\n||     ||\n \\\\   //\n  \\\\ //\n   \\|/\n";
                }
                cout << "Legend: " << role1.legend << endl;
                cout << "HP: " << role1.health << endl;
                cout << "Attack: " << role1.damage << endl;
                cout << "Defense: " << role1.defense << endl;
                cout << "Are you sure you want to choose this role?\n1. [Yes]\n2. [No]\n";
                cin >> command;
                while (command != "1" && command != "2"){
                    cout << "Invalid choice, please try again." << endl;
                    cin >> command;
                }
                if (command == "1"){
                    g = true;
                }
            }
            cout << "Now please tell your name, brave legend." << endl;
            cin >> command;
            role1.name = command;
            cout << "Fornign traveller, your advanture starts!" << endl; 
            status=1;
            num=0;
        }

        if (g){
            cout<< "1. [Move forward]\n"
                << "2. [View the map]\n"
                << "3. [Check your inventory]\n"
                << "4. [Save and quit the game]\n"
                << "5. [Quit the game without saving]\n";
                
            
            while (status!=0){
                cin>>command;
                //showmap
                if (command=="2"){
                    //showmap();
                    drawlRoad(status);
                }
                //savegame
                else if (command=="4"){
                    gamesave();
                    break;
                }
                //quit
                else if (command=="5"){
                    //quit;
                    break;
                }
                //display bag
                else if (command=="3"){
                    display_bag(role1);
                }
                else if (command=="1"){
                    status++;
                    cout<<"     |     "<<endl; //
                    if (status%3==0 && status!=15){
                        //int nchoose;
                        //cout<<choose1[num]<<"     "<<choose2[num]<<endl;
                        cout << "You have reached a fork in the road! Which way do you turn?" << endl;
                        cout << "1. Turn left" << endl;
                        cout << "2. Turn right" << endl;
                        cin >> command;
                        while (command != "1" && command != "2"){
                            cout << "Invalid choice, please try again." << endl;
                            cin >> command;
                        }
                        if (command == "1"){
                            place = choose1[num];
                        }
                        else if (command == "2"){
                            place = choose2[num];
                        }
                        num++;
                        //map(place);
                        switch (place){
                        case 0:
                            ShowShop_and_BuyItems();
                            break;
                        case 1:
                            if (status<11){
                                Portal(num, status);		
                            }
                            else {
                                cout << "You find a portal, but it looks broken.";
                            }
                            break;
                        case 2:
                            boss = create_monster();
                            fight(boss);
                            break;
                        case 3:
                            randomEvent();
                            break;
                        default:
                            cout << "Error in map." << endl;
                            break;
                        }
                    }
                    //final boss
                    else if (status==15){
                        status=0;
                        cout << "You meet the final boss of the maze." << endl;
                        boss = create_dragon();
                        end = fight(boss);
                        if (end==0){
                        //TE
                            cout << "You defeat the boss, but youself become the new Prince of the Devils." << endl;
                            cout << "You get to end of the maze and your soul is pulled to a unknown place again......" << endl;
                            //制作名单
                            cout << "Thanks for playing!" << endl;
                            cout << "Press any key to return to the main menu" << endl;
                            cin >> command;
                            break;
                        }
                        cout << "Unfortunately, your character was defeated by the final boss.\n";
                        cout << "It's a tough loss, but don't give up!\n";
                        cout << "Keep trying and honing your skills, and success will come eventually.\n";
                    }
                    //cout<<"You can go upward(input 0) OR check map(input 1) OR savegame and quit game(input 2) OR quit game without savegame(input 3) OR check bag(input 4)" << endl;
                }
                else {
                    cout<<"You can only go upward"<<endl;
                    continue;
                }
            }
            
            sleep(3);
            //cout << "Please choose a existing game (Input 1) or choose a new game (Input 2) or quit the whole game(Input 0)" << endl;
            cout << "###################################" << endl;
            cout << "#                                 #" << endl;
            cout << "#         Welcome to the          #" << endl;
            cout << "# Text Adventure Game - Dungeon   #" << endl;
            cout << "#                                 #" << endl;
            cout << "###################################" << endl;
            cout << "1. [Continue]\n2. [New Game]\n3. [Quit]\n";
            cin >> command;
        }
    }
    return 0;
}
