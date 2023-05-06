#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "header.h"

using namespace std;


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

role role1;

//Function gamesave, enter the game name and open the file
void gamesave(){
    ofstream fout;
    string savename,data;
    bool if_exist;
    cout << "Please input your game name." << endl;
    cin >> savename;
    fout.open(savename.c_str());

    //If successful, load the map and role information
    if(fout.fail()){
        cout << "Error in opening the file." << endl;
        fout.close();
    }
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
        //open game menu and save the game name, then close
        fin.open("game_menu.txt");
        while (fin >> data){
            if (data == savename){
                if_exist = true;
            }
        }
        fin.close();
        if (if_exist == false){
            fout.open("game_menu.txt", ios::app);
            fout << savename << endl;
            fout.close();
        }
    }
}

//show the game saved in the game menu and choose a game 
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

bool loadgame(string savename){
    ifstream fin;
    int data;
    string data_str;
    fin.open(savename.c_str());
    if (fin.fail()){
        fin.close();
        cout << "Error in opening the file." << endl;
        return false;
    }
    else {
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


/*
int main(){
        role1.legend = "Human warrior";
        role1.damage = 20;
        role1.health = 100;
        role1.defense = 10;
        role1.gold_coin = 10;
        role1.weapon = "Nothing";
        role1.armor = "Nothing";
        role1.holly_relic = false;
        role1.trash_talk[0] = "In the name of justice, your guilty will be judged!";
        //“星星之火，可以燎原。”
        role1.trash_talk[1] = "A single spark can start a prairie fire";
        //"失去人性，失去很多。失去兽性，失去一切。"
        role1.trash_talk[2] = "Lose humanity, lose much. Lose animalistic nature, lose all.";
    string savename;   
    gamesave();
    savename = choosegame();
    loadgame(savename);
    cout << "choose1:" << endl;
    for (int i=0; i<5;i++){
            cout << choose1[i] << " ";
        }
        cout << endl;

        cout << "choose2:" << " ";
        for (int i=0; i<5;i++){
            cout << choose2[i] << " ";
        }
        cout << endl;

        cout << "choice" << " ";
        for (int i=0; i<5;i++){
            cout << choice[i] << " ";
        }
        cout << endl;

        // role
        cout << "status:" << " ";
        cout << status << endl;
        cout << "role1" << " ";
        cout << role1.legend << " " ;
        cout << role1.name << " " ;
        cout << role1.damage << " " ;
        cout << role1.health << " " ;
        cout << role1.defense << " " ;
        cout << role1.gold_coin << " " ;
        cout << role1.weapon << " " ;
        cout << role1.armor << " " ;
        cout << role1.holly_relic << " " << endl;
        for (int i=0; i<3; i++){
            cout << role1.trash_talk[i] << " " << endl;
        }

    return 0;
}
*/
