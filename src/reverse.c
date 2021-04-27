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

void storage(int x1,int y1,int x2,int y2,int redmoves,int bluemoves, char player) //added the player variable
{
    if (player == 'RED')            
    {
       storered[redmoves].p1 = x1;
       storered[redmoves].p2 = y1;
       storered[redmoves].n1 = x2;
       storered[redmoves].n2 = y2;

       redmoves++;
    }


    if (player == 'BLUE')           
    {
       storeblue[bluemoves].p1 = x1;
       storeblue[bluemoves].p2 = y1;
       storeblue[bluemoves].n1 = x2;
       storeblue[bluemoves].n2 = y2;

       bluemoves++;
    }

}

void undo(int k, int redmoves, int bluemoves, Moves storered[100000], Moves storeblue[100000], int board[10][10])
{
    int i, j, x1, x2, y1, y2;

    Makeboard(board);

    while((i + j) < (redmoves + bluemoves - k))
    {
        if(((i + j) % 2) == 0)
        {
            x1 = storered->p1;
            y1 = storered->p2;
            x2 = storered->n1;
            y2 = storered->n2;

            Logic(RED, x1, y1, x2, y2, board);

            i++;
            PrintBoard(board);
        }

        else
        {
            x1 = storeblue->p1;
            y1 = storeblue->p2;
            x2 = storeblue->n1;
            y2 = storeblue->n2;

            Logic(BLUE, x1, y1, x2, y2, board);

            j++;
            PrintBoard(board);
        }
        
    }
}

void PlayerConsent(int P1, int P2)    //The undo function would only work when both player 1 and player 2 agree.
{
    if(P1 == 1 && P2 == 1)
    {
        undo(k, redmoves, bluemoves, storered, storeblue, board);
    }

    else
    {
        printf("Both players don't agree to undo the moves")
    }
    
}