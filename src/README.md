PROJECT : CHECKERS 8*8

REVIEW :
In this function we are taking a struct consisting of 4 integers p1,p2,n1,n2. Here these 4 integers
represent the position of the coin on the board before and after making a move 
(p1,p2 - before n1,n2- after). Next we take 2 struct arrays of length which is more than the maximum
number of total moves possible. Here one struct array stores the moves of the red coin and the other 
struct array stores the moves of blue coin.

When either player wants to review the game , the function creates a new board and starts playing all 
the moves from start of the struct arrays till the end (alternately). Ror doing this we use the functions 
Makeboard - for creating a new board, Logic - for playing each stored move , PrintBoard - to print the board
after each move.

TIME COMPLEXITY :
 // need to do //
