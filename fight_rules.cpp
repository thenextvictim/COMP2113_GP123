#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <math.h>
#include <cstdlib>
#include <unistd.h>
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
    string trash_talk[3];
};

role makerole(role &role1){
    cout << "Please choose your legend. Input 1 if you can to be a Human Warrior, 2 if Elf Magician, 3 if Giant Tank." << endl;
    int a;
    cin >> a;
    while (a != 1 && a != 2 && a != 3 ){
        cout << "Error. Please input a correct number." << endl;
        cin >> a;
    }
    if (a == 1){
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
    }
    else if (a == 2){
        role1.legend = "Elf magician";
        role1.damage = 30;
        role1.health = 70;
        role1.defense = 5;
        role1.gold_coin = 20;
        role1.weapon = "Nothing";
        role1.armor = "Nothing";
        role1.holly_relic = false;
        role1.trash_talk[0] = "Elegance is never out of date~";
        //"生命生而平等，但是精灵们更平等一些。"
        role1.trash_talk[1] = "Life is born equal, but elves are more equal.";
        //“魔法的意义就是区分凡人和天才。”
        role1.trash_talk[2] = "The meaning of magic is to distinguish between mortals and geniuses.";
    }
    else if (a == 3){
        role1.legend = "Giant tank";
        role1.damage = 10;
        role1.health = 150;
        role1.defense = 20;
        role1.gold_coin = 5;
        role1.weapon = "Nothing";
        role1.armor = "Nothing";
        role1.holly_relic = false;
        role1.trash_talk[0] = "No one can stand on the shoulders of giants！";
        //"言语上是巨人，行动上还是巨人。"
        role1.trash_talk[1] = "A giant in speech, a giant in action as well.";
        //“势不可挡。”
        role1.trash_talk[2] = "I am unstoppable.";
    }
    cout << "Now please tell your name, brave legend." << endl;
    string name;
    cin >> name;
    role1.name = name;
    return role1;
}

void display_bag(role role1){
      cout << "\033[32m-------------------------------------------------------------------\033[0m" << endl:
      cout << role1.legend << " " << role1.name << endl; 
      cout << "\033[31mDamagem: \033[0m" << role1.damage << ", " << "\033[32mHealth: \033[0m" << role1.health << ", " << "\033[34mDefense: \033[0m" << role1.defense << ", " << "\033[33mGold coin: \033[0m" << role1.gold_coin << endl;
      cout << "\033[31mWeapon: \033[0m" << role1.weapon << ", " << "\033[34mArmor: \033[0m" << role1.armor << ", " << "\033[37mHolly relic: \033[0m" << role1.holly_relic << "." << endl; 
      cout << "\033[32m-------------------------------------------------------------------\033[0m" << endl:
}

string trophies(){
    int k= rand()% 9 ;
    switch(k){
        case 0:
        return "Long sword";
        break;
        case 1:
        return "Flintlock";
        break;
        case 2:
        return "Magical stick";
        break;
        case 3:
        return "Huge axe";
        break;
        case 4:
        return "God-bless armor";
        break;
        case 5:
        return "Standard armor";
        break;
        case 6:
        return "Magic armor";
        break  ; 
        case 7:
        return "Giant armor";
        break;
        case 8:
        return "Holly_relic";
        break;
        default:
        return "Error";
    }

}

void change_proporties(role role1, string thing){
    if (thing=="Long sword"){
        if (role1.weapon != "Nothing"){
            cout << "You dropped " << role1.weapon << "and you lose it forever.";
            }
        role1.weapon = "Long sword";
        role1.damage = role1.damage+5;
    // Long sword: +5 damage, every legend can use.
        cout << "You equiped \"Long sword\" and your damage grows +5!" << endl;
    }
    else if (thing=="Flintlock" && role1.legend == "Human warrior"){
        if (role1.weapon != "Nothing"){
            cout << "You dropped " << role1.weapon << "and you lose it forever.";
            }
        role1.weapon = "Flintlock";
        role1.damage = role1.damage+8;
    // Flintlock: +8 damage, only can be used by human warrior.
        cout << "You equiped \"Flintlock\" and your damage grows +8!" << endl;
    }
    else if (thing=="Magical stick" && role1.legend == "Elf magician"){
        if (role1.weapon != "Nothing"){
            cout << "You dropped " << role1.weapon << "and you lose it forever.";
            }
        role1.weapon = "Magical stick";
        role1.damage = role1.damage+10;
    // Magical stick: +10 damage, only can be used by elf magician.
        cout << "You equiped \"Magical stick\" and your damage grows +10!" << endl;
    }
     else if (thing=="Huge axe" && role1.legend == "Giant tank"){
        if (role1.weapon != "Nothing"){
            cout << "You dropped " << role1.weapon << "and you lose it forever.";
            }
        role1.weapon = "Huge axe";
        role1.damage = role1.damage+5;
    // Huge axe： +5 damage， only can be used by giant tank.
        cout << "You equiped \"Huge axe\" and your damage grows +5!" << endl;
    }
      else if (thing=="God-bless armor" ){
        if (role1.armor != "Nothing"){
            cout << "You dropped " << role1.armor << "and you lose it forever.";
            }
        role1.armor = "God-bless armor";
        role1.defense = role1.defense+5;
    // God-bless armor: +5 defense, every legend can use.
        cout << "You equiped \"God-bless armor\" and your defense grows +5!" << endl;
    }
        else if (thing=="Standard armor" && role1.legend == "Human warrior"){
        if (role1.armor != "Nothing"){
            cout << "You dropped " << role1.armor << "and you lose it forever.";
            }
        role1.armor = "Standard armor";
        role1.defense = role1.defense+8;
    // Standard armor: +8 defense, only can be used by human warrior.
        cout << "You equiped \"Standard armor\" and your defense grows +8!" << endl;
    }
        else if (thing=="Magic armor" && role1.legend == "Elf magician" ){
        if (role1.armor != "Nothing"){
            cout << "You dropped " << role1.armor << "and you lose it forever.";
            }
        role1.armor = "Magic armor";
        role1.defense = role1.defense +5;
    // Magic armor： +5 defense, only can be used by elf magician.
        cout << "You equiped \"Magic armor\" and your defense grows +5!" << endl;
    }
        else if (thing=="Giant armor" && role1.legend == "Giant tank" ){
        if (role1.armor != "Nothing"){
            cout << "You dropped " << role1.armor << "and you lose it forever.";
            }
        role1.armor = "Giant armor";
        role1.defense = role1.defense +10;
    // Giant armor: +10 defense, only can be uesd by giant tank.
        cout << "You equiped \"Giant armor\" and your defense grows +10!" << endl;
    }
        else if (thing=="Damage potion" ){
        role1.damage = role1.damage+5;
    // damage potion：+5 damage, every legend can drink.
        cout << "You drank \"Damage potion\" and your damage grows +5!" << endl;
    
}
        else if (thing=="Defense potion" ){
        role1.defense = role1.defense+5;
    //  defense potion: +5 defense, every legend can drink.
        cout << "You drank \"Defense potion\" and your defense grows +5!" << endl;
    
}
        else if (thing=="Health potion" ){
        role1.health = role1.defense*1.2;
    //  health potion: +20%HP， every legend can drink.
        cout << "You drank \"Health potion\" and your health grows +20%!" << endl;
    
}
        else if (thing=="Holly relic" ){
        role1.holly_relic = true;
    //  Only works when facing the boss--Prince of the Devils, a legend can choose to use or not to use before the final battle.
    //  If used, then both legend and boss will be deducted 50% of HP.
    //  Else, nothing happens and final battle will start.
        cout << "You obtain the power of Holly relic and you feel it will help a lot when you face the Prince of the Devils." << endl;    
}
        else{
        cout << "You can not use it. Maybe other legends can make use of it." << endl;
        cout << "You dropped it in case you load too much." << endl;
        }
}

int fight(role role1, role role2){
        int e; //exit game or not
        int round=1;
        int fight_health1= role1.health;
        int fight_health2= role2.health;
        if (role2.legend == "Black_Dragon" && role1.holly_relic == true){ 
            cout << "It is a Huge Black_Dragon with fatal power. However, you strangely assume that it doesn't want to attack you." << endl;
            cout << "Anyway, you have to win and get through this maze back home, right? So you still take your weapon and ready for the final battle." << endl;
            cout << "The Holly relic in your bag suddenly turn warm and you surprisingly find that it flies out and attacks the dargon!" << endl;
            cout << "The Black Dragon roars in pain. You find that its power seems to be lower and come to a mind that it is the time!!!" << endl;
            fight_health2= fight_health2/2;
            role1.holly_relic = false;
            sleep(1);
        }
        else if (role2.legend == "Black_Dragon" && role1.holly_relic == true){ 
            cout << "It is a Huge Black_Dragon with fatal power. However, you strangely assume that it doesn't want to attack you." << endl;
            cout << "Anyway, you have to win and get through this maze back home, right? So you still take your weapon and ready for the final battle." << endl;
            sleep(1);
        }
        // legend attacks first
        int i, j;
        i= rand()% 3 ;
        j= rand()% 3 ;
        cout << role1.legend << " " << role1.name << ": " << "\"" << role1.trash_talk[i] << "\"" << endl;
        cout << role2.legend << ": " << "\"" << role2.trash_talk[j] << "\"" << endl;
        //Since our standard compile environment is in Linux, here we use the sleep function by adding <unistd.h> and e.g. sleep(1) states that the programme will stop for 1 seconds.
        sleep(1);
        while (fight_health1 >0 && fight_health2 >0){
            // every round we have random fixed damage for two roles.
            int fixed_damage1= rand()%((role1.damage+2)-(role1.damage-2)+1)+(role1.damage-2);
            int fixed_damage2= rand()%((role2.damage+2)-(role2.damage-2)+1)+(role2.damage-2);
            cout << "Round " << round << ": " << endl;
            cout << role1.legend << " " << role1.name << " attacks " << role2.legend << " and make a hurt of -";
            if ( fixed_damage1 - role2.defense >=0 ){
                fight_health2 = fight_health2- (fixed_damage1 - role2.defense);
                if (fight_health2 <=0){
                    fight_health2 = 0;
                    }
                cout << (fixed_damage1 - role2.defense) << " (" << fight_health2 << "/" << role2.health << ")." << endl;
            }
            else{
                cout << "0" << " (" << fight_health2 << "/" << role2.health << ")." << endl;
            }
            if (fight_health2 == 0){
                cout << role2.legend << " dies." <<  " You win." << endl;
                break;
            }
            // monster attacks then
            cout << role2.legend << " attacks " << role1.legend << " " << role1.name << " and make a hurt of -";
            if ( fixed_damage2 - role1.defense >=0 ){
                fight_health1 = fight_health1- (fixed_damage2 - role1.defense);
                if (fight_health1 <=0){
                    fight_health1 = 0;
                }
                cout << (fixed_damage2 - role1.defense) << " (" << fight_health1 << "/" << role1.health << ")." << endl;
            }
            else{
                cout << "0" << " (" << fight_health1 << "/" << role1.health << ")." << endl;
            }
            if (fight_health1 == 0 ){
                cout << "You are defeated. You die.";
                e = 1;
                break;
            }
            //round is over
            round++;
            //Since our standard compile environment is in Linux, here we use the sleep function by adding <unistd.h> and sleep(1) states that the programme will stop for 1 seconds.
            sleep(1);
        }
        if (role2.legend == "Black_Dragon"){
                cout << "Though it is dead, Black_Dragon's eyes are still stareing at you, like saying something......" << endl;
                e = 0;
            }
        else{
            int get = rand()%((7)-(3)+1)+3;
            string thing = trophies();
            cout << "You get " << get << " gold coins, and a " << thing << " ." << endl;
            role1.gold_coin = role1.gold_coin + get;
            // Choose to equip the new spoil or not
            cout << "Do you want to equip " << thing << " or not?" << " IF yes, please enter 1. If no, please enter 0." << endl;
            int a;
            cin >> a;
            while (a != 0 && a != 1){
                cout << "Error. Please input a correct number." << endl;
                cin >> a;
            }
            if (a == 1){
            change_proporties(role1,thing);
            cout << "You are going on your journey with a happy mood:)." << endl;
            }
            else{
            cout << "You are going on your journey with a soso mood:|." << endl;    
            }
            e = 0;
        }
        
        // fight is all over, if exit = 0, game continue, else, game over
            return e;
    }

