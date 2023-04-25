#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <math.h>
#include <cstdlib>
#include <unistd.h>
#include <time.h>
using namespace std;

int main(){
  cout << "Oh traveler who is lost in confusion, your soul has been reborn into a different world." << endl;
  cout << "Now choose your legend and embark on a new adventure." << endl;
  cout << "Please choose a existing game (Input 1) or choose a new game (Input 2) or quit the whole game(Input 0)" << endl;
  cin >> int a;
  while (a !=0 ){
  while (a != 1 && a != 2){
        cout << "Error. Please input a correct number." << endl;
        cin >> a;
    }
  if ( a == 1 ){
    cout << "Fornign traveller, you come back to your adventure!" << endl; 
    //display_game_file
    //readgame（file1）
    
  }
  else if ( a == 2){
      cout << "Fornign traveller, your advanture starts!" << endl; 
      makepath();
      cout << " Maze is initialized." << endl;
      role role1;
      role makerole(role &role1)
      int status=1, num=0;
      int change, place;
      cout<<"You can go upward(input 0) OR check map(input 1) OR savegame and quit game(input 2) OR quit game without savegame(input 3) OR check bag(input 4)" << endl;
      while (status!=0){
          cin>>change;
          if (change==1){
              showmap();
          }
          if (change==2){
              //save and quit;
          }
          if (change==3){
              //quit;
            break;
          }
          if (change==4){
              display_bag(role role1);
          }
          if ( change==0){
              status++;
              cout<<"     |     "<<endl;
              if (status%3==0 && status!=15){
                  int nchoose=status%3;
                  cout<<choose[num][0]<<"     "<<choose[num][1]<<endl;
                  choosedirection(nchoose);
                  num++;
                  map(place);
              }
              if (status==15){
                  status=0;
                  cout << "You meet the final boss of the maze." << endl;
                  //final boss
                  fight(role role1, role boss);
                  if (e==1){
                    //TE
                    cout << "You defeat the boss, but youself become the new Prince of the Devils." << endl;
                  break;
              }
          }
          cout<<"You can go upward(input 0) OR check map(input 1) OR savegame and quit game(input 2) OR quit game without savegame(input 3) OR check bag(input 4)" << endl;
          if (change!=0){
              cout<<"You can only go upward"<<endl;
              continue;
          }
      }
        cout << "You get to end of the maze and your soul is pulled to a unknown place again......"
        //制作名单
        sleep(3);
        cout << "Please choose a existing game (Input 1) or choose a new game (Input 2) or quit the whole game(Input 0)" << endl;
        }
     
      return 0;
    }

