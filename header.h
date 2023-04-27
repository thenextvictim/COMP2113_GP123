#ifndef HEADER_H
#define HEADER_H

#include <string>


// map.cpp
void makepath();
int choosedirection(int nchoose);
void map(int place);
void showmap();

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
role makerole(role &role1);
void display_bag(role role1);
std::string trophies();
void change_proporties(role role1, std::string thing);
int fight(role role1, role role2);

// gamesave.cpp
// :'(

// monster_shop.cpp
struct monster {
	std::string name;
	int HP;
	int attack;
	int defense;
	int gold;
};
struct shop_item {
	std::string description;
	int price;
};

extern monster Louse;
extern monster Cultist;
extern monster Looter;
extern monster Gremlin_Nob;
extern monster Bronze_Automation;
extern shop_item Blood_potion;
extern shop_item Attack_potion;
extern shop_item Earth_potion;
extern shop_item Thorn_potion;
extern shop_item shop_item_potion_arr[4];
extern shop_item Toy_Ornithopter;
extern shop_item Red_skull;
extern shop_item Shuriken;
extern shop_item Anchor;
extern shop_item shop_item_relic_arr[4];

void ShowShop_and_BuyItems(int HP,int attack,int defense,int gold);


// Portal.cpp
extern const std::string Dividing_line = "-------------------------------------------------------------------\n";

void Portal(int choose[][2], int position[2]);
void randomEvent();


#endif