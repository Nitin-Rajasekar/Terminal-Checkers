#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

int jump_made;

void MakeBoard(int arr[10][10])
{
    for (int i = 0; i < 10; i++)
    {                           //makes the borders of the 10x10 board
        arr[0][i] = -2;         //unreachable, making it 8x8 for players.
        arr[9][i] = -2;
        arr[i][0] = -2;
        arr[i][9] = -2;
    }
    for (int i = 1; i < 9; i++)
    {
        for (int j = 1; j < 9; j++)
        {
            if ((i + j) % 2 == 0)
            {
                arr[i][j] = -1; //-1 = forbidden
            }
            else if (i == 1 || i == 2 || i == 3)
            {
                arr[i][j] = 2; //2 = upper player (B), 4 = B's crown
            }
            else if (i == 7 || i == 8 || i == 6)
            {
                arr[i][j] = 1; //1 = lower player (A), 3 = A's crown
            }
            else
                arr[i][j] = 0; //0 = empty block
        }
    }
}

// functions for colouring pieces
// call the function when we want the next output to be of that colour
// call reset to reset the colour to white
void red () {
  printf("\033[1;31m");
}

void blue() {
  printf("\033[1;33m");
}

void reset () {
  printf("\033[0m");
}

void PrintBoard(int arr[10][10])
{
    printf("\n\t ");
    for (int i=1;i<=8;i++){        //printing A-H horizontally for users' convenience
        printf(" %c ",(char)(i+64));
    }
    printf("\n");
    for (int i = 1; i < 9; i++)
    {
        printf("%c\t",9-i);       //printing 8-1 vertically (downwards)
        for (int j = 0; j < 9; j++)
        {
            if (arr[i][j] == -1)
                printf("\u2588\u2588 ");    //opaque block for inacessible squares
            if (arr[i][j] == 0)
                printf("   ");              //empty
            if (arr[i][j] == 1)
                printf("\u24D0  ");         //player 1
            if (arr[i][j] == 2)
                printf("\u24D1  ");         //player 2
            if (arr[i][j] == 3)
                printf("\u24B6  ");         //player 1 (crown)
            if (arr[i][j] == 4)
                printf("\u24B7  ");         //player 2 (crown)
        }
        printf("\n");
    }
    printf("\n");
}

//Note: x represents row's position, y represents column's. 
void Logic(int player, int x1, int x2, int y1, int y2, int arr[10][10])
{                  //player on turn, coordinates are parameters
    jump_made = 0; //becomes 1 if a jump is made
    if (player == 1)
    { //x1,y1 = current position; x2,y2 = desired
        if (arr[x1][y1] == 1)
        { //non-crowned
            if ((y2 - y1 == 1) && ((x2 - x1 == 1) || (x1 - x2 == 1)))
            { //not a jump
                if (arr[x2][y2] == 0)
                {
                    arr[x1][y1] = 0;
                    arr[x2][y2] = 1;
                }
                else /*code for invalid input*/
                    ;
            }
            else if (y2 - y1 == 2)
            { //jump
                if (x2 - x1 == 2)
                { //right jump
                    if ((arr[x1 + 1][y1 + 1] == 2 || arr[x1 + 1][y1 + 1] == 4) && (arr[x2][y2] == 0))
                    {
                        arr[x1 + 1][y1 + 1] = 0; //removing the opponent's pawn
                        arr[x2][y2] = 1;
                        arr[x1][y1] = 0;
                        jump_made = 1;
                    }
                    else /*code for invalid input*/
                        ;
                }
                else if (x1 - x2 == 2)
                { //left jump
                    if ((arr[x1 - 1][y1 + 1] == 2 || arr[x1 - 1][y1 + 1] == 4) && (arr[x2][y2] == 0))
                    {
                        arr[x1 - 1][y1 + 1] = 0; //removing the opponent's pawn
                        arr[x2][y2] = 1;
                        arr[x1][y1] = 0;
                        jump_made = 1;
                    }
                    else /*code for invalid input*/
                        ;
                }
                else /*code for invalid input*/
                    ;
            }
            else /*code for invalid input*/
                ;
        }
        else if (arr[x1][y1] == 3)
        { //crowned
            if (((y2 - y1 == 1) || (y1 - y2 == 1)) && ((x2 - x1 == 1) || (x1 - x2 == 1)))
            { //non-jump
                if (arr[x2][y2] == 0)
                {
                    arr[x1][y1] = 0;
                    arr[x2][y2] = 3;
                    jump_made = 1;
                }
                else /*code for invalid input*/
                    ;
            }
            else if (y2 - y1 == 2)
            { //forward jump
                if (x2 - x1 == 2)
                {
                    if ((arr[x1 + 1][y1 + 1] == 2 || arr[x1 + 1][y1 + 1] == 4) && (arr[x2][y2] == 0))
                    {
                        arr[x1 + 1][y1 + 1] = 0;
                        arr[x2][y2] = 3;
                        arr[x1][y1] = 0;
                        jump_made = 1;
                    }
                    else /*code for invalid input*/
                        ;
                }
                else if (x1 - x2 == 2)
                {
                    if ((arr[x1 - 1][y1 + 1] == 2 || arr[x1 - 1][y1 + 1] == 4) && (arr[x2][y2] == 0))
                    {
                        arr[x1 - 1][y1 + 1] = 0;
                        arr[x2][y2] = 3;
                        arr[x1][y1] = 0;
                        jump_made = 1;
                    }
                    else /*code for invalid input*/
                        ;
                }
                else /*code for invalid input*/
                    ;
            }
            else if (y1 - y2 == 2)
            { //backward jump
                if (x2 - x1 == 2)
                {
                    if ((arr[x1 + 1][y2 + 1] == 2 || arr[x1 + 1][y2 + 1] == 4) && (arr[x2][y2] == 0))
                    {
                        arr[x1 + 1][y2 + 1] = 0;
                        arr[x2][y2] = 3;
                        arr[x1][y1] = 0;
                        jump_made = 1;
                    }
                    else /*code for invalid input*/
                        ;
                }
                else if (x1 - x2 == 2)
                {
                    if ((arr[x1 - 1][y2 + 1] == 2 || arr[x1 - 1][y2 + 1] == 4) && (arr[x2][y2] == 0))
                    {
                        arr[x1 - 1][y2 + 1] = 0;
                        arr[x2][y2] = 3;
                        arr[x1][y1] = 0;
                        jump_made = 1;
                    }
                    else /*code for invalid input*/
                        ;
                }
                else /*code for invalid input*/
                    ;
            }
            else /*code for invalid input*/
                ;
        }
        else /*code for invalid input*/
            ;
        if (x2 == 1 && arr[x2][y2] == 1)
        {
            arr[x2][y2] = 3; //creates king for player 1
            jump_made = 0;   //because when a new king is made, the players turn terminates irrespective of whether he made a jump
                             //so jump_made is 0 so that the player cannot make an extra jump
        }
    }
    else if (player == 2)
    {
        if (arr[x1][y1] == 2)
        { //non-crowned
            if ((y1 - y2 == 1) && ((x2 - x1 == 1) || (x1 - x2 == 1)))
            { //not a jump
                if (arr[x2][y2] == 0)
                {
                    arr[x1][y1] = 0;
                    arr[x2][y2] = 2;
                    jump_made = 1;
                }
                else /*code for invalid input*/
                    ;
            }
            else if (y1 - y2 == 2)
            { //jump
                if (x2 - x1 == 2)
                { //right jump
                    if ((arr[x1 + 1][y2 + 1] == 1 || arr[x1 + 1][y2 + 1] == 3) && (arr[x2][y2] == 0))
                    {
                        arr[x1 + 1][y2 + 1] = 0; //removing the opponent's pawn
                        arr[x2][y2] = 2;
                        arr[x1][y1] = 0;
                        jump_made = 1;
                    }
                    else /*code for invalid input*/
                        ;
                }
                else if (x1 - x2 == 2)
                { //left jump
                    if ((arr[x1 - 1][y2 + 1] == 1 || arr[x1 - 1][y2 + 1] == 3) && (arr[x2][y2] == 0))
                    {
                        arr[x1 - 1][y1 + 1] = 0; //removing the opponent's pawn
                        arr[x2][y2] = 2;
                        arr[x1][y1] = 0;
                        jump_made = 1;
                    }
                    else /*code for invalid input*/
                        ;
                }
                else /*code for invalid input*/
                    ;
            }
            else /*code for invalid input*/
                ;
        }
        else if (arr[x1][y1] == 4)
        { //crowned
            if (((y2 - y1 == 1) || (y1 - y2 == 1)) && ((x2 - x1 == 1) || (x1 - x2 == 1)))
            { //non-jump
                if (arr[x2][y2] == 0)
                {
                    arr[x1][y1] = 0;
                    arr[x2][y2] = 4;
                    jump_made = 1;
                }
                else /*code for invalid input*/
                    ;
            }
            else if (y2 - y1 == 2)
            { //forward jump
                if (x2 - x1 == 2)
                {
                    if ((arr[x1 + 1][y1 + 1] == 1 || arr[x1 + 1][y1 + 1] == 3) && (arr[x2][y2] == 0))
                    {
                        arr[x1 + 1][y1 + 1] = 0;
                        arr[x2][y2] = 4;
                        arr[x1][y1] = 0;
                        jump_made = 1;
                    }
                    else /*code for invalid input*/
                        ;
                }
                else if (x1 - x2 == 2)
                {
                    if ((arr[x1 - 1][y1 + 1] == 1 || arr[x1 - 1][y1 + 1] == 3) && (arr[x2][y2] == 0))
                    {
                        arr[x1 - 1][y1 + 1] = 0;
                        arr[x2][y2] = 4;
                        arr[x1][y1] = 0;
                        jump_made = 1;
                    }
                    else /*code for invalid input*/
                        ;
                }
                else /*code for invalid input*/
                    ;
            }
            else if (y1 - y2 == 2)
            { //backward jump
                if (x2 - x1 == 2)
                {
                    if ((arr[x1 + 1][y2 + 1] == 1 || arr[x1 + 1][y2 + 1] == 3) && (arr[x2][y2] == 0))
                    {
                        arr[x1 + 1][y2 + 1] = 0;
                        arr[x2][y2] = 4;
                        arr[x1][y1] = 0;
                        jump_made = 1;
                    }
                    else /*code for invalid input*/
                        ;
                }
                else if (x1 - x2 == 2)
                {
                    if ((arr[x1 - 1][y2 + 1] == 1 || arr[x1 - 1][y2 + 1] == 3) && (arr[x2][y2] == 0))
                    {
                        arr[x1 - 1][y2 + 1] = 0;
                        arr[x2][y2] = 4;
                        arr[x1][y1] = 0;
                        jump_made = 1;
                    }
                    else /*code for invalid input*/
                        ;
                }
                else /*code for invalid input*/
                    ;
            }
            else /*code for invalid input*/
                ;
        }
        else /*code for invalid input*/
            ;
        if (x2 == 8 && arr[x2][y2] == 2)
        {
            arr[x2][y2] = 4; //creates king for player 2;
            jump_made = 0;
        }
    }
}

int check_possible_jump(int arr[10][10], int player_no) //utility function to check if it is possible for a player to make a jump, in which case a non-jump move would be invalid
{
    int possible_jump = 0; //becomes 1 if a jump is available
    int i, j;
    if (player_no == 1)
    {
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 10; j++)
            {
                if (arr[i][j] == 1)
                {
                    if (arr[i - 1][j - 1] == 2 && arr[i - 2][j - 2] == 0)
                        possible_jump = 1;
                    if (arr[i + 1][j + 1] == 2 && arr[i + 2][j + 2] == 0)
                        possible_jump = 1;
                    if (arr[i + 1][j - 1] == 2 && arr[i + 2][j - 2] == 0)
                        possible_jump = 1;
                    if (arr[i - 1][j + 1] == 2 && arr[i - 2][j + 2] == 0)
                        possible_jump = 1;
                }
            }
        }
    }

    else if (player_no == 2)
    {
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 10; j++)
            {
                if (arr[i][j] == 2)
                {
                    if (arr[i - 1][j - 1] == 1 && arr[i - 2][j - 2] == 0)
                        possible_jump = 1;
                    if (arr[i + 1][j + 1] == 1 && arr[i + 2][j + 2] == 0)
                        possible_jump = 1;
                    if (arr[i + 1][j - 1] == 1 && arr[i + 2][j - 2] == 0)
                        possible_jump = 1;
                    if (arr[i - 1][j + 1] == 1 && arr[i - 2][j + 2] == 0)
                        possible_jump = 1;
                }
            }
        }
    }
    return possible_jump;
}

/*void UserInput() //accepts user inputs and generates coordinates
{
    char c1, c2;
    int x1, x2, y1, y2;
    printf("Enter starting and destination positions: ");
    //removed the line specifying format as we'll only print that once.
    scanf("%c%d %c%d", &c1, &y1, &c2, &y2);
    x1 = c1 - 64;
    x2 = c2 - 64;
    //need to pass the coordinates into a doubly linked list now, each node
    //of which will be used as input for logic function. Need to preserve the
    //list for use in functions like review, undo.
}*/

void UserInput_new() //accepts user inputs and generates coordinates
{
    int arr[10][10];
    int player_no = 1;
    int result_obtained = 0;
    char c1, c2;
    int x1, x2, y1, y2;
    MakeBoard(arr);
    PrintBoard(arr);
    while (result_obtained != 1) //result_obtained becomes 1 when a player has won, this functionality has not been implemented yet
    {
        printf("Player %d enter starting and destination positions: ", player_no);

        scanf("%c%d %c%d", &c1, &x1, &c2, &x2);
        while (getchar() != '\n') //flush buffer
            ;

        y1 = c1 - 64;
        y2 = c2 - 64;
        x1 = 9 - x1;
        x2 = 9 - x2;
        //printf("Co-ordinates are %d %d %d %d\n", x1, y1, x2, y2);
        Logic(player_no, x1, x2, y1, y2, arr);
        PrintBoard(arr);
        if (player_no == 1 && (jump_made == 0 || check_possible_jump(arr, 1) == 0)) //if a player makes a jump AND could make another he should, so he gets another turn
            player_no = 2;                                                          //jump_made is global, its 1 if a jump has been made
        else if (player_no == 2 && (jump_made == 0 || check_possible_jump(arr, 2) == 0))
            player_no = 1;
    }
}

int main()
{
    
    printf("   cccccccc     hhh     hhh     eeeeeeeee      cccccccc    kkk    kkk    eeeeeeeee     rrrrrrrrr     sssssssss\n");
    printf("  cccccccc      hhh     hhh     eeeeeeeee     cccccccc     kkk   kkk     eeeeeeeee     rrr    rrr    sssssssss\n");  
    printf(" ccc            hhh     hhh     eee          ccc           kkk  kkk      eee           rrr    rrr    ss\n"); 
    printf("ccc             hhhhhhhhhhh     eee         ccc            kkk kkk       eee           rrr    rrr    ss\n");
    printf("ccc             hhhhhhhhhhh     eeeeeeeee   ccc            kkkkkk        eeeeeeeee     rrrrrrrrr     sssssssss\n");
    printf(" ccc            hhh     hhh     eee          ccc           kkk kkk       eee           rrr    rrr           ss\n");
    printf("  ccc           hhh     hhh     eee           ccc          kkk  kkk      eee           rrr     rrr          ss\n");
    printf("   cccccccc     hhh     hhh     eeeeeeeee      cccccccc    kkk   kkk     eeeeeeeee     rrr      rrr  sssssssss\n");
    printf("    cccccccc    hhh     hhh     eeeeeeeee       cccccccc   kkk    kkk    eeeeeeeee     rrr       rrr sssssssss\n");

    
    UserInput_new();
}
