#include <iostream>
#include <ctime>
#include <cstdlib>
#include <tuple>
#include <random>
using namespace std;

int main(){

//function to add char to array. it checks if there is a piece already in a space
void move(char x[], char c) {
    for int(i=0;i<7;i++){
        if (x[i]== 'x' || 'y'){

        }else{
            x[i]=c;
        }

    }


}
//check vertical 4 in a row function
bool check_vertical(char x[]){
    int count=0;
    bool same=false;
    for(int i=0;i<7;i++){
        
        if(x[i]== x[i-1]){
            cout+=1;
        }else{
            count=0;
        }
        if(count>=3){
            return true;
        }else{
            return false;
        }
    }
}
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
cout<<"Player 1 Select character of each column"<<endl;
cin>>column;
//switch places the players move in each column/array
    switch (column){
    case 'A': move(a,player_one);
        break;
    case 'a': move(a,player_one);
        break;
    case 'B': move(b,player_one);
        break;
    case 'b': move(b,player_one);
        break;
    case 'C': move(c,player_one);
        break;
    case 'c': move(c,player_one);
        break;
    case 'D': move(d,player_one);
        break;
    case 'd': move(d,player_one);
        break;
    case 'E': move(e,player_one);
        break;
    case 'e': move(e,player_one);
        break;
    case 'F': move(f,player_one);
        break;
    case 'f': move(f,player_one);
        break;
    case 'G': move(g,player_one);
        break;
    case 'g': move(g,player_one);
        break;
    



    default: // code to be executed if n doesn't match any cases
}
}else{
cout<<"Player 2 Select character of each column"<<endl;
cin>>column;
//switch places the players move in each column/array
    
    switch (column){
    case 'A': move(a,player_two);
        break;
    case 'a': move(a,player_two);
        break;
    case 'B': move(b,player_two);
        break;
    case 'b': move(b,player_two);
        break;
    case 'C': move(c,player_two);
        break;
    case 'c': move(c,player_two);
        break;
    case 'D': move(d,player_two);
        break;
    case 'd': move(d,player_two);
        break;
    case 'E': move(e,player_two);
        break;
    case 'e': move(e,player_two);
        break;
    case 'F': move(f,player_two);
        break;
    case 'f': move(f,player_two);
        break;
    case 'G': move(g,player_two);
        break;
    case 'g': move(g,player_two);
        break;
    



    default: // code to be executed if n doesn't match any cases
}


}

}






}
