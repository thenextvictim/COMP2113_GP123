#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <math.h>
#include <cstdlib>
using namespace std;

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
    string trash_talk;
};

int display_bag(role role1){
      ifstream fin;
      fin.open("ROLE");
      cout << role1.legend << " " << role1.name << endl; 
      cout << "Damage: " << role1.demage << ", " << "Health: " << role1.health << ", " << "Defense: " << role1.defense << ", " << "Gold coin: " << role1.gold_coin << endl;
      cout << "Weapon: " << role1.weapon << ", " << "Armor: " << role1.armor << ", " << "Holly relic: " << role1.holly_relic << "." << endl; 
      fin.close();
}

int fight(role role1, role role2, int &exit){
        int round=1;
        int fight_health1= role1.health;
        int fight_health2= role2.health;
        // legend attacks first
        cout << role1.legend << " " << role1.name << ": " << "/"" << role1.trash_talk << "/"" << endl;
        cout << role2.legend << ": " << "/"" << role2.trash_talk << "/"" << endl;
        while (fight_health1 >0 && fight_health2 >0){
        // every round we have random fixed damage for two roles.
        int fixed_damage1= rand()%((role1.damage+2)-(role1.damage-2)+1))+(role1.damage-2);
        int fixed_damage2= rand()%((role2.damage+2)-(role2.damage-2)+1))+(role2.damage-2);
        cout << "Round" << round << ": " << endl;
        role1.legend << " " << role1.name << " attacks " << role2.legend << " and make a hurt of -";
        if ( fixed_damage1 - role2.defense >=0 ){
            fight_health2 = fight_health2- (fixed_damage1 - role2.defense)
            if (fight_health2 <=0){
                fight_health2 = 0;
            }
            cout << fixed_damage1 - role2.defense << cout << " (" << fight_health2 << "/" << role2.health << ")." << endl;
        }
        else{
            cout << "0" << cout << " (" << fight_health2 << "/" << role2.health << ")." << endl;
        }
        // monster attacks then
        cout << role2.legend << " attacks " << role1.legend << " " << role1.name << " and make a hurt of -";
        if ( fixed_damage2 - role1.defense >=0 ){
            fight_health1 = fight_health1- (fixed_damage2 - role1.defense)
            if (fight_health1 <=0){
                fight_health1 = 0;
            }
            cout << fixed_damage2 - role1.defense << cout << " (" << fight_health1 << "/" << role1.health << ")." << endl;
        }
        else{
            cout << "0" << cout << " (" << fight_health1 << "/" << role1.health << ")." << endl;
        }
        //round is over
        round++;

        if (fight_health1 == 0 ){
            cout << "You are defeated. You die."
            exit = 1;
        }
        else{
            cout << role2.legend << " dies." <<  " You win." << endl;
            int get = rand()%((7)-(3)+1))+3;
            cout << "You get " << get << "G"
            exit = 0;
        }
        return exit;
        // fight is all over
}
