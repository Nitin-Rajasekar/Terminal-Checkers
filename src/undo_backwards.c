/*unlike the previous undo that starts from the beginning and goes to the required position, this implementation tries to start from the current position and work backwards*/
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
void undo_2(int num_moves, int redmoves, int bluemoves, struct move storered[100000], struct move storeblue[100000], int board[10][10])
{
    int i;
    int x1, y1, x2, y2;
    int j=redmoves+bluemoves;
    for(i=0;i<num_moves;i++)
    {
        if(j%2==0)                               //if the number of moves played is even then the second team's coins are to be moved first
        {
            x1 = storeblue[bluemoves-1].p1;
            y1 = storeblue[bluemoves-1].p2;
            x2 = storeblue[bluemoves-1].n1;
            y2 = storeblue[bluemoves-1].n2;
            Logic_2(2, x2, y2, x1, y1, board);     //using logic_2(yet to be implemented) as the normal logic function would not allow a backwards move
            if((x1-x2==2)||(x1-x2==-2))            //detects a jump and brings back a captured coin on undoing
            {
                board[(x1+x2)/2][(y1+y2)/2]=1;
            }
            PrintBoard(board);
            j--;
          bluemoves--;
        }
        else if(j%2==1)
        {
            x1 = storered[redmoves-1].p1;
            y1 = storered[redmoves-1].p2;
            x2 = storered[redmoves-1].n1;
            y2 = storered[redmoves-1].n2;
            Logic_2(1, x2, y2, x1, y1, board);
            if((x1-x2==2)||(x1-x2==-2))
            {
                board[(x1+x2)/2][(y1+y2)/2]=2;
            }
            PrintBoard(board);
            j--;
          redmoves--;
        }
    }
}
