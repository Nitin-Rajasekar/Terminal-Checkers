#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

struct move
{
    int p1;
    int p2;
    int n1;
    int n2;
};                             // storing the initial and final places
struct move storered[100000];  // array for storing red moves
struct move storeblue[100000]; // array for storing blue moves
int jump_made;
void MakeBoard(int arr[10][10])
{
    for (int i = 0; i < 10; i++)
    {                   //makes the borders of the 10x10 board
        arr[0][i] = -2; //unreachable, making it 8x8 for players.
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
void red()
{
    printf("\033[1;31m");
}

void yellow()
{
    printf("\033[1;33m");
}

void green()
{
    printf("\033[1;32m");
}

void blue()
{
    printf("\033[1;34m");
}

void reset()
{
    printf("\033[0m");
}

void printcolour(int colour)
{

    if (colour == 1)
        printf("\033[1;31m");

    else if (colour == 2)
        printf("\033[1;33m");

    else if (colour == 3)
        printf("\033[1;32m");

    else if (colour == 4)
        printf("\033[1;34m");
}

int choosecolour()
{
    printf("THE COLOURS AVAILABLE ARE \n\n");
    red();
    printf("\u2588\u2588 - R "); // 1
    yellow();
    printf("\u2588\u2588 - Y "); // 2
    green();
    printf("\u2588\u2588 - G "); // 3
    blue();
    printf("\u2588\u2588 - B\n\n"); // 4
    reset();

    char colour[7];
    printf("ENTER THE COLOUR YOU WANT\n");
    scanf("%s", colour);

    if (strcmp(colour, "R") == 0)
    {
        return 1;
    }
    if (strcmp(colour, "Y") == 0)
    {
        return 2;
    }
    if (strcmp(colour, "G") == 0)
    {
        return 3;
    }
    if (strcmp(colour, "B") == 0)
    {
        return 4;
    }
}

int p1_colour, p2_colour;

void player1_colour()
{
    p1_colour = choosecolour();
}

void player2_colour()
{

    int k = choosecolour();
    if (k != p1_colour)
    {
        p2_colour = k;
    }
    else
    {
        printf("THE COLOUR IS ALREADY TAKEN CHOOSE ANOTHER \n\n");
        choosecolour();
    }
}

/*void Instructions()
{
    printf("--------------------------------------INSTRUCTIONS-------------------------------------------------\n");
    
    printf("TO REVIEW THE GAME PRESS R\n");
    printf("TO VIEW THE RULES PRESS V\n");
    printf("TO UNDO ANY NUMBER OF MOVES PRESS U \n");
    printf("TO FIND ALL POSSIBLE MOVES FOR NEXT K MOVES PRESS W \n");
    printf("TO VIEW THE INSTRUCTIONS PRESS U\n");
}


void PrintBoard(int arr[10][10])
{
     reset();
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

                printcolour(p1_colour);
            if (arr[i][j] == 1)
                printf("\u24D0  ");         //player 1
                reset();

                printcolour(p2_colour);
            if (arr[i][j] == 2)
                printf("\u24D1  ");         //player 2
                reset();

                printcolour(p1_colour);
            if (arr[i][j] == 3)
                printf("\u24B6  ");         //player 1 (crown)
                 reset();

                printcolour(p2_colour);
            if (arr[i][j] == 4)
                printf("\u24B7  ");         //player 2 (crown)
                reset();
        }
        printf("\n");
    }
    printf("\n");
}*/

void Instructions()
{
    printf("--------------------------------------INSTRUCTIONS-------------------------------------------------\n");

    printf("TO REVIEW THE GAME PRESS R\n");
    printf("TO VIEW THE RULES PRESS V\n");
    printf("TO UNDO ANY NUMBER OF MOVES PRESS U \n");
    printf("TO FIND ALL POSSIBLE MOVES FOR NEXT K MOVES PRESS W \n");
    printf("TO VIEW THE INSTRUCTIONS PRESS U\n");
}

void PrintBoard(int arr[10][10])
{
    printf("\n\t");
    for (int i = 1; i <= 8; i++)
    { //printing A-H horizontally for users' convenience
        printf("%c  ", (char)(i + 64));
    }
    printf("\n");
    for (int i = 1; i < 9; i++)
    {
        printf("%d \t", i); //printing 1-8 vertically (downwards)
        // This way the input corresponds directly to the array's indices
        for (int j = 0; j < 9; j++)
        {
            if (arr[i][j] == -1)
                printf("\u2588\u2588 "); //opaque block for inacessible squares
            if (arr[i][j] == 0)
                printf("   "); //empty

            printcolour(p1_colour);
            if (arr[i][j] == 1)
                printf("\u24D0  "); //player 1
            reset();

            printcolour(p2_colour);
            if (arr[i][j] == 2)
                printf("\u24D1  "); //player 2
            reset();

            printcolour(p1_colour);
            if (arr[i][j] == 3)
                printf("\u24B6  "); //player 1 (crown)
            reset();

            printcolour(p2_colour);
            if (arr[i][j] == 4)
                printf("\u24B7  "); //player 2 (crown)
            reset();
        }
        printf("\n");
    }
    printf("\n");
}

//Note: x represents column, y represents row
int Logic(int player, int x1, int x2, int y1, int y2, int arr[10][10]) //might wanna consider making it return 0 or 1 for validity
{                                                                      //player on turn, coordinates, board are parameters

    jump_made = 0; //becomes 1 if a jump is made
    if (player == 1)
    { //x1,y1 = current position; x2,y2 = desired
        if (arr[y1][x1] == 1)
        {                                                             //non-crowned
            if ((y1 - y2 == 1) && ((x2 - x1 == 1) || (x1 - x2 == 1))) //y2 will be above y1, hence smaller index coz 2d array
            {                                                         //not a jump
                if (arr[y2][x2] == 0)
                {
                    arr[y1][x1] = 0;
                    arr[y2][x2] = 1;
                }
                else
                    return 0;
            }
            else if (y1 - y2 == 2)
            { //jump
                if (x2 - x1 == 2)
                { //right jump
                    if ((arr[y2 + 1][x1 + 1] == 2 || arr[y2 + 1][x1 + 1] == 4) && (arr[y2][x2] == 0))
                    {
                        arr[y2 + 1][x1 + 1] = 0; //removing the opponent's pawn from [y2+1][x1+1]
                        arr[y2][x2] = 1;
                        arr[y1][x1] = 0;
                        jump_made = 1;
                    }
                    else
                        return 0;
                }
                else if (x1 - x2 == 2)
                { //left jump
                    if ((arr[y2 + 1][x1 - 1] == 2 || arr[y2 + 1][x1 - 1] == 4) && (arr[y2][x2] == 0))
                    {
                        arr[y2 + 1][x1 - 1] = 0; //removing the opponent's pawn
                        arr[y2][x2] = 1;
                        arr[y1][x1] = 0;
                        jump_made = 1;
                    }
                    else
                        return 0;
                }
                else
                    return 0;
            }
            else
                return 0;
        }
        else if (arr[x1][y1] == 3)
        { //crowned
            if (((y2 - y1 == 1) || (y1 - y2 == 1)) && ((x2 - x1 == 1) || (x1 - x2 == 1)))
            { //non-jump
                if (arr[y2][x2] == 0)
                {
                    arr[y1][x1] = 0;
                    arr[y2][x2] = 3;
                }
                else
                    return 0;
            }
            else if (y2 - y1 == 2)
            {                     //backward jump
                if (x2 - x1 == 2) //right jump
                {
                    if ((arr[y1 + 1][x1 + 1] == 2 || arr[y1 + 1][x1 + 1] == 4) && (arr[y2][x2] == 0))
                    {
                        arr[y1 + 1][x1 + 1] = 0;
                        arr[y2][x2] = 3;
                        arr[y1][x1] = 0;
                        jump_made = 1;
                    }
                    else
                        return 0;
                }
                else if (x1 - x2 == 2) //left
                {
                    if ((arr[y1 + 1][x1 - 1] == 2 || arr[y1 + 1][x1 - 1] == 4) && (arr[y2][x2] == 0))
                    {
                        arr[y1 + 1][x1 - 1] = 0;
                        arr[y2][x2] = 3;
                        arr[y1][x1] = 0;
                        jump_made = 1;
                    }
                    else
                        return 0;
                }
                else
                    return 0;
            }
            else if (y1 - y2 == 2)
            {                     //forward jump
                if (x2 - x1 == 2) //right
                {
                    if ((arr[y2 + 1][x1 + 1] == 2 || arr[y2 + 1][x1 + 1] == 4) && (arr[y2][x2] == 0))
                    {
                        arr[y2 + 1][x1 + 1] = 0;
                        arr[y2][x2] = 3;
                        arr[y1][x1] = 0;
                        jump_made = 1;
                    }
                    else
                        return 0;
                }
                else if (x1 - x2 == 2) //left
                {
                    if ((arr[y2 + 1][x1 - 1] == 2 || arr[y2 + 1][x1 - 1] == 4) && (arr[y2][x2] == 0))
                    {
                        arr[y2 + 1][x1 - 1] = 0;
                        arr[y2][x2] = 3;
                        arr[y1][x1] = 0;
                        jump_made = 1;
                    }
                    else
                        return 0;
                }
                else
                    return 0;
            }
            else
                return 0;
        }
        else
            return 0;
        if (y2 == 1 && arr[y2][x2] == 1)
        {
            arr[y2][x2] = 3; //creates king for player 1
            jump_made = 0;   //because when a new king is made, the players turn terminates irrespective of whether he made a jump
                             //so jump_made is 0 so that the player cannot make an extra jump
        }
    }
    else if (player == 2)
    {
        if (arr[y1][x1] == 2)
        { //non-crowned
            if ((y2 - y1 == 1) && ((x2 - x1 == 1) || (x1 - x2 == 1)))
            { //not a jump
                if (arr[y2][x2] == 0)
                {
                    arr[y1][x1] = 0;
                    arr[y2][x2] = 2;
                    //jump_made = 1;
                }
                else
                    return 0;
            }
            else if (y2 - y1 == 2)
            { //jump
                if (x2 - x1 == 2)
                { //right jump
                    if ((arr[y1 + 1][x1 + 1] == 1 || arr[y1 + 1][x1 + 1] == 3) && (arr[y2][x2] == 0))
                    {
                        arr[y1 + 1][x1 + 1] = 0; //removing the opponent's pawn
                        arr[y2][x2] = 2;
                        arr[y1][x1] = 0;
                        jump_made = 1;
                    }
                    else
                        return 0;
                }
                else if (x1 - x2 == 2)
                { //left jump
                    if ((arr[y1 + 1][x2 + 1] == 1 || arr[y1 + 1][x2 + 1] == 3) && (arr[y2][x2] == 0))
                    {
                        arr[y1 + 1][x2 + 1] = 0; //removing the opponent's pawn
                        arr[y2][x2] = 2;
                        arr[y1][x1] = 0;
                        jump_made = 1;
                    }
                    else
                        return 0;
                }
                else
                    return 0;
            }
            else
                return 0;
        }
        else if (arr[y1][x1] == 4)
        { //crowned
            if (((y2 - y1 == 1) || (y1 - y2 == 1)) && ((x2 - x1 == 1) || (x1 - x2 == 1)))
            { //non-jump
                if (arr[y2][x2] == 0)
                {
                    arr[y1][x1] = 0;
                    arr[y2][x2] = 4;
                }
                else
                    return 0;
            }
            else if (y2 - y1 == 2)
            {                     //forward jump
                if (x2 - x1 == 2) //right
                {
                    if ((arr[y1 + 1][x1 + 1] == 1 || arr[y1 + 1][x1 + 1] == 3) && (arr[y2][x2] == 0))
                    {
                        arr[y1 + 1][x1 + 1] = 0;
                        arr[y2][x2] = 4;
                        arr[y1][x1] = 0;
                        jump_made = 1;
                    }
                    else
                        return 0;
                }
                else if (x1 - x2 == 2) //left
                {
                    if ((arr[y1 + 1][x2 + 1] == 1 || arr[y1 + 1][x2 + 1] == 3) && (arr[y2][x2] == 0))
                    {
                        arr[y1 + 1][x2 + 1] = 0;
                        arr[y2][x2] = 4;
                        arr[y1][x1] = 0;
                        jump_made = 1;
                    }
                    else
                        return 0;
                }
                else
                    return 0;
            }
            else if (y1 - y2 == 2)
            { //backward jump
                if (x2 - x1 == 2)
                {
                    if ((arr[y2 + 1][x1 + 1] == 1 || arr[y2 + 1][x1 + 1] == 3) && (arr[y2][x2] == 0))
                    {
                        arr[y2 + 1][x1 + 1] = 0;
                        arr[y2][x2] = 4;
                        arr[y1][x1] = 0;
                        jump_made = 1;
                    }
                    else
                        return 0;
                }
                else if (x1 - x2 == 2)
                {
                    if ((arr[y2 + 1][x2 + 1] == 1 || arr[y2 + 1][x2 + 1] == 3) && (arr[y2][x2] == 0))
                    {
                        arr[y2 + 1][x2 + 1] = 0;
                        arr[y2][x2] = 4;
                        arr[y1][x1] = 0;
                        jump_made = 1;
                    }
                    else
                        return 0;
                }
                else
                    return 0;
            }
            else
                return 0;
        }
        else
            return 0;
        if (x2 == 8 && arr[x2][y2] == 2)
        {
            arr[y2][x2] = 4; //creates king for player 2;
            jump_made = 0;
        }
    }
    return 1;
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
                    if (arr[i - 1][j + 1] == 2 && arr[i - 2][j + 2] == 0)
                        possible_jump = 1;
                }
                else if (arr[i][j] == 3)
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
                    if (arr[i + 1][j - 1] == 1 && arr[i + 2][j - 2] == 0)
                        possible_jump = 1;
                    if (arr[i + 1][j + 1] == 1 && arr[i + 2][j + 2] == 0)
                        possible_jump = 1;
                }
                else if (arr[i][j] == 4)
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
int check_possible_jump_specific(int arr[10][10], int player_no, int x, int y) //check_possible_jump but for a specific position
{
    int possible_jump = 0; //becomes 1 if a jump is available
    if (player_no == 2 && arr[x][y] == 2)
    {

        if (arr[x + 1][y + 1] == 1 && arr[x + 2][y + 2] == 0)
            possible_jump = 1;
        if (arr[x + 1][y - 1] == 1 && arr[x + 2][y - 2] == 0)
            possible_jump = 1;
    }
    else if (player_no == 2 && arr[x][y] == 4)
    {
        if (arr[x - 1][y - 1] == 1 && arr[x - 2][y - 2] == 0)
            possible_jump = 1;
        if (arr[x + 1][y + 1] == 1 && arr[x + 2][y + 2] == 0)
            possible_jump = 1;
        if (arr[x + 1][y - 1] == 1 && arr[x + 2][y - 2] == 0)
            possible_jump = 1;
        if (arr[x - 1][y + 1] == 1 && arr[x - 2][y + 2] == 0)
            possible_jump = 1;
    }
    else if (player_no == 1 && arr[x][y] == 1)
    {
        if (arr[x - 1][y - 1] == 2 && arr[x - 2][y - 2] == 0)
            possible_jump = 1;
        if (arr[x - 1][y + 1] == 2 && arr[x - 2][y + 2] == 0)
            possible_jump = 1;
    }
    else if (player_no == 1 && arr[x][y] == 3)
    {
        if (arr[x - 1][y - 1] == 2 && arr[x - 2][y - 2] == 0)
            possible_jump = 1;
        if (arr[x + 1][y + 1] == 2 && arr[x + 2][y + 2] == 0)
            possible_jump = 1;
        if (arr[x + 1][y - 1] == 2 && arr[x + 2][y - 2] == 0)
            possible_jump = 1;
        if (arr[x - 1][y + 1] == 2 && arr[x - 2][y + 2] == 0)
            possible_jump = 1;
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
int check_if_player_lost(int arr[10][10], int player_no)
{
    int flag = 1; //becomes zero if player has a move left;
    int i, j;
    if (check_possible_jump(arr, player_no) == 1)
        flag = 0;

    if (player_no == 1)
    {
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 10; j++)
            {
                if (arr[i][j] == 1)
                {
                    if (arr[i - 1][j - 1] == 0)
                        flag = 0;
                    if (arr[i - 1][j + 1] == 0)
                        flag = 0;
                }
                else if (arr[i][j] == 3)
                {
                    if (arr[i - 1][j - 1] == 0)
                        flag = 0;
                    if (arr[i - 1][j + 1] == 0)
                        flag = 0;
                    if (arr[i + 1][j - 1] == 0)
                        flag = 0;
                    if (arr[i + 1][j + 1] == 0)
                        flag = 0;
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
                if (arr[i][j] == 1)
                {
                    if (arr[i + 1][j - 1] == 0)
                        flag = 0;
                    if (arr[i + 1][j + 1] == 0)
                        flag = 0;
                }
                else if (arr[i][j] == 3)
                {
                    if (arr[i - 1][j - 1] == 0)
                        flag = 0;
                    if (arr[i - 1][j + 1] == 0)
                        flag = 0;
                    if (arr[i + 1][j - 1] == 0)
                        flag = 0;
                    if (arr[i + 1][j + 1] == 0)
                        flag = 0;
                }
            }
        }
    }
    return flag;
}
void UserInput_new() //accepts user inputs and generates coordinates
{
    int arr[10][10];
    int player_no = 1;
    int result_obtained = 0;
    char c1, c2;
    int x1, x2, y1, y2;
    int x_store, y_store;
    int multiple_jump = 0; //becomes 1 when on a multiple jump
    MakeBoard(arr);
    PrintBoard(arr);

    /* Note- Added the extra functions to userinterface, few struct etc we need for other function in the interface,pls check if anything else is missing   */

    while (check_if_player_lost(arr, player_no) != 1) //result_obtained becomes 1 when a player has won
    {
        int redmoves = 0;
        int bluemoves = 0;
    retry:
        printf("Player %d enter starting and destination positions: ", player_no);

        scanf(" %c%d %c%d", &c1, &y1, &c2, &y2);

        if (c1 == 'X' && y1 == 0 && c2 == 'X' && y2 == 0) // If thre user enters X0 X0 then they get access to the functions
        {
            char ch;
            Instructions();    // To help the user we are displaying the Instructions once again
            printf("Enter :"); // User needs to enter the char corresponding to the function they need to access
            scanf(" %c", &ch);

            if (ch == 'R') // If the function needed is review the whole game from the starting
            {
                //review(redmoves , bluemoves, storered,storeblue , player_no);
            }
            else if (ch == 'V') // To see the rules of the game
            {
                //rules(); //need to create
            }
            else if (ch == 'U') // To undo moves,here u can undo any no of moves,user needs to enter the number of undos they want to do
            {
                printf("Enter the number of moves you would like to undo:");
                int num_moves; // number of moves to undo
                scanf("%d", &num_moves);

                //undo(num_moves, redmoves, bluemoves, storered, storeblue, board);
            }
            else if (ch == 'W') // To see the next possible moves
            {
                printf("How many next possible moves would you like to see, enter the number:");
                int n; // The number of next possible moves user wants to see
                scanf("%d", &n);
                //all_possible_moves(); // need to create
            }
            else if (ch == 'U')
            {
                Instructions();
            }
        }
        else
        {
            while (getchar() != '\n') //flush buffer
                ;

            x1 = c1 - 64; //converting from A-H to 1-8
            x2 = c2 - 64;

            //printf("Co-ordinates are %d %d %d %d\n", x1, y1, x2, y2);
            if (check_possible_jump(arr, player_no) == 1 && ((x1 - x2) != 2 && (x2 - x1) != 2))
            {
                printf("If there is an opportunity to jump, one must take it\n");
                continue;
            }
            if (multiple_jump == 1)
            {
                if (x1 != x_store || y1 != y_store)
                {
                    printf("In a multiple jump you can only jump with the coin you had used in your previous turn\n");
                    continue;
                }
            }
            int valid = Logic(player_no, x1, x2, y1, y2, arr); // Plays the move, stores "valid"
                                                               // storage(x1, y1, x2, y2, redmoves, bluemoves, player_no);  // storing all the moves to be used in other functions
            if (valid == 1)
                PrintBoard(arr); // Prints the board
            else
            {
                goto retry;
            }

            if (player_no == 1 && (jump_made == 0 || check_possible_jump_specific(arr, 1, x2, y2) == 0)) //if a player makes a jump AND could make another he should, so he gets another turn
            {
                player_no = 2; // go to the next player
                redmoves++;    // increasing the number of moves made by red

            } //jump_made is global, its 1 if a jump has been made
            else if (player_no == 2 && (jump_made == 0 || check_possible_jump_specific(arr, 2, x2, y2) == 0))
            {
                player_no = 1; // go to the next player
                bluemoves++;   // increasing the number of moves made by blue
            }
            if (jump_made == 1 && check_possible_jump_specific(arr, player_no, x2, y2) == 1) //player is going to get another turn
            {
                multiple_jump = 1;
                x_store = x2;
                y_store = y2;
            }
            else
            {
                multiple_jump = 0;
            }
        }
    }
}

/* while (result_obtained != 1) //result_obtained becomes 1 when a player has won, this functionality has not been implemented yet
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
    }*/
//}

int main()
{
    printf("\n\n");
    red();
    printf("   cccccccc     hhh     hhh     eeeeeeeee      cccccccc    kkk    kkk    eeeeeeeee     rrrrrrrrr     sssssssss\n");
    printf("  cccccccc      hhh     hhh     eeeeeeeee     cccccccc     kkk   kkk     eeeeeeeee     rrr    rrr    sssssssss\n");
    printf(" ccc            hhh     hhh     eee          ccc           kkk  kkk      eee           rrr    rrr    ss\n");
    printf("ccc             hhhhhhhhhhh     eee         ccc            kkk kkk       eee           rrr    rrr    ss\n");
    printf("ccc             hhhhhhhhhhh     eeeeeeeee   ccc            kkkkkk        eeeeeeeee     rrrrrrrrr     sssssssss\n");
    printf(" ccc            hhh     hhh     eee          ccc           kkk kkk       eee           rrr    rrr           ss\n");
    printf("  ccc           hhh     hhh     eee           ccc          kkk  kkk      eee           rrr     rrr          ss\n");
    printf("   cccccccc     hhh     hhh     eeeeeeeee      cccccccc    kkk   kkk     eeeeeeeee     rrr      rrr  sssssssss\n");
    printf("    cccccccc    hhh     hhh     eeeeeeeee       cccccccc   kkk    kkk    eeeeeeeee     rrr       rrr sssssssss\n");

    reset();
    printf("\n\n");

    player1_colour();
    player2_colour();

    reset();
    printf("\n\n\n\n");
    yellow();
    printf("<>---<>-----<>----<>------THE GAME IS STARTING ----<>----<>-----<>-----<>\n");
    printf("\n\n");

    printf("*******ENTER X0 X0 FOR INSTRUCTIONS AND OTHER FUNCTIONS*******\n");
    reset();
    /* Note-It looks a bit messy need to change it a little bit */
    UserInput_new();
}
