#include <iostream>
#include <string>
using namespace std;
random_device rd;//用于生成随机数种子
mt19937 r_eng(rd());//随机数生成器  
uniform_int_distribution<int> dis(0, 2);//随机数分布器 闭区间
//0: awards; 1: jump to other place; 2: monster

void makepath(){
    int a[2], b[2], c[2], d[2], e[2];
    int choose[5]={a,b,c,d,e};
    for (int j=0; j<5; j++){
        for (int i = 0; i < 2; ++i)
            choose[j][i]=dis(r_eng);
    }
}

int choosedirection(int nchoose){
    int place;
    string sure;
    cout<<"Choose your direction: Left OR Right"<<endl;
    cin>>direction;
    if (char direction==75){
        place=choose[nchoose][0];
    }
    if (char direction==77){
        place=choose[nchoose][1];
    }
    cout<<"Are you sure? Yes Or No"<<endl;
    cin<<sure;
    while (sure=="No"){
        choosedirection(nchoose);
    }
    return place;
}

void map(int place){
    if (place==0){
        //awards system
    }
    if (place==1){
	if (status<11){
		uniform_int_distribution<int> dis(status, 11);
        	status=dis(r_eng);
	}
    }
    if (place==2){
        //monster system
    }
}

void showmap(){
    
}

int main() {
	makepath();
	int status=1;
	int change, place;
	cout<<"You can go upward OR check map(type 1) OR savegame and quit game(type 2) OR quit game without savegame(type 3) OR check bag(type 4)"
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
	    }
	    if (change==4){
		//bagfunction;
	    }
	    if (char change==72){
	        status++;
	        if (status%3==0 && status!=15){
	            int nchoose=status%3;
	            choosedirection(nchoose);
	            map(place);
	        }
	        if (status==15){
	            status=0;
	            //final monster
	            break;
	        }
	    }
	    if (char change!=72){
	        cout<<"You can go upward"<<endl;
	        continue;
	    }
	}
	return 0;
}
