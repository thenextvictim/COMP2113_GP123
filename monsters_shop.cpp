#include<iostream>
#include<string>
#include<time.h>
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

struct shop_item {           // define potions and relics in shop
	string name;
	string description;
	int price;
};

role create_monster(){
int k= rand()% 6 ;
if (k == 1){
	role Louse;
	Louse.legend = "Louse";
        Louse.damage = 30;
        Louse.health = 50;
        Louse.defense = 5;
        Louse.weapon = "Nothing";
        Louse.armor = "Nothing";
        Louse.holly_relic = false;
        Louse.trash_talk[0] = "Whhhhhh~~~";
        role1.trash_talk[1] = "Ohhhhhh~~~";
        role1.trash_talk[2] = "Ehhhhhh~~~";
	return Louse;
    }
else if (k == 2){
	role Cultist;
	Cultist.legend = "Cultist";
        Cultist.damage = 50;
        Cultist.health = 50;
        Cultist.defense = 0;
        Cultist.weapon = "Nothing";
        Cultist.armor = "Nothing";
        Cultist.holly_relic = false;
        Cultist.trash_talk[0] = "Behold, mortals!";
        Cultist.trash_talk[1] = "I am the master of dark magic, a conjurer of chaos, and a weaver of nightmares.";
        Cultist.trash_talk[2] = "Give me you soul and then you can go on your journey to the devil.";
	return Cultist;
    }
else if (k == 3){
	role Looter;
	Looter.legend = "Looter";
        Looter.damage = 50;
        Looter.health = 50;
        Looter.defense = 0;
        Looter.weapon = "Nothing";
        Looter.armor = "Nothing";
        Looter.holly_relic = false;
        Looter.trash_talk[0] = "Suuuuuu~~";
        Looter.trash_talk[1] = "Saaaaaa~~";
        Looter.trash_talk[2] = "Kuuuuuu~~";
	return Looter;
    }
else if (k == 4){
	role Gremlin_Nob;
	Gremlin_Nob.legend = "Looter";
        Gremlin_Nob.damage = 50;
        Gremlin_Nob.health = 50;
        Gremlin_Nob.defense = 0;
        Gremlin_Nob.weapon = "Nothing";
        Gremlin_Nob.armor = "Nothing";
        Gremlin_Nob.holly_relic = false;
        Gremlin_Nob.trash_talk[0] = "Hmmmmmm~~";
        Gremlin_Nob.trash_talk[1] = "Wahhhhh~~";
        Gremlin_Nob.trash_talk[2] = "Lhhhhhh~~";
	return Gremlin_Nob;
    }
else if (k == 5){
	role role2;
	role2.legend = "Bronze_Automation";
        role2.damage = 13;
        role2.health = 200;
        role2.defense = 12;
        role2.weapon = "Nothing";
        role2.armor = "Nothing";
        role2.holly_relic = false;
        role2.trash_talk[0] = "I am a bronze puppet, created to serve and obey. my metal shell may be cold, but my loyalty burns hot.";
        role2.trash_talk[1] = "My movements may be stiff, but my determination is unwavering. i will fulfill my programming until the end.";
        role2.trash_talk[2] = "My bronze body may be fragile, but i am powered by an unbreakable will.";
	return role2;
    }
    else if (k == 0){
            role role2;
	    role2.legend = "Forest_wolf";
	    role2.damage = 15;
	    role2.health = 60;
	    role2.defense = 5;
	    role2.gold_coin = 0;
	    role2.weapon = "";
	    role2.armor = "";
	    role2.holly_relic = false;
	    role2.trash_talk[0] = "Bow-bow~";
	    role2.trash_talk[1] = "Wang-Wang~";
	    role2.trash_talk[2] = "Ouuuuuuuu~~~";
	    return role2;
    }
}

role create_dragon(){
	role Black_Dragon;
	Black_Dragon.legend = "Black_Dragon"
	Black_Dragon.damage = 13;
        Black_Dragon.health = 200;
        Black_Dragon.defense = 12;
        Black_Dragon.weapon = "Nothing";
        Black_Dragon.armor = "Nothing";
        Black_Dragon.holly_relic = false;
        Black_Dragonn.trash_talk[0] = "You're the me from the past, and i'm the you from the future.";
        Black_Dragon.trash_talk[1] = "Your life is a drama, and it’s finally time for the curtain to fall."
        Black_Dragon.trash_talk[2] = "Why me here? Why you here?";
	return Black_Dragon;
    }


shop_item Blood_potion = { "Blood potion","Raise your max HP by 20" ,40 };
shop_item Attack_potion = { "Attack potion","Raise your strength by 5",30 };
shop_item Earth_potion = { "Earth potion","Raise your defense value by 5",40 };
shop_item Thorn_potion = { "Thorn potion","Obtain 10 blocks in your next battle",40 };
shop_item shop_item_potion_arr[4] = { Blood_potion ,Blood_potion ,Earth_potion ,Thorn_potion };     // four potions

shop_item Long_sword = { "Long sword","Raise your strength by 5.",50 };
shop_item Flintlock = { "Flintlock","Raise your strength by 8",70};
shop_item Magical_stick = { "Magical stick","Raise your strength by 10",90};
shop_item Huge_axe = { "Huge axe","Rsie your strength by 5", 50};
shop_item shop_item_weapon_arr[4] = {Long_sword, Flintlock, Magical_stick, Huge_axe};

shop_item God_bless_armor = {"God-bless armor", "Raise your defense by 5",50};
shop_item Standard_armor = {"Standard armor", "Raise your defense by 8",80};
shop_item Magic_armor = {"Magic armor", "Raise your defense by 5", 50};
shop_item Giant_armor = {"Giant armor", "Raise your defense by 10, 100};
shop_item shop_item_armor[4] = {God_bless_armor, Standard_armor, Magic_armor, giant_armor};

void ShowShop_and_BuyItems(int HP,int attack,int defense,int gold) {
	cout << "You encounter a sneaky and greedy gremlin merchant in a muddy cave. 'Give me the gold, and I'll give you the goods!', he says."<<endl;
	shop_item potion, weapon, armor;
	int choice, m = 0, n;
	bool buy_items = true;
	srand(time(NULL));
	int index_potion = rand() % 4;
	int index_weapon = rand() % 4;
	int index_armor = rand() % 4;
	potion = shop_item_potion_arr[index_potion];
	weapon = shop_item_weapon_arr[index_weapon];
	armor = shop_item_armor_arr[index_armor];

	cout << potion.name << "  ";
	cout << potion.description << "  ";
	cout << "$" << potion.price << endl;
	
	cout << weapon.name << "  ";
	cout << weapon.description << "  ";
	cout << "$" << weapon.price << endl;

	cout << armor.name << "  ";
	cout << armor.description << "  ";
	cout << "$" << armor.price << endl;
      // show four items, two potions and two relics in each shop.

	shop_item shop_item_arr[3]= { potion, weapon, armor};
	int bought_items[3] = {};
	cout << "Choose your preferred items! Enter number 1-3 for the products and 0 for exiting.";
	while (buy_items) {
		bool check1 = true, check2 = true;
		cin >> choice;
		if (choice == 0) {
			cout << "'Good luck.',said the gremlin and fades away in the cave.";
			buy_items = false;
		}
		else {
			for (n = 0; n < m; n++) {
				if (bought_items[n] == choice) {                                  // check whether the item is bought
					cout << "The item is sold out! Choose another one !";
					check1= false;
					break;
				}
			}
			if (gold < shop_item_arr[choice].price) {                             // check whether the player has enough gold
				cout << "'stop bothering me if don't have enough gold',said the gremlin";
				check2 = false;
			}
			if (check1 && check2 && choice==1){
				if (shop_item_arr[choice].name == Blood_potion.name) {
					HP += 20;
					gold -= 40;
				}
				if (shop_item_arr[choice].name == Attack_potion.name) {
					attack += 5;
					gold -= 30;
				}
				if (shop_item_arr[choice].name == Earth_potion.name) {
					defense += 5;
					gold -= 40;
				}
				if (shop_item_arr[choice].name == Thorn_potion.name) {
					//block-=10 ？
					gold -= 40;
				}
			}
			if (check1 && check2 && choice == 2) {
				if (shop_item_arr[choice].name == (Long_sword.name) {
					attack+=5;
					gold -= 50;
				}
				if (shop_item_arr[choice].name == (Flintlock.name) {
					attack += 8;
					gold -= 70;
				}
				if (shop_item_arr[choice].name == (Magic_stick.name) {
					attack += 10;
					gold -= 90;
				}
				if (shop_item_arr[choice].name == (Huge_axe.name) {
					attack += 5;
					gold -= 50;
				}
			}
			if (check1 && check2 && choice == 3) {
				if (shop_item_arr[choice].name == (God_bless_armor.name) {
					defense += 5;
					gold -= 50;
				}
				if (shop_item_arr[choice].name == (Standard_armor.name) {
					attack += 8;
					gold -= 80;
				}
				if (shop_item_arr[choice].name == (Magic_armor.name) {
					defense += 5;
					gold -= 50;
				}
				if (shop_item_arr[choice].name == (Giant_armor.name) {
					defense+=10;
					gold -= 100;
				}
			}
		}
		bought_items[m] = choice;
		m++;
	}
}



