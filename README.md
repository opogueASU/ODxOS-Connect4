# ODxOS-Connect4
Requirements:

Check if game is still running
Perform a check to see if a Connect four has been found.
If it hasn’t, loop back through the software.
Check if someone has one vertically, horizontally, diagonally

2D Array for Connect Four spaces
Store the individual spaces for each piece.

Prevent repeating pieces
Prevent players from taking occupied space
If space is taken, let the player know and let them take their turn over

Prevent players from playing out of bounds
Don’t let players play beyond the boundaries set by the board

Turn based game
Player 1 and 2 should alternate turns until a winner is found

Update Board
Update the board with a players choices

User Input
Take in input from Player 1 and Player 2 separately
Both from the row and column

Prevent misinput
If a player hits a space that’s already taken, or an invalidate character. State that, then repeat their turn.

Check if game is tie
If the turn counter is the final one and no connect fours have been found, then call it a tie game. End game

Display Board before and after each turn
Update the board and display it for the next player every turn.
