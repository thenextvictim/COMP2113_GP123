## Identification of the team members.
Our group include 5 members:
Deng Menghao, Huang Shiqi, Song Bingyan, Wu Qiong, Zhang Kaiqi (ordered alphabetically).

## Game description
This a roguelike game, which has a core feature of randomness and adventure. The player will play a role of legend to explore a maze full of danger. Player can first edit his/her own name and load a existing game or create a game. After choosing a new game, player will need to select a legend. He/She can choose 3 careers--human warrior, elf magician and giant tank .

Human warrior -- balanced initial damage(DA), health(HP), defense(DE) and moderate initial gold coins(G) --i.e. initial DA(20), HP(100), DE(15), G(50).

Elf magician -- very high initial DA, low HP, low DE, and many initial G --i.e. initial DA(30), HP(70), DE(10), G(70).

Giant tank --  low initial DA, high HP, high DE, and low initial G --i.e. initial DA(12), HP(140), DE(20), G(40).

After selected a role to play, a fully random maze will be automatically created with several branches, players will encounter a fork every three steps. After choosing the direction at the fork，players would like to trigger some random events like facing monsters/ enconter a portal/ find shops etc. Then after several steps of adventure, the legend will finally reach the exit of maze with a boss in the end. If boss is defeated, then player will pass the maze and min. Otherwise, legends will lose if HP <= 0 in any of the fights, which also means the current game lose and player need to load a existing game or create another new game.

## Nouns and rules explanation:

Monsters: will attack legends at once and have different types. 3 legends are good at fighting with some of them, but not able to handle the others. Once defeated, the
legend will get some spoil include: weapoms, armors, gold coins.

Portal: if a legend find this, he/she can teleport to a deeper place in the maze(i.e. omit some random branches and get closer to the end).

Shops: crafty goblin merchant will show the legend 3 types of goods include weapons, armors, magic potions or holly relic. The goods are expensive and cost gold coins.

Weapons:
    Long sword: +5 damage, every legend can use.
    Flintlock: +8 damage, only can be used by human warrior.
    Magical stick: +10 damage, only can be used by elf magician.
    Huge axe： +5 damage， only can be used by giant tank.

Armors:
    God-bless armor: +5 defense, every legend can use.
    Standard armor: +8 defense, only can be used by human warrior.
    Magic armor： +5 defense, only can be used by elf magician.
    Giant armor: +10 defense, only can be uesd by giant tank.

Magic potion:
    damage potion：+5 damage, every legend can drink.
    health potion: +20%HP， every legend can drink.
    defense potion: +5 defense, every legend can drink.

Holly relic: Only works when facing the boss--Prince of the Devils, a legend can choose to use or not to use before the final battle.
    If used, then both legend and boss will be deducted 50% of HP.
    Else, nothing happens and final battle will start.
    
Bag: You can cheak your properties here along with your number of gold coins and your equipments.
    
 Fight rules： Legends are the most acute beings, even the giant tank, so they can first attack the monsters and the boss.
 Every round， legends will attack once and monsters will attend once, and HP will be deducted if being attacked. The loss of HP: Attacker's DA - Defenser's DE
 When one of the fighters'HP <= 0, then fight is over. After a fight, since legends are blessed by the gods, they can recover from all hurts before and HP will resetted to 100%.  
 
 Fight example:  
 
          (your_name): In the name of justice, your guilty will be judged!  
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

//A list of features that you have implemented and explain how each coding 
element 1 to 5 listed under the coding requirements aforementioned support 
your features.

//A list of non-standard C/C++ libraries, if any, that are used in your work and 
integrated to your code repo. Please also indicate what features in your game 
are supported by these libraries.

// Compilation and execution instructions. This serves like a "Quick start" of your 
game. The teaching team will follow your instructions to compile and run your 
game.
