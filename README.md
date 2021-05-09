This project allows you to play checkers via the terminal.

To run the project, download and extract the zip. Navigate to src/, compile and run checkers.c.

On running the program, you will be asked to pick colors of your choice for player 1 and player
2 respectively. Player 1 plays first, and occupies the lower position on the board by default.

To play, enter starting and ending coordinates of the desired piece during your turn.
Coordinates are in the format (A-H,1-8). If you enter an invalid pair of coordinates, they
will be rejected and you will be prompted to retry.
You can press X0 X0 at any time which will bring up the instructions to use some special commands,
including reviewing the game, undoing certain moves, checking the rules and viewing the next 'k'
(input by the user) possible moves. The output for the latter will be pushed into a text file in the
same directory, containing the starting and ending coordinates of the corresponding moves - the idea
being that one can copy them and paste them into the terminal to view the output; helps avoid cluttering
up the terminal as well as the text file.

The game ends when one of the users has no pieces left, or has no possible moves to make.