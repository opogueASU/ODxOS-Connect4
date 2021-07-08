#include <iostream>
#include <ctime>
#include <cstdlib>
#include <tuple>
#include <random>
using namespace std;

int main(){
//variables for the players
char player_one = 'x';
char player_two = 'y';

//character arrays for the game board
char a[6];
char b[6];
char c[6];
char d[6];
char e[6];
char f[6];
char g[6];
//char for column 
char column = 'A';
//use for loop to play the game
cout << "| " + a[0] + " | " + b[0] +  "| " + c[0] +  "| " + d[0] + "| " + e[0] + "|  " + f[0] + "| "  + g[0] +  "|"<<endl;
for(int i=0;i<43;i++){
cout << "  A   B   C   D   E   F   G"  <<endl;
cout << "|   |   |   |   |   |   |   |"  <<endl;
cout << "|   |   |   |   |   |   |   |"  <<endl;
cout << "|   |   |   |   |   |   |   |"  <<endl;
cout << "|   |   |   |   |   |   |   |"  <<endl;
cout << "| " <<a[0]<< " | " <<b[0]<<  "| " <<c[0] << "| " << d[0] << "| " << e[0]<< "|  "<< f[0]<< "| " <<g[0]<<  "|"<<endl;








//if i is even player 1's turn
//else is player 2's turn
if(i%2==0){
cout<<"Select character of each column"<<endl;
cin>>column;
    if()
}else{


}

}






}
