#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// define constant variables

const int Max_Items_In_Bag = 8;
const int Max_Items_In_Shop = 4;
const int Max_Weapon_In_Equipment = 1;
const int Max_Armor_In_Equipment = 1; // all to be modified

enum itemType {
    Weapon, Armor, Potion,
};

ostream &operator<<(ostream &os, const itemType &item) {
    if (item == Weapon) os << "Weapon";
    else if (item == Armor) os << "Armor";
    else if (item == Potion) os << "Potion";
    return os;
}

istream &operator>>(istream &input, itemType &item) {
    string s;
    input >> s;
    if (s == "Weapon") item = Weapon;
    else if (s == "Armor") item = Armor;
    else if (s == "Potion") item = Potion;
    return input;
}

enum itemRarity {
    Ordinary, Excellent, Epic, Legendary, Myth
};

ostream &operator<<(ostream &os, const itemRarity &item) {
    if (item == Ordinary) os << "Ordinary";
    else if (item == Excellent) os << "Excellent";
    else if (item == Epic) os << "Epic";
    else if (item == Legendary) os << "Legendary";
    else if (item == Myth) os << "Myth";
    return os;
}

istream &operator>>(istream &input, itemRarity &item) {
    string s;
    input >> s;
    if (s == "Ordinary") item = Ordinary;
    else if (s == "Excellent") item = Excellent;
    else if (s == "Epic") item = Epic;
    else if (s == "Legendary") item = Legendary;
    else if (s == "Myth") item = Myth;
    return input;
}

// define Characters

struct Character {
    string name;
    int hp;
    int attack;
    int defense;
    int gold;
    int x;
    int y; //Position on the Map
    vector<string> bag;
    vector<string> equipment;

    /*
    vector<Effect> buff;
    */

    friend ostream &operator<<(ostream &os, const Character &character) {
        os << character.name << " " << character.hp
           << " " << character.attack << " "
           << character.defense << " " << character.gold << " "
           << character.x << " " << character.y;


        os << " " << character.bag.size() << " ";
        for (const auto &i : character.bag) {
            os << i << " ";
        }

        os << character.equipment.size() << " ";
        for (const auto &i : character.equipment) {
            os << i << " ";
        }
        return os;
    }

    friend istream &operator>>(istream &input, Character &item) {
        input >> item.name >> item.hp >> item.attack >> item.defense
              >> item.gold >> item.x >> item.y;
        int size;
        input >> size;
        for (int i = 0; i < size; ++i) {
            string s;
            input >> s;
            item.bag.push_back(s);
        }

        input >> size;
        for (int i = 0; i < size; ++i) {
            string s;
            input >> s;
            item.equipment.push_back(s);
        }

        return input;
    }


};

Character classes[] = {
        // System default classes, e.g. Warrior, Knight, Ranger, Assassin, Archmage...
};
Character enemies[] = {
        // System default Enemies, e.g. Slime, Goblin, Murloc, Undead...
};
Character player; // Player controlled character

// define Items

struct Item {
    string name;
    itemType type;
    itemRarity rarity;
    int value; //Amount of money gained from selling in the shop
    int rounds; // Duration of effect, only for potion
    /*
    Effect; // Effect (buff or debuff) of the Item (to be defined)
    */

    // for write file, if you add field, and the field needed to save, add it
    friend ostream &operator<<(ostream &os, const Item &item) {
        os << item.name << " " << item.type << " " << item.rarity << " "
           << item.value << " " << item.rounds;
        return os;
    }

    friend istream &operator>>(istream &input, Item &item) {
        input >> item.name >> item.type >> item.rarity >> item.value
              >> item.rounds;
        return input;
    }

};

//define Map
struct Map{
    
};

// define random events

class Event{
public:
    int eventCoder;
    string name;
    string desoription;
    /*
    void showEvent(){
    };
    ...
    */
};

Event randomEvent[] ={
    
};
