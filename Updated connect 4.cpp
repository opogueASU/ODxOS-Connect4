#include <iostream>
#include <ctime>
#include <cstdlib>
#include <tuple>
#include <random>

// cout+  will handle the input and the output as a stream of bytes that are sent and received.  
using namespace std;

char board [6][7];

void ABBoard() {
  for (int a= 0; a < 6; a++) {
    for (int b = 0; b < 7; b++) {
      board[a][b] = '-';
      cout << board [a][b]<< ' ';
    }
    cout << endl;
  }
}

void printBoard() {
  for (int a=0; a < 6; a++) {
    for (int b = 0; b< 7; b++) {
      cout << board[a][b] << ' ';
    }
    cout << endl;
  }  
}

int pick() {
  int column;
  cin >> column;
  return column; 
}

tuple<int, int> decision(int column, bool human) {
  column = column -1;
  if (human == 1) {
    for (int row=5; row>-1 ; row--) {
      if (board[row][column] == '-') {
        return make_tuple(row, column); 
      }
    }
  }
  else {
    srand(time(0));
    int Aicolumn = (rand() % 6) + 1;
    for (int row=5; row>-1; row--) {
      if (board[row][Aicolumn] == '-'){
        return make_tuple(row, Aicolumn);
      }
    }
  }
}

bool check () {
  for (int a=3; a< 6; a++){
    for (int b=0; b < 7; b++){
      if (board[a][b] == 'X' 
          and board[a][b] == board[a-1][b]
          and board[a][b] == board[a-2][b]
          and board[a][b] == board[a-3][b]){
        return true;
      }
      else if (board[a][b] == 'X' 
          and board[a][b] == board[a-1][b]
          and board[a][b] == board[a-2][b]
          and board[a][b] == board[a-3][b]){
        return true;
      }
    }
      
  } 
  for (int a=0; a< 6; a++){
    for(int b=0; b< 4; b++){
      if (board[a][b] == 'X'
          and board[a][b] == board[a][b+1]
          and board[a][b] == board[a][b+2]
          and board[a][b] == board[a][b+3]){
        return true;     
      }
      else if (board[a][b] == 'X'
          and board[a][b] == board[a][b+1]
          and board[a][b] == board[a][b+2]
          and board[a][b] == board[a][b+3]){
        return true; 
      }   
    }
  }
  for (int a=4; a< 6; a++){
    for(int b=0; b < 4; b++){
      if (board[a][b] == 'X'
          and board[a][b] == board[a-1][b+1]
          and board[a][b] == board[a-2][b+2]
          and board[a][b] == board[a-3][b+3]){
        return true;     
      }
      else if (board[a][b] == 'X'
          and board[a][b] == board[a-1][b+1]
          and board[a][b] == board[a-2][b+2]
          and board[a][b] == board[a-3][b+3]){
        return true;     
      }
    }
  }
  for (int a=4; a< 6; a++){
    for(int b=3; b < 7; b++){
      if (board[a][b] == 'X'
          and board[a][b] == board[a-1][b-1]
          and board[a][b] == board[a-2][b-2]
          and board[a][b] == board[a-3][b-3]){
        return true;
      }
      else if (board[a][b] == 'O'
          and board[a][b] == board[a-1][b-1]
          and board[a][b] == board[a-2][b-2]
          and board[a][b] == board[a-3][b-3]){
        return true;
      }
    }
  }
  return false;
}

int main() {
 /**********************************/
  int playerNum=1;
  bool player2;
  cout << "Press 0 to play against AI or Press 1 to add a Player 2: " << endl;
  cin >> player2;
  cout<< "\n\n";
/**********************************/  
  cout << "------------------------------------" << endl;
  cout << "         WELCOME TO CONNECT 4!      " << endl;
  cout << "------------------------------------" << endl;
  cout << "Welcome to Connect 4.  Your board has 6 Rows and 7 Columns. " << endl;
  ABBoard();
  cout << endl << "Rules of the Game:\n";
  cout << "Step 1: Human Player will be labeled X " << endl;
  cout << "Step 2. The AI player(or Player 2) will drop the pieces labeled O." << endl;
  cout << "Step 3. Pick a column to drop your piece.  For example, numbers 1-7" << endl;
  cout << "4. Keep dropping pieces until you are the AI gets Connect 4!!" << endl;
  bool human;
  bool result;
  while (true) {
    cout << endl <<"Player"<<playerNum<<" input: ";//**//
    human = true;
    int column = pick();
       /**********************************/
    while ( board[0][column-1] != '-' ){
        cout << "Column Full, Try again: ";
        column = pick();
    }
    /************************************/
    int row;
    tie(row, column) = decision(column, human);
/**************************************/
    if (player2){
        if (playerNum==1){
            board[row][column] = 'X';
        }
        else{
            board[row][column] = 'O';
        }
    }
    else{
        board[row][column] = 'X';
    }
    /*************************************/

    printBoard();
    result = check();
    if (result == true){
      cout << "Congratulations, Player"<< playerNum  << " have won the game" << endl;
      break;
    }
    /**************************************/
    if (player2){
      playerNum = 2 - playerNum +1;}
    /*************************************/
    if (!player2) {//**//
    human = false;
    cout << "Your Artificial Intelligence Opponent Plays:" << endl;
    tie(row, column) = decision(column, human);
    board[row][column] = 'O';
    printBoard();
    result = check();
    if (result == true){
      cout << "The AI has won! It was a good game though.  Try Again!" << endl;
      break;
    }
   }//**//
  }
  return 0;
}
