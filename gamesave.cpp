#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "header.h"

using namespace std;

// Defination of struct role is include in "header.h"
/*
struct role{
    string legend;
    string name;
    int damage;
    int health;
    int defense;
    int gold_coin;
    string weapon;
    string armor;
    bool holly_relic;
    string trash_talk[3];
};
*/

// Definition of player controlled by user
role role1;

//Function gamesave, enter the file name and save game data (map, player position, legend, name, and other informations) in that file.
void gamesave(){
    ofstream fout;
    string savename,data;
    bool if_exist;
    cout << "Please input your game name." << endl;
    cin >> savename;
    fout.open(savename.c_str());

    // If open file fail, print error information on the screen
    if(fout.fail()){
        cout << "Error in opening the file." << endl;
        fout.close();
    }
    
    //If successful, load the map and role information
    else{
        // map information
        for (int i=0; i<5;i++){
            fout << choose1[i] << " ";
        }
        fout << endl;

        for (int i=0; i<5;i++){
            fout << choose2[i] << " ";
        }
        fout << endl;

        for (int i=0; i<5;i++){
            fout << choice[i] << " ";
        }
        fout << endl;

        // role information
        fout << status << " " << num << endl;
        fout << role1.legend << "\n" ;
        fout << role1.name << "\n" ;
        fout << role1.damage << " " ;
        fout << role1.health << " " ;
        fout << role1.defense << " " ;
        fout << role1.gold_coin << "\n" ;
        fout << role1.weapon << "\n" ;
        fout << role1.armor << "\n" ;
        fout << role1.holly_relic << " " << endl;;
        for (int i=0; i<3; i++){
            fout << role1.trash_talk[i] << endl;
        }
        cout << "This game is saved." << endl;
        fout.close();
        ifstream fin;
        // game_menu.txt is used to store the list of file names of save files.
        // Check if this save file exists
        fin.open("game_menu.txt");
        while (fin >> data){
            if (data == savename){
                if_exist = true;
            }
        }
        fin.close();
        // If the save file does not exist in game_menu.txt, append the file name to game_menu.txt
        if (if_exist == false){
            fout.open("game_menu.txt", ios::app);
            fout << savename << endl;
            fout.close();
        }
        // If the save file name exists in game_menu.txt, do nothing
    }
}

//show the game saved in the game menu and let user choose one save file, then return the chosen file name.
string choosegame(){
    ifstream fin;
    vector<string> savenames;
    fin.open("game_menu.txt");
    string savename;
    int index;
    bool check = false;
    cout << "Existing games are as follows: " << endl;
    index = 1;
    while(fin >> savename){
        cout << index << ". " << savename << endl;
        savenames.push_back(savename);
        index++;
    }
    
    //select history game saved
    cout << "Please choose a game." << endl;
    cin >> index;
    while (index <= 0 || index > savenames.size()){
        cout << "Game does not exist, please try again." << endl;
        cin >> index;
    }
    cout << "Load successfully." << endl;
    fin.close();
    return savenames[index-1];
}

// load the game in file "savename". If file open fail, print error information and return false. If file load successfully, return true.
bool loadgame(string savename){
    ifstream fin;
    // data is used to read int information in save file.
    int data;
    // data_str is used to read string information in save file
    string data_str;
    
    fin.open(savename.c_str());
    // print error information on screen if file open fail
    if (fin.fail()){
        fin.close();
        cout << "Error in opening the file." << endl;
        return false;
    }
    else {
        // read data about map
        for (int i=0; i<5; i++){
            fin >> data;
            
            choose1[i] = data;
        }
        for (int i=0; i<5; i++){
            fin >> data;
            
            choose2[i] = data;
        }
        
        for (int i=0; i<5; i++){
            fin >> data;
            
            choice[i] = data;
        }
        fin >> data;
        status = data;
        fin >> data;
        num = data;
        // read data about player
        getline(fin,data_str);
        getline(fin,data_str);
        role1.legend = data_str;
        getline(fin,data_str);
        role1.name = data_str;
        fin >> data;
        role1.damage = data;
        fin >> data;
        role1.health = data;
        fin >> data;
        role1.defense = data;
        fin >> data;
        role1.gold_coin = data;
        getline(fin,data_str);
        getline(fin,data_str);
        role1.weapon = data_str;
        getline(fin,data_str);
        role1.armor = data_str;
        fin >> data;
        role1.holly_relic = data;
        getline(fin,data_str);
        for (int i=0; i<3; i++){
            getline(fin,data_str);
            role1.trash_talk[i] = data_str;
        }
        fin.close();
        return true;
    }
    fin.close();
    return false;    
}
