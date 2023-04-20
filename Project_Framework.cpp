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

enum itemType {Weapon, Armor, Potion};
enum itemRarity {Ordinary, Excellent, Epic, Legendary, Myth};

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
};

Character classes[ ] = {
    // System default classes, e.g. Warrior, Knight, Ranger, Assassin, Archmage...
};
Character enemies[ ] = {
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
};

// define Map
struct Map {

};

// define random events

class Event {
    public:
        int eventCode;
        string name;
        string description;
        /*   
        void showEvent(){

        };
        ...
        */
};

Event randomEvent[ ] = {

};

// define shop

struct Shop {
    vector<string> items; 
};

// define Functions

string handleCommand(string command);

void showMainMenu();

void showCharacterSelection();

Character createCharacter(string name, int hp, int attack, int defense, int gold);

void showInterface(Character character);

void showMap(Map map, Character character);

void moveCharacter(Character& character, Map& map, string direction);

void showBag(Character character);

void usePotion(Item& potion, Character& character);

void showEquipment(Character character);

void equipItem(Item& item, Character& character);

void unequipItem(Item& item, Character& character);

void showShop(Shop shop, Character& character);

void buyItem(Item item, Character& character);

void exchangeItem(Item item, Charachter& Character, vector<Item> item_On_Ground); // When player gets one or more items when bag is full

void showEvent(Event event, Character& character);

void handleEvent(Event event, Character& character);

void showBattle(Character& character, Character enemy);

void handleBattle(Character& character, Character enemy);

bool isDead(Character character); //return true if (character.hp <= 0)

void showEnding(Character character, Map map, Shop shop); //Show the ending plot, show the summary of this game, delete the game data

void saveGame(Character character, Map map, Shop shop, string filename);

void loadGame(Character& character, Map& map, Shop& shop, string fliename);


void generateMap(Map& map);

void generateShop(Shop& shop); //Also refresh shop

void generateEvent(Event& event);
