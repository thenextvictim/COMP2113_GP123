//Portal.cpp
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <map>

using namespace std;

/*
    randomEvent()
*/

int choose[5][2], position[2]={3,1};

const string Dividing_line = "-------------------------------------------------------------------\n";

void Portal(/*character& player,*/ int choose[][2], int position[2]){
    string command;
    cout << Dividing_line
         << "Before you is a sight that seems out of place in the landscape around you. Strangely placed into one of the wall is an enclosed stone entrance filled with a " << "\033[35mswirling magical portal\033[0m" << ".\n" 
         << "You aren't sure where it leads, but maybe it could speed your journey through the Forest.\n";
    cout << Dividing_line
         << "1. " << "\033[1;34m[Enter the Portal]\033[0m Travel to an unknown place.\n" 
         << "2. " << "\033[1;34m[Leave]\033[0m Nothing happens.\n\n";

    getline(cin,command);
    // Handle command.
    cout << Dividing_line;
    if (command == "1"){
        position[0] = 6;
        // change position of player1

        cout << "Jumping through the portal, your sense of time and space is completely torn apart.\n"
             << "As you reorient yourself to the new surroundings, you realize that you have come to a strange place.\n";
    }
    else {
        cout << "Careful and cautious seems the better approach for reaching the top of the Spire. Ignoring the portal you continue on.\n";
    }
    cout << Dividing_line << "1. \033[1;34m[Continue]\033[0m\n\n";
    // getline(cin,command);
}

void Golden_Shrine(/*character& player*/){
    string command;
    cout << Dividing_line << "Before you lies an elaborate shrine to an ancient spirit.\n";
    cout << Dividing_line
        << "1. " << "\033[1;34m[Pray]\033[0m Gain 100 \033[1;33mGold\033[0m.\n"
        << "2. " << "\033[1;34m[Desecrate]\033[0m Gain 275 \033[1;33mGold\033[0m. Become Cursed.\n"
        << "3. " << "\033[1;34m[Leave]\033[0m Nothing happens.\n\n";
    getline(cin,command);

    cout << Dividing_line;
    if (command == "1"){
        // player.golden += 100;
        cout << "As your hand touches the shrine, gold rains from the ceiling showering you in riches.\n";
    }
    else if (command == "2"){
        // player.golden += 275;
        // player.attack -= 3;
        cout << "Each time you strike the shrine, gold pours forth again and again!\n"
             << "As you pocket the riches, something " << "\033[1;31mweighs heavily on you.\033[0m\n";
    }
    else if (command == "3"){
        cout << "You ignore the shrine.\n";
    }
    cout << Dividing_line << "1. \033[1;34m[Continue]\033[0m\n\n";
    // getline(cin,command);
}

void Treasure_chest(){
    string command;
    if (rand()%4 == 1){
        // Mimic
        cout << Dividing_line << "You stumble upon a wooden box. It seems to be a little broken, the lock on it has rusted and damaged. Along with your approach, it emits a slight shaking.\n";
        cout << Dividing_line
            << "1. " << "\033[1;34m[\"Open\"]\033[0m Get random equitment\n"
            << "2. " << "\033[1;34m[Leave]\033[0m Nothing happens.\n\n";
        getline(cin,command);

        cout << Dividing_line;
        if (command == "1"){
            cout << "As you reach for the lock, they notice a slight movement from within. Suddenly, the \"chest\" reveals its true form: a grotesque monster with jagged teeth and a slimy maw!\n";
            cout << Dividing_line
            << "1. " << "\033[1;34m[Fight]\033[0m Get into a tough battle\n"
            << "2. " << "\033[1;34m[Escape]\033[0m RUN! NOW!\n\n";
            getline(cin,command);
            cout << Dividing_line;
            if (command == "1"){
                cout << "The horrible monster did not knock down your will. You decided to defeat it.\n";
                // Fight
                // if Win:
                    cout << "With the last stab you made into its body, you defeated this horrible monster.\n"
                        << "You found a large amount of gold coins and an extremely rare equipment from it.\n";
                    // player.golden += 200 + rand()%50;
                    // Get Equitment
                // if Lose
                    // endGame();

            }
            else if (command == "2"){
                cout << "With 10 minutes of frenzied running, you get rid of the monster successfully\n";
            }
        }
        else if (command == "2"){
            cout << "You ignore this spooky chest.\n";
        }
        cout << Dividing_line << "1. \033[1;34m[Continue]\033[0m\n\n";
        // getline(cin,command);
    }
    else {
        // Treasure Chest
        cout << Dividing_line << "You stumbles upon a wooden chest. it seems to be intact and functional, with no visible signs of damage. a single lock keeps it shut, but it looks like it can be easily opened with the right tools.\n";
        cout << Dividing_line
            << "1. " << "\033[1;34m[Open]\033[0m Get random equitment\n"
            << "2. " << "\033[1;34m[Leave]\033[0m Nothing happens.\n\n";
        getline(cin,command);

        cout << Dividing_line;
        if (command == "1"){
            cout << "You have successfully opened this treasure chest, which contains some gold coins and an intact costume\n";
            // player.golden += 90 + rand()%20;
            // Get an equipment;
        }
        else if (command == "2"){
            cout << "You ignore the chest.\n";
        }
        cout << Dividing_line << "1. \033[1;34m[Continue]\033[0m\n\n";
        // getline(cin,command);
    }
}

void randomEvent(){
    switch (rand()%3)
    {
    case 0:
        Portal(choose,position);
        break;
    
    case 1:
        Golden_Shrine();
        break;

    case 2:
        Treasure_chest();
        break;
    }
}

int main(){
    string command = "1";
    while (command == "1"){
        randomEvent();
        getline(cin, command);
    }
    return 0;
}

