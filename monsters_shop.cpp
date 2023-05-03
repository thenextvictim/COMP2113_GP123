#include<iostream>
#include<string>
#include<time.h>
using namespace std;

struct monster {                     // define monster struct
	string name;
	int HP;
	int attack;
	int defense;
	int gold;
};

struct shop_item {           // define potions and relics in shop
	string name;
	string description;
	int price;
};

monster Louse = { "Louse",50,25,5,10 };
monster Cultist = { "Cultist",70,35,10,25 };
monster Looter = { "Looter",60,30,5,25 };        // the looter will steal the legend's gold coins whennver it attacks. Returns back all the gold if it is defeated. Achievable???
monster Gremlin_Nob = { "Gremlin Nob",100,35,20,45 };
monster Bronze_Automation = { "Bronze Automation",200,55,35,0 };      // the boss

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



