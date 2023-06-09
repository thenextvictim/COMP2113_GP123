#include<iostream>
#include<string>
#include<time.h>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "header.h"
using namespace std;

// randomly select and creat a monster, then return the monster.
role create_monster(){
    role role_null;
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
        Louse.trash_talk[1] = "Ohhhhhh~~~";
        Louse.trash_talk[2] = "Ehhhhhh~~~";
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
        Looter.damage = 20;
        Looter.health = 150;
        Looter.defense = 5;
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
        Gremlin_Nob.legend = "Gremlin Nob";
        Gremlin_Nob.damage = 18;
        Gremlin_Nob.health = 120;
        Gremlin_Nob.defense = 12;
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
        role2.legend = "Bronze Automation";
        role2.damage = 13;
        role2.health = 200;
        role2.defense = 8;
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
	    role2.legend = "Forest wolf";
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
    return role_null;
}

// create and return the final boss
role create_dragon(){
	role Black_Dragon;
	Black_Dragon.legend = "Black_Dragon";
	Black_Dragon.damage = 25;
        Black_Dragon.health = 200;
        Black_Dragon.defense = 15;
        Black_Dragon.weapon = "Nothing";
        Black_Dragon.armor = "Nothing";
        Black_Dragon.holly_relic = false;
        Black_Dragon.trash_talk[0] = "You're the me from the past, and i'm the you from the future.";
        Black_Dragon.trash_talk[1] = "Your life is a drama, and it is finally time for the curtain to fall.";
        Black_Dragon.trash_talk[2] = "Why me here? Why you here?";
	return Black_Dragon;
}

// creat and return monster "Mimic" (appears in random event Treasure_chest).
role create_Mimic(){
	role Mimic;
	Mimic.legend = "Mimic";
	Mimic.damage = 20;
    Mimic.health = 100;
    Mimic.defense = 5;
    Mimic.weapon = "Nothing";
    Mimic.armor = "Nothing";
    Mimic.holly_relic = false;
    Mimic.trash_talk[0] = "This is your last treasure hunt.";
    Mimic.trash_talk[1] = "*Mimic Groans* \"You've awoken me from my slumber...\"";
    Mimic.trash_talk[2] = "*Mimic Laughs* \"Foolish adventurer...you fell right into my trap!\"";
	return Mimic;
}

// define the struct of items in shop
struct shop_item {
    string name;
    string description;
    int price;
};

// Initialization of all the items is shop
shop_item Blood_potion = { "Blood potion","Raise your max HP by 20" ,40 };
shop_item Attack_potion = { "Attack potion","Raise your strength by 5",30 };
shop_item Earth_potion = { "Earth potion","Raise your defense value by 5",40 };
shop_item shop_item_potion_arr[3] = { Blood_potion ,Blood_potion ,Earth_potion};     // four potions

shop_item Long_sword = { "Long sword","Raise your strength by 5.",50 };
shop_item Flintlock = { "Flintlock","Raise your strength by 8",70};
shop_item Magical_stick = { "Magical stick","Raise your strength by 10",90};
shop_item Huge_axe = { "Huge axe","Raise your strength by 5", 50};
shop_item shop_item_weapon_arr[4] = {Long_sword, Flintlock, Magical_stick, Huge_axe};

shop_item God_bless_armor = {"God-bless armor", "Raise your defense by 5",50};
shop_item Standard_armor = {"Standard armor", "Raise your defense by 8",80};
shop_item Magic_armor = {"Magic armor", "Raise your defense by 5", 50};
shop_item Giant_armor = {"Giant armor", "Raise your defense by 10", 100};
shop_item shop_item_armor_arr[4] = {God_bless_armor, Standard_armor, Magic_armor, Giant_armor};

// random conversation when player buy an item from shop
string buy_item_shop[] = {
    "\"May the blessings of the ancients guide you on your journey, adventurer. Thank you for your patronage!\"",
    "\"The winds of fortune favor thee, warrior.\"",
    "\"May the virtues of our shop stay with you as you journey on.\"",
    "\"The embrace of magic will surround those who purchase from us.\""
};

// random conversation when player try to buy an item that is sold out in shop
string sold_out_shop[] = {
    "The gremlin raises an eyebrow at you. \"Sorry, we don't have that item in stock. Can I help you find something else?\"",
    "The gremlin glances at the empty space on the shelf where that item used to be. \"Sorry, we're sold out right now. Can i interest you in something else?\"",
    "\"I'm sorry adventurer. It seems this item is no longer available for purchase.\", said the germlin."
};

// random System prompt when player input an invalid command in shop
string invalid_input_shop[] = {
    "The magic of the shop seems to be refusing that input. Perhaps there's another way you can achieve your goal?",
    "That choice does not resonate with the magical energies of this shop. Can you ask again in a different way?",
    "The arcane secrets of this shop hum with power, but that input is not unlocking them. Can you try again?",
    "The shadows within this store twist and turn, refusing to heed that request. Perhaps there's another path you can take?"
};
// Function used to generate items in shop and handle player's purchases.
void ShowShop_and_BuyItems() {
	cout << "You encounter a sneaky and greedy gremlin merchant in a muddy cave. \"Give me the gold, and I'll give you the goods!\", he says."<<endl;
	shop_item potion, weapon, armor;
	int choice_int, m = 0, n;
	bool buy_items = true;
    string choice, thing;
	srand(time(NULL));
	int index_potion = rand() % 3;
	int index_weapon = rand() % 4;
	int index_armor = rand() % 4;
	potion = shop_item_potion_arr[index_potion];
	weapon = shop_item_weapon_arr[index_weapon];
	armor = shop_item_armor_arr[index_armor];
    shop_item shop_item_arr[3]= {potion, weapon, armor};
	
    // show all the items in shop, also show its price and description 
    cout << "\033[32m-------------------------------------------------------------------\033[0m" << endl;
    for (int i=0; i<3; i++){
        cout << left;
        cout << "\033[1;34m" << setw(15) << shop_item_arr[i].name << "\033[0m";
        cout << right;
        cout << setw(8)  << "\033[33mG"  << shop_item_arr[i].price << "\033[0m" << endl;
        cout << shop_item_arr[i].description << endl;
    }
    cout << "\033[32m-------------------------------------------------------------------\033[0m" << endl;
      // show 3 items,1 potions and 1 armor and 1 weapon in each shop.
	
	int bought_items[3] = {};
	//Record the items purchased by the player, the player tries to buy the purchased items will show sold out
	
	cout << "Choose your preferred items! Enter number 1-3 for the products and 0 for exiting." << endl;
	while (buy_items) {
	// show player's gold
        cout << setw(30) << right << "Your gold : " << "\033[33mG" << role1.gold_coin << "\033[0m" << endl;
		//check1 used to check if item is sold out. check2 used to check if player has enough gold to buy this item
		bool check1 = true, check2 = true;
		// read player's command
		cin >> choice;
		
		// input "0" if players leave the shop
		if (choice == "0") {
			cout << "\"Good luck.\"" << ",said the gremlin and fades away in the cave." << endl;
			buy_items = false;
		}
		else if (choice == "1" || choice == "2" || choice == "3"){
            	choice_int = stoi(choice);
			// check whether the item is bought
			for (n = 0; n < m; n++) {
				if (bought_items[n] == choice_int) {
					cout << sold_out_shop[rand()%(sizeof(sold_out_shop)/sizeof(sold_out_shop[0]))] << endl;
					check1= false;
					break;
				}
			}
			// check whether the player has enough gold
			if ((role1.gold_coin < shop_item_arr[choice_int-1].price) && (check1 == true)) {
				cout << "\"Stop bothering me if don't have enough gold.\",said the gremlin" << endl;
				check2 = false;
			}
			if (check1 && check2 && choice_int==1){
				if (shop_item_arr[choice_int-1].name == Blood_potion.name) {
					role1.health += 20;
					role1.gold_coin -= 40;
				}
				if (shop_item_arr[choice_int-1].name == Attack_potion.name) {
					role1.damage += 5;
					role1.gold_coin -= 30;
				}
				if (shop_item_arr[choice_int-1].name == Earth_potion.name) {
					role1.defense += 5;
					role1.gold_coin -= 40;
				}
				cout<< buy_item_shop[rand()%(sizeof(buy_item_shop)/sizeof(buy_item_shop[0]))] << ", said the gremlin." << endl;
                	bought_items[m] = choice_int;
		        m++;
			}
			else if (check1 && check2 && choice_int == 2) {
				if (shop_item_arr[choice_int-1].name == (Long_sword.name)) {
					thing="Long sword";
					change_proporties(thing);
				}
				else if (shop_item_arr[choice_int-1].name == (Flintlock.name)) {
					thing="Flintlock";
					change_proporties(thing);
				}
				else if (shop_item_arr[choice_int-1].name == (Magical_stick.name)) {
					thing="Magical stick";
					change_proporties(thing);
				}
				else if (shop_item_arr[choice_int-1].name == (Huge_axe.name)) {
					thing="Huge axe";
					change_proporties(thing);
				}
			role1.gold_coin -= shop_item_arr[choice_int-1].price;
                	cout<< buy_item_shop[rand()%(sizeof(buy_item_shop)/sizeof(buy_item_shop[0]))] << ", said the gremlin." << endl;
                	bought_items[m] = choice_int;
		        m++;
			}
			else if (check1 && check2 && choice_int == 3) {
				if (shop_item_arr[choice_int-1].name == (God_bless_armor.name)) {
					thing="God-bless armor";
					change_proporties(thing);
				}
				else if (shop_item_arr[choice_int-1].name == (Standard_armor.name)) {
					thing="Standard armor";
					change_proporties(thing);
				}
				else if (shop_item_arr[choice_int-1].name == (Magic_armor.name)) {
					thing="Magic armor";
					change_proporties(thing);
				}
				else if (shop_item_arr[choice_int-1].name == (Giant_armor.name)) {
					thing="Giant armor";
					change_proporties(thing);
				}
				role1.gold_coin -= shop_item_arr[choice_int-1].price;
                cout<< buy_item_shop[rand()%(sizeof(buy_item_shop)/sizeof(buy_item_shop[0]))] << ", said the gremlin." << endl;
                bought_items[m] = choice_int;
		        m++;
			}
		}
        else {
            cout << invalid_input_shop[rand()%(sizeof(invalid_input_shop)/sizeof(invalid_input_shop[0]))] << endl;
	    // handle invaild command
        }
	}
}



// used to divide text and options
const string Dividing_line = "-------------------------------------------------------------------\n";

// random System prompt when player input an invalid command in event
string invalid_input_1[8]= {
    "You try to do that, but it seems impossible. Perhaps there's another way?",
    "Your words fall on deaf ears. Perhaps there is another way?",
    "You cannot do that here, adventurer. Try again.",
    "The forces of magic ignore your command. What else would you like to try?",
    "The spirits of the forest seem to be watching you. Better not anger them with an invalid command.",
    "Your attempt to interact with the environment was fruitless. Maybe there's another way?",
    "Your attempt to manipulate the world around you has failed. Think carefully about what you want to do next.",
    "The world around you remains still and silent, indifferent to your actions. Please try again with a different approach."
};

// random System prompt when player input an invalid command in fight
string invalid_input_2[8]= {
    "The hero within you yearns to succeed, but that's not going to work.",
    "The enemy seems to be waiting for you to make a move. Choose more carefully.",
    "Your instincts tell you that won't end well. Better come up with a new strategy.",
    "The shadows whisper with malevolence. You quickly rethink your approach.",
    "The darkness seems to be closing in around you. Better try a different command.",
    "The darkness around you seems to grow deeper as if it's closing in. Try something else before it's too late.",
    "The air grows thick with tension as if something is about to happen. But not with that command.",
    "You feel a sense of foreboding as you realize that won't work. There must be another way forward.",
};

// random System prompt to remind the player that the event is over and move on
string continue_input_1[6]= {
    "The path ahead is filled with danger and uncertainty. But you're ready for whatever comes next. \nPress \033[1;34m[Enter]\033[0m when you're prepared to move forward.",
    "You feel a sense of satisfaction as you complete the task at hand. But there's still much to be done. \nHit \033[1;34m[Enter]\033[0m to continue your journey.",
    "As you gaze out over the horizon, you realize just how far you've come. But there's still a long road ahead. \nPress \033[1;34m[Enter]\033[0m to keep moving forward.",
    "The mysteries of this world never cease to amaze you. \nPress \033[1;34m[Enter]\033[0m when you're ready to uncover the next one.",
    "The path ahead is shrouded in mist, but your determination is clear as day. \nPress \033[1;34m[Enter]\033[0m when you're ready to take the next step.",
    "The path ahead may be shrouded in darkness, but you have the light of courage to guide you. \nPress \033[1;34m[Enter]\033[0m to keep moving forward."
};

// random System prompt to remind the player that the fight is over and move on
string continue_input_2[6]= {
    "Your journey through this dark and foreboding world has only just begun. \nPress \033[1;34m[Enter]\033[0m to step boldly into the unknown.",
    "With the creature vanquished, you take a moment to catch your breath and prepare for what lies ahead. \nPress \033[1;34m[Enter]\033[0m to continue your journey.",
    "With the enemy vanquished, you pause to catch your breath and survey your surroundings. But time is running short. \nHit \033[1;34m[Enter]\033[0m to continue your quest.",
    "The darkness around you seems to thicken, as if something is waiting just beyond the shadows. But you're not afraid. \nPress \033[1;34m[Enter]\033[0m to step boldly into the unknown.",
    "The world trembles beneath your feet as you complete your task. But there's no time to celebrate. \nHit \033[1;34m[Enter]\033[0m to continue your fight against the encroaching darkness.",
    "Every challenge you overcome makes you stronger. Eeady yourself for what lies ahead. \nHit \033[1;34m[Enter]\033[0m to move forward."
};



string continue_road[4]={
    "The road seems peaceful and uneventful. It looks like you can only grip your sword tightly and proceed with determination.",
    "As you journey down the path, nothing eventful happens. Perhaps you should press ahead in this direction.",
    "As you tread on, nothing seems to happen. Perhaps it is best to keep moving forward."
    "You have smoothly passed through this part of your long journey without any unexpected events. This could be a sign to keep moving forward without hesitation."
};


// handle the case when the player meet portal event, the player's position will be teleported forward three steps
void Portal(int& num, int&status){
    string command;
    cout << Dividing_line
         << "Before you is a sight that seems out of place in the landscape around you. Strangely placed into one of the wall is an enclosed stone entrance filled with a " << "\033[35mswirling magical portal\033[0m" << ".\n" 
         << "You aren't sure where it leads, but maybe it could speed your journey through the Forest.\n";
    cout << Dividing_line
         << "1. " << "\033[1;34m[Enter the Portal]\033[0m Travel to an unknown place.\n" 
         << "2. " << "\033[1;34m[Leave]\033[0m Nothing happens.\n\n";

    getline(cin,command);
    while(command != "1" && command != "2"){
            cout << invalid_input_1[rand()%(sizeof(invalid_input_1)/sizeof(invalid_input_1[0]))] << endl;
            getline(cin,command);
        }
    // Handle command.
    cout << Dividing_line;
    if (command == "1"){
        num += 1;
        status += 3;
        // change position of player1

        cout << "Jumping through the portal, your sense of time and space is completely torn apart.\n"
             << "As you reorient yourself to the new surroundings, you realize that you have come to a strange place.\n";
    }
    else {
        cout << "Careful and cautious seems the better approach for reaching the top of the Spire. Ignoring the portal you continue on.\n";
    }
    //cout << Dividing_line << "1. \033[1;34m[Continue]\033[0m\n\n";
    cout << Dividing_line << continue_input_1[rand()%(sizeof(continue_input_1)/sizeof(continue_input_1[0]))] << endl;
    getline(cin,command);
}

// handle the case when the player meet Golden_Shrine event.
void Golden_Shrine(){
    string command;
    cout << Dividing_line << "Before you lies an elaborate shrine to an ancient spirit.\n";
    cout << Dividing_line
        << "1. " << "\033[1;34m[Pray]\033[0m Gain 80 \033[1;33mGold\033[0m.\n"
        << "2. " << "\033[1;34m[Desecrate]\033[0m Gain 175 \033[1;33mGold\033[0m. Become Cursed.\n"
        << "3. " << "\033[1;34m[Chant a mysterious spell]\033[0m \033[1m\"Super Pass COMP2113!\"\033[0m\n"
        << "4. " << "\033[1;34m[Leave]\033[0m Nothing happens.\n\n";
    getline(cin,command);
    while(command != "1" && command != "2" && command != "3" && command != "4"){
        cout << invalid_input_1[rand()%(sizeof(invalid_input_1)/sizeof(invalid_input_1[0]))] << endl;
        getline(cin,command);
    }
    cout << Dividing_line;
    if (command == "1"){
        role1.gold_coin += 80;
        cout << "As your hand touches the shrine, gold rains from the ceiling showering you in riches.\n";
    }
    else if (command == "2"){
        role1.gold_coin += 175;
        role1.damage -= 3;
        cout << "Each time you strike the shrine, gold pours forth again and again!\n"
             << "As you pocket the riches, something " << "\033[1;31mweighs heavily on you.\033[0m\n";
    }
    else if (command == "3"){
        role1.damage += 5;
        role1.defense += 5;
        role1.health += 20;
        role1.gold_coin += 2113;
        cout << "With the blessing of the C++ god, you have acquired \033[1;33m2113 pieces of gold coins\033[0m.\nDon't worry, this will not cause integer overflow. ;D\n";
    }
    else if (command == "4"){
        cout << "You ignore the shrine.\n";
    }
    //cout << Dividing_line << "1. \033[1;34m[Continue]\033[0m\n\n";
    cout << Dividing_line << continue_input_1[rand()%(sizeof(continue_input_1)/sizeof(continue_input_1[0]))] << endl;
    getline(cin,command);
}

// handle the case when the player meet Golden_Shrine event.
// Players have a half chance of meeting a normal treasure chest and a half chance of meeting a treasure chest mimic (a monster)
// If the player fails in a battle with the mimic, reuturn true. Else return false. (check if the game lose)
int Treasure_chest(){
    string command;
    string thing;
    int end = 0;
    role Mimic;
    bool mimic = (rand() % 2 == 1);
    if (mimic){
        // Mimic
        cout << Dividing_line << "You stumble upon a wooden box. It seems to be a little broken, the lock on it has rusted and damaged. Along with your approach, it emits a slight shaking.\n";
        cout << Dividing_line
            << "1. " << "\033[1;34m[\"Open\"]\033[0m Try to get the treasure within\n"
            << "2. " << "\033[1;34m[Leave]\033[0m Back away slowly\n\n";
        getline(cin,command);
        while(command != "1" && command != "2"){
            cout << invalid_input_1[rand()%(sizeof(continue_input_1)/sizeof(continue_input_1[0]))] << endl;
            getline(cin,command);
        }
        cout << Dividing_line;
        if (command == "1"){
            cout << "As you reach for the lock, the chest suddenly springs open revealing its true form: a grotesque monster with jagged teeth and a slimy maw!\n";
            cout << Dividing_line
            << "1. " << "\033[1;34m[Fight]\033[0m Prepare for a fierce battle\n"
            << "2. " << "\033[1;34m[Escape]\033[0m Flee from the abomination\n\n";
            getline(cin,command);
            while(command != "1" && command != "2"){
                cout << invalid_input_2[rand()%(sizeof(continue_input_2)/sizeof(continue_input_2[0]))] << endl;
                getline(cin,command);
            }
            cout << Dividing_line;
            if (command == "1"){
                cout << "Steel yourself for the coming fight!\n";
                // Fight
                Mimic = create_Mimic();
                end = fight(Mimic);
            }
            else if (command == "2"){
                cout << "You turn tail and run as fast as you can, barely escaping the clutches of the mimic.\n";
            }
        }
        else if (command == "2"){
            cout << "You wisely choose to back away from the dangerous-looking chest.\n";
        }
        //cout << Dividing_line << "1. \033[1;34m[Continue]\033[0m\n\n";
        if (end == 0){
            cout << Dividing_line << continue_input_2[rand()%(sizeof(continue_input_2)/sizeof(continue_input_2[0]))] << endl;
            getline(cin,command);
        }
        return end;
    }
    else {
        // Treasure Chest
        cout << Dividing_line << "You find a sturdy wooden chest, its lock undamaged and gleaming in the light. It appears to be filled with riches.\n";
        cout << Dividing_line
            << "1. " << "\033[1;34m[Open]\033[0m See what's inside\n"
            << "2. " << "\033[1;34m[Leave]\033[0m Leave it be\n\n";
        getline(cin,command);
        while(command != "1" && command != "2"){
            cout << invalid_input_1[rand()%(sizeof(invalid_input_1)/sizeof(invalid_input_1[0]))] << endl;
            getline(cin,command);
        }
        cout << Dividing_line;
        if (command == "1"){
            cout << "You successfully pry open the chest, revealing a trove of treasure within: gold coins, gems, and a valuable piece of equipment.\n";
            role1.gold_coin += 100 + rand()%20;
            if (role1.weapon == "Nothing"){
                thing = "Long sword";
            }
            else if (role1.armor == "Nothing"){
                thing = "God-bless armor";
            }
            else {
                switch (rand()%6)
                {
                case 0:
                    thing = "Flintlock";
                    break;
                case 1:
                    thing = "Standard armor";
                    break;
                case 2:
                    thing = "Magical stick";
                    break;
                case 3:
                    thing = "Magic armor";
                    break;
                case 4:
                    thing = "Huge axe";
                    break;
                case 5:
                    thing = "Giant armor";
                    break;
                default:
                    break;
                }
            }
            cout << "Do you want to equip " << thing << " or not?" << " IF yes, please enter 1. If no, please enter 0." << endl;
            cin >> command;
            while (command != "0" && command != "1"){
                cout << "Error. Please input a correct number." << endl;
                cin >> command;
            }
            if (command == "1"){
            change_proporties(thing);
            }
            else if (command == "2"){
                cout << "You decide to leave the chest alone and continue on your way.\n";
            }
            //cout << Dividing_line << "1. \033[1;34m[Continue]\033[0m\n\n";
            cout << Dividing_line << continue_input_1[rand()%(sizeof(continue_input_1)/sizeof(continue_input_1[0]))] << endl;
            getline(cin,command);
            return 0;
        }
        return 0;
    }
}

// handle the case when the player meet Lab event.
// Players can get three random potions in this event
void Lab(){
    string command;
    int index[3]={0,0,0};
    index[0] = rand()%3;
    while(index[0] == index[1]){
        index[1] = rand()%3;
    }
    while(index[0] == index[2] || index[1] == index[2]){
        index[2] = rand()%3;
    }
    cout << Dividing_line << "You find yourself in a room filled with racks of test tubes, beakers, flasks, forceps, pinch clamps, stirring rods, tongs, goggles, funnels, pipets, cylinders, condensers, and even a rare spiral tube of glass.\nWhy do you know the name of all these tools? It doesn't matter, you take a look around.\n";
    for (int i=0; i<3; i++){
    cout << Dividing_line
        << "1. " << "\033[1;34m[Search]\033[0m Obtain a random Potions\n\n";
    getline(cin,command);
    while(command != "1"){
        cout << invalid_input_1[rand()%(sizeof(invalid_input_1)/sizeof(invalid_input_1[0]))] << endl;
        getline(cin,command);
    }
    cout << Dividing_line;
    if (command == "1"){
        cout << "You find a " << shop_item_potion_arr[index[i]].name << endl;
            if (shop_item_potion_arr[index[i]].name == Blood_potion.name) {
                role1.health += 20;
                cout << "As you drink the potion, your wounds heal and your body becomes more resilient. You feel your maximum health increase." << endl;
            }
            if (shop_item_potion_arr[index[i]].name == Attack_potion.name) {
                role1.damage += 5;
                cout << "The elixir surges through your veins, sharpening your senses and increasing your attack power!" << endl;
            }
            if (shop_item_potion_arr[index[i]].name == Earth_potion.name) {
                role1.defense += 5;
                cout << "You feel the potion's power moving through you, as if it were part of your very being. your defense is now even stronger than before." << endl;
            }
        }
    }
    cout << Dividing_line
        << "1. " << "\033[1;34m[Leave]\033[0m Nothing happens.\n\n";
    getline(cin,command);
    while(command != "1"){
        cout << invalid_input_1[rand()%(sizeof(invalid_input_1)/sizeof(invalid_input_1[0]))] << endl;
        getline(cin,command);
    }
    cout << Dividing_line << continue_input_1[rand()%sizeof(continue_input_1)/sizeof(continue_input_1[0])] << endl;
    getline(cin,command);
}

// Use rand() to determine which event the player encounters.
// If the player fails in a battle with the mimic, reuturn true
int randomEvent(){
    int end;
    switch (rand()%3)
    {
    case 0:
        Golden_Shrine();
        break;
    case 1:
        end = Treasure_chest();
        return end;
        break;
    case 2:
        Lab();
        break;
    }
    return 0;
}
