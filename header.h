#ifndef HEADER_H
#define HEADER_H

#include <string>


// map.cpp
void makepath();
int choosedirection(int nchoose);
void showmap();
extern int choice[5];
extern int num;
extern int status;
extern int choose1[5];
extern int choose2[5];
void drawlRoad(int num);

// fight_rules.cpp
struct role{
    std::string legend;
    std::string name;
    int damage;
    int health;
    int defense;
    int gold_coin;
    std::string weapon;
    std::string armor;
    bool holly_relic;
    std::string trash_talk[3];
};
extern role role1;
role makerole(role &role1);
void display_bag(role role1);
std::string trophies();
void change_proporties(std::string thing);
int fight(role role2);

// gamesave.cpp
void gamesave();
bool loadgame(std::string savename);
std::string choosegame();

// event.cpp
extern std::string continue_road[4];
extern const std::string Dividing_line;
role create_monster();
role create_dragon();
void ShowShop_and_BuyItems();


// Portal.cpp
void Portal(int& num, int& status);
int randomEvent();


#endif
