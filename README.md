## Tic Tac Toe
### Setup  
Download  
`$ git clone git@github.com:koochin/tic-tac-toe.git`  
  
Build  
`$ cd patient-management-system`  
`$ make`
  
Run  
`$ ./main`  
  
Removal  
`$ make clean`  
  
uses **make** and **g++17** (see makefile)  
  
### How to play
The player who guesses closest to the randomly generated number (1-100 inclusive) gets first move  
  
Each player enters their move in `row column` format (there must be a space between them)  
  
The board displays the corresponding `row column` values of each tile  
  
First player to form three consecutive pieces (horizontal, vertical, diagonal) wins, otherwise the game results in a draw    
  
  
