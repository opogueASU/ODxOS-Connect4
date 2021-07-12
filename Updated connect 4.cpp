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
      else if (board[a][b] == 'O' 
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
      else if (board[a][b] == 'O'
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
      else if (board[a][b] == 'O'
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
  int players;
  cout << "------------------------------------" << endl;
  cout << "         WELCOME TO CONNECT 4!      " << endl;
  cout << "------------------------------------" << endl;
  cout<<"Single(1) or 2-Players(2)"<<endl;
  cout<<"Enter number: " ;
  cin>>players;
  if(players==1){

  
    cout << "Welcome to Connect 4.  Your board has 6 Rows and 7 Columns. " << endl;
    ABBoard();
    cout << endl << "Rules of the Game:\n";
    cout << "Step 1: Human Player will be labeled X " << endl;
    cout << "Step 2. The AI player will drop the pieces labeled O." << endl;
    cout << "Step 3. Pick a column to drop your piece.  For example, numbers 1-7" << endl;
    cout << "4. Keep dropping pieces until you are the AI gets Connect 4!!" << endl;
    bool human;
    bool result;
    while (true) {
      cout << endl <<"You Played: ";
      human = true;
      int column = pick();
      int row;
      tie(row, column) = decision(column, human);
      board[row][column] = 'X';
      printBoard();
      result = check();
      if (result == true){
        cout << "Congratulations, you have won and defeated the Artificial Intelligence"<< endl;
        break;
      }
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
    }
//2 player game
  }else{
      cout << "Welcome to Connect 4.  Your board has 6 Rows and 7 Columns. " << endl;
    ABBoard();
    cout << endl << "Rules of the Game:\n";
    cout << "Player 1 will be labeled X " << endl;
    cout << "Player 2 will be labeled O." << endl;
    cout << "Pick a column to drop your piece.  For example, numbers 1-7" << endl;
    cout << "4. Keep dropping pieces until a player get 4 in a row!!" << endl;
    bool player_one;
    bool result;
    while (true) {
      cout << endl <<"Player 1 Played: ";
      player_one = true;
      int column = pick();
      int row;
      tie(row, column) = decision(column, player_one);
      board[row][column] = 'X';
      printBoard();
      result = check();
      if (result == true){
        cout << "Congratulations, Player 1 Wins!!"<< endl;
        break;
      }
      player_one = false;
      cout << "Player 2 Played:" << endl;
      int column_two = pick();
      int row_two;
      tie(row_two, column_two) = decision(column_two, true);
      board[row_two][column_two] = 'O';
      printBoard();
      result = check();
      if (result == true){
        cout << "Congratulations, Player 2 Wins!!" << endl;
        break;
      }
    }


  }
  return 0;
}
