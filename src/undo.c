struct move                   //from review
{
    int p1;
    int p2;
    int n1;
    int n2;
};
struct move storered[100000];
struct move storeblue[100000];
int redmoves = 0, bluemoves = 0;
void storage(int x1, int y1, int x2, int y2, int redmoves, int bluemoves, int player)       //from review
{
    if (player == 1)
    {
        storered[redmoves].p1 = x1;
        storered[redmoves].p2 = y1;
        storered[redmoves].n1 = x2;
        storered[redmoves].n2 = y2;

        redmoves++;
    }

    if (player == 2)
    {
        storeblue[bluemoves].p1 = x1;
        storeblue[bluemoves].p2 = y1;
        storeblue[bluemoves].n1 = x2;
        storeblue[bluemoves].n2 = y2;

        bluemoves++;
    }
}

void undo(int num_moves, int redmoves, int bluemoves, struct move storered[100000], struct move storeblue[100000], int board[10][10])  
{
    int i = 0, j = 0;
    int x1, y1, x2, y2;
    MakeBoard(board);
    

    while (i + j < (redmoves+bluemoves-num_moves))
    {
        if ((i + j) % 2 == 0) //player 1 plays the 1st, 3rd , 5th move and so on
        {
            x1 = storered[i].p1;
            y1 = storered[i].p2;
            x2 = storered[i].n1;
            y2 = storered[i].n2;

            Logic(1, x1, y1, x2, y2, board); // play player 1's move
            PrintBoard(board);
            i++;
        }

        else if ((i + j) % 2 == 1) //player 2 playes the 2nd, 4th, 6th move and so on
        {
            x1 = storeblue[j].p1;
            y1 = storeblue[j].p2;
            x2 = storeblue[j].n1;
            y2 = storeblue[j].n2;

            Logic(2, x1, y1, x2, y2, board); // play player 2's move
            PrintBoard(board);
            j++;
        }
    }
    
}
