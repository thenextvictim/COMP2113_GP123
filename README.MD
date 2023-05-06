## Identification of the team members
Our group include 5 members:  
Deng Menghao, Huang Shiqi, Song Bingyan, Wu Qiong, Zhang Kaiqi (ordered alphabetically).

## Game description
This is a roguelike game with a core feature of randomness and adventure. The player will play the role of legend to explore a maze full of danger. The player can first edit his/her name and load an existing game or create one. After choosing a new game, the player will need to select a legend. He/She can choose 3 careers--human warrior, elf magician and giant tank.  

Human warrior ：balanced initial damage(DA), health(HP), defense(DE) and moderate initial gold coins(G) --i.e. initial DA(20), HP(100), DE(15), G(50).

Elf magician ：very high initial DA, low HP, low DE, and many initial G --i.e. initial DA(30), HP(70), DE(10), G(70).

Giant tank ：low initial DA, high HP, high DE, and low initial G --i.e. initial DA(12), HP(140), DE(20), G(40).

After selecting a role to play, an entirely random maze will be automatically created with several branches, and players will encounter a fork every three steps. After choosing the direction at the fork，players would like to trigger random events like facing monsters/encountering a portal/finding shops/experiencing magical incidents, etc. Then after several steps of adventure, the legend will finally reach the maze exit with a boss in the end. The player will pass the maze and min if the boss is defeated. Otherwise, legends will lose if HP <= 0 in any of the fights, which means the current game loses, and the player needs to load an existing game or create another new one.

## Nouns and rules explanation

Monster: They will attack legends at once and have different types. The three legends are respectively good at fighting some of them, but unable to take on others. Once defeated, the legend will get some spoils, including weapons, armors, and gold coins.

Portal: If a legend finds this, he/she can teleport to a deeper place in the maze(i.e. omit some random branches and get closer to the end).

Shop: Crafty goblin merchant will show the legend 3 types of goods, including weapons, armour, or magic potions. The goods are expensive and cost gold coins.

Random event: Random events will be met at every crossing, and unknown things will happen. The role can get weapons, armour, magic potions, holly relic, and sometimes debuffs.

Weapon:  
    Long sword: +5 damage, every legend can use.  
    Flintlock: +8 damage, only can be used by human warrior.  
    Magical stick: +10 damage, only can be used by elf magician.  
    Huge axe： +5 damage， only can be used by giant tank.  

Armour:  
    God-bless armor: +5 defense, every legend can use.  
    Standard armor: +8 defense, only can be used by human warrior.  
    Magic armor： +5 defense, only can be used by elf magician.  
    Giant armor: +10 defense, only can be uesd by giant tank.  

Magic potion:  
    Damage potion：+5 damage, every legend can drink.  
    Health potion: +20%HP， every legend can drink.  
    Defense potion: +5 defense, every legend can drink.  

Holly relic: 
    Only works when facing the boss--Prince of the Devils, a legend can choose to use or not to use before the final battle.  
    If used, then both legend and boss will be deducted 50% of HP.  
    Else, nothing happens and final battle will start.  
    
Bag: You can check your properties here, along with your number of gold coins and your equipment.
    
Fight rules： 
Legends are the most acute beings, even the giant tank, so they can first attack the monsters and the boss.
Every round，legends will attack once, monsters will attend once, and HP will be deducted if attacked. (The loss of HP: Attacker's DA - Defenser's DE.) When one of the fighters'HP <= 0, then the fight is over. 
After a fight, since the gods bless legends, they can recover from all the hurts before, and HP will reset to 100%.  
 
Fight example (for demo, not identical to real situation):  
 
          (your_name): Infor  the name of justice, your guilty will be judged!  
          Forest wolf: Bow-bow~  
          1st round:   
          Human warrior (your_name) attacks Forest wolf and make a hurt of -12 (48/60)  
          Forest wolf attacks Human warrior and make a hurt of -17 (83/100)  
          2st round:   
          Human warrior (your_name) attacks Forest wolf and make a hurt of -8 (40/60)  
          Forest wolf attacks Human warrior and make a hurt of -13 (70/100)  
          3st round:   
          Human warrior（your_name）attacks Forest wolf and make a hurt of -10 (30/60)  
          Forest wolf attacks Human warrior and make a hurt of -15 (55/100)  
          4st round:   
          Human warrior（your_name） attacks Forest wolf and make a hurt of -9 (21/60)  
          Forest wolf attacks Human warrior and make a hurt of -16 (39/100)  
          5st round:   
          Human warrior（your_name） attacks Forest wolf and make a hurt of -11 (10/60)  
          Forest wolf attacks Human warrior and make a hurt of -14 (25/100)  
          6st round:   
          Human warrior（your_name） attacks Forest wolf and make a hurt of -12 (0/60)  
          Forest wolf dies, you win.  
          You gets 5 gold coins, a Magic armor.  
          
## List of Features have implemented
- Randomized maps: A new map is generated every time the game is loaded. There are many forks in the map, and players will face different challenges in choosing different directions，i.e. monsters, shops and portals.

- Personalized role attributes: There are roles with different characteristics to choose from. Game equipments are randomly dropped after the battle is won, different weapons and armors can only be equipped by specific occupations. Gold coins can be used to buy required potions and game equipments in the store.

- Viewable role status: Players can view current location, role attributes and armored game equipments.

- Automated combat system: When encountering a monster, the battle will be automatically triggered and settled through the turn system. If the battle is won, gold coins and game equipments will be randomly dropped.

- Game save system: Players can save their current game progress and continue the game the next time they play.

## Five coding requirements
1. Generation of random game sets or events
Players will encounter different random events as they advance.    
The types of monsters met are random, and the number of gold coins and game equipment will be randomly dropped after successfully defeating the monster.  
Different types of goods will be randomly shown in the shop. 

2. Data structures for storing game status  
Saved data includes the role and the map i.e. monsters, shops and portals.
About the role: Legend, name, weapon, armor and trash talk, these are in form of string. Damage, health, defense, gold coin as saved as integers. Holly relic is saved as bool.  
About the map: Generated paths and player selections are saved as arrays.

3. Dynamic memory management

4. File input/output (e.g., for loading/saving game status)  
If the player chooses to save, all the required data will be stored in a text file, and the data in the file can be read in the next game.

5. Program codes in multiple files  
The main.cpp file contains the driver program and basic inputs for this game. Game map, fight rule, random events and game save are declared and stored in separate files.



//A list of features that you have implemented and explain how each coding 
element 1 to 5 listed under the coding requirements aforementioned support 
your features.

//A list of non-standard C/C++ libraries, if any, that are used in your work and 
integrated to your code repo. Please also indicate what features in your game 
are supported by these libraries.

// Compilation and execution instructions. This serves like a "Quick start" of your 
game. The teaching team will follow your instructions to compile and run your 
game.

## Compilation and execution instructions
Use```make clean``` to clean all old *.o and game files
Run ```make game``` to compile the game.
Do ```./game``` to start the game.
