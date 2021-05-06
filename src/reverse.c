#include <stdio.h>

typedef struct move Moves;

struct move                             //from the review function
{
 int p1;
 int p2;   
 int n1;
 int n2;
};           

struct move storered[100000];  
struct move storeblue[100000]; 
int redmoves,bluemoves;        

void storage(int x1,int y1,int x2,int y2,int redmoves,int bluemoves, int player) 
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

void undo(int k, int redmoves, int bluemoves, Moves storered[100000], Moves storeblue[100000], int board[10][10])  // k represents the number of moves the player wants to undo 
{
    int i, j, x1, x2, y1, y2;

    Makeboard(board);

    while((i + j) < (redmoves + bluemoves - k))
    {
        if(((i + j) % 2) == 0)
        {
            x1 = storered[i].p1;
            y1 = storered[i].p2;
            x2 = storered[i].n1;
            y2 = storered[i].n2;

            Logic(1, x1, y1, x2, y2, board);

            i++;
        }

        else
        {
            x1 = storeblue[j].p1;
            y1 = storeblue[j].p2;
            x2 = storeblue[j].n1;
            y2 = storeblue[j].n2;

            Logic(2, x1, y1, x2, y2, board);

            j++;
         
        }
     
        PrintBoard(board);
    }
}

void PlayerConsent(int P1, int P2)                                           //The undo function would only work when both player 1 and player 2 agree.
{
    if(P1 == 1 && P2 == 1)
    {
        undo(k, redmoves, bluemoves, storered, storeblue, board);
    }

    else
    {
        printf("Both players don't agree to undo the moves")
    }
 
    return;
}
