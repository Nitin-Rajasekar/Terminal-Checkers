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

Additional notes on the output of the "K possible moves" function:
The blank lines here are significant. For an input K, you will likely see K moves being labelled without
any line breaks (if it's more than K, it's because the moves involve jumps). That means they are successive
moves. Following that, before you encounter consecutive lines without line breaks, will be several 
line-separated moves. All of these moves are substitutes for the last move. The same applies to all the 
clusters of lines you will find. 

Here is an dummy output to illustrate what this means. Say, K = 3:

A
B
C

D

E

F
G

H

I

J

K
L
M

N

Here, A is the first move, and B is a possible move after A. C, D, E are the possible moves after B. F is a
possible move after A, and G, H, I, J are possible moves after F. When you encounter KLM (size of cluster 
of lines = K), it means all the possible moves starting with the move "A" have been exhausted. Similarly, L
is a possible move after K, M and N are possible moves after L, and so on.