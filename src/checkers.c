#include<stdio.h>
#include<stdlib.h>
#include<wchar.h>

void MakeBoard(int arr[10][10]){
    for (int i=0;i<10;i++){                                                         //makes the borders of the 10x10 board
        arr[0][i]=-2;                                                               //unreachable, making it 8x8.
        arr[9][i]=-2;
        arr[i][0]=-2;
        arr[i][9]=-2;
    }
    for (int i=1;i<9;i++){
        for (int j=1;j<9;j++){
            if((i+j)%2==0){
                arr[i][j]=-1;                                                       //-1 = forbidden
            }
            else if(i==1||i==2||i==3){
                arr[i][j]=2;                                                        //2 = upper player (B), 4 = B's crown
            }
            else if(i==7||i==8||i==6){
                arr[i][j]=1;                                                        //1 = lower player (A), 3 = A's crown
            }
            else arr[i][j]=0;                                                       //0 = empty block
        }
    }
}

void PrintBoard(int arr[10][10]){
    printf("\n");
    for (int i=1;i<9;i++){
        printf("\t");
        for (int j=0;j<9;j++){
            if (arr[i][j]==-1) printf("\u2588\u2588 ");
            if (arr[i][j]== 0) printf("   ");
            if (arr[i][j]== 1) printf("\u24D0  ");
            if (arr[i][j]== 2) printf("\u24D1  ");
            if (arr[i][j]== 3) printf("\u24B6  ");
            if (arr[i][j]== 4) printf("\u24B7  ");
        }
        printf("\n");
    }
    printf("\n");
}

void Logic(int player, int x1, int x2, int y1, int y2, int arr[10][10]){            //player on turn, coordinates are parameters
    if(player==1){                                                                  //x1,y1 = current position; x2,y2 = desired
        if(arr[x1][y1]==1){                                                         //non-crowned
            if((y2-y1==1)&&((x2-x1==1)||(x1-x2==1))){                               //not a jump
                if(arr[x2][y2]==0){
                    arr[x1][y1]=0;
                    arr[x2][y2]=1;
                }
                else /*code for invalid input*/;
            }
            else if(y2-y1==2){                                                      //jump
                if(x2-x1==2){                                                       //right jump
                    if((arr[x1+1][y1+1]==2||arr[x1+1][y1+1]==4)&&(arr[x2][y2]==0)){
                        arr[x1+1][y1+1]=0;                                          //removing the opponent's pawn
                        arr[x2][y2]=1;
                        arr[x1][y1]=0;
                    }
                    else /*code for invalid input*/;
                }
                else if (x1-x2==2){                                                 //left jump
                    if((arr[x1-1][y1+1]==2||arr[x1-1][y1+1]==4)&&(arr[x2][y2]==0)){
                        arr[x1-1][y1+1]=0;                                          //removing the opponent's pawn
                        arr[x2][y2]=1;
                        arr[x1][y1]=0;
                    }
                    else /*code for invalid input*/;
                }
                else /*code for invalid input*/;
            }
            else /*code for invalid input*/;
        }
        else if(arr[x1][y1]==3){                                                    //crowned
            if(((y2-y1==1)||(y1-y2==1))&&((x2-x1==1)||(x1-x2==1))){                 //non-jump                         
                if(arr[x2][y2]==0){
                    arr[x1][y1]=0;
                    arr[x2][y2]=3;
                }
                else /*code for invalid input*/;
            }
            else if(y2-y1==2){                                                      //forward jump                                         
                if(x2-x1==2){                                                      
                    if((arr[x1+1][y1+1]==2||arr[x1+1][y1+1]==4)&&(arr[x2][y2]==0)){
                        arr[x1+1][y1+1]=0;                                          
                        arr[x2][y2]=3;
                        arr[x1][y1]=0;
                    }
                    else /*code for invalid input*/;
                }
                else if (x1-x2==2){                                                 
                    if((arr[x1-1][y1+1]==2||arr[x1-1][y1+1]==4)&&(arr[x2][y2]==0)){
                        arr[x1-1][y1+1]=0;                                          
                        arr[x2][y2]=3;
                        arr[x1][y1]=0;
                    }
                    else /*code for invalid input*/;
                }
                else /*code for invalid input*/;
            }
            else if(y1-y2==2){                                                      //backward jump                                          
                if(x2-x1==2){                                                      
                    if((arr[x1+1][y2+1]==2||arr[x1+1][y2+1]==4)&&(arr[x2][y2]==0)){
                        arr[x1+1][y2+1]=0;                                          
                        arr[x2][y2]=3;
                        arr[x1][y1]=0;
                    }
                    else /*code for invalid input*/;
                }
                else if (x1-x2==2){                                                 
                    if((arr[x1-1][y2+1]==2||arr[x1-1][y2+1]==4)&&(arr[x2][y2]==0)){
                        arr[x1-1][y2+1]=0;                                          
                        arr[x2][y2]=3;
                        arr[x1][y1]=0;
                    }
                    else /*code for invalid input*/;
                }
                else /*code for invalid input*/;
            }
            else /*code for invalid input*/;
        }
        else /*code for invalid input*/;
        if (x2 == 8 && arr[x2][y2] == 1)
            arr[x2][y2] = 3; //creates king for player 1
    }
    else if(player==2){
        if(arr[x1][y1]==2){                                                         //non-crowned
            if((y1-y2==1)&&((x2-x1==1)||(x1-x2==1))){                               //not a jump
                if(arr[x2][y2]==0){
                    arr[x1][y1]=0;
                    arr[x2][y2]=2;
                }
                else /*code for invalid input*/;
            }
            else if(y1-y2==2){                                                      //jump
                if(x2-x1==2){                                                       //right jump
                    if((arr[x1+1][y2+1]==1||arr[x1+1][y2+1]==3)&&(arr[x2][y2]==0)){
                        arr[x1+1][y2+1]=0;                                          //removing the opponent's pawn
                        arr[x2][y2]=2;
                        arr[x1][y1]=0;
                    }
                    else /*code for invalid input*/;
                }
                else if (x1-x2==2){                                                 //left jump
                    if((arr[x1-1][y2+1]==1||arr[x1-1][y2+1]==3)&&(arr[x2][y2]==0)){
                        arr[x1-1][y1+1]=0;                                          //removing the opponent's pawn
                        arr[x2][y2]=2;
                        arr[x1][y1]=0;
                    }
                    else /*code for invalid input*/;
                }
                else /*code for invalid input*/;
            }
            else /*code for invalid input*/;
        }
        else if(arr[x1][y1]==4){                                                    //crowned
            if(((y2-y1==1)||(y1-y2==1))&&((x2-x1==1)||(x1-x2==1))){                 //non-jump                         
                if(arr[x2][y2]==0){
                    arr[x1][y1]=0;
                    arr[x2][y2]=4;
                }
                else /*code for invalid input*/;
            }
            else if(y2-y1==2){                                                      //forward jump                                         
                if(x2-x1==2){                                                      
                    if((arr[x1+1][y1+1]==1||arr[x1+1][y1+1]==3)&&(arr[x2][y2]==0)){
                        arr[x1+1][y1+1]=0;                                          
                        arr[x2][y2]=4;
                        arr[x1][y1]=0;
                    }
                    else /*code for invalid input*/;
                }
                else if (x1-x2==2){                                                 
                    if((arr[x1-1][y1+1]==1||arr[x1-1][y1+1]==3)&&(arr[x2][y2]==0)){
                        arr[x1-1][y1+1]=0;                                          
                        arr[x2][y2]=4;
                        arr[x1][y1]=0;
                    }
                    else /*code for invalid input*/;
                }
                else /*code for invalid input*/;
            }
            else if(y1-y2==2){                                                      //backward jump                                          
                if(x2-x1==2){                                                      
                    if((arr[x1+1][y2+1]==1||arr[x1+1][y2+1]==3)&&(arr[x2][y2]==0)){
                        arr[x1+1][y2+1]=0;                                          
                        arr[x2][y2]=4;
                        arr[x1][y1]=0;
                    }
                    else /*code for invalid input*/;
                }
                else if (x1-x2==2){                                                 
                    if((arr[x1-1][y2+1]==1||arr[x1-1][y2+1]==3)&&(arr[x2][y2]==0)){
                        arr[x1-1][y2+1]=0;                                          
                        arr[x2][y2]=4;
                        arr[x1][y1]=0;
                    }
                    else /*code for invalid input*/;
                }
                else /*code for invalid input*/;
            }
            else /*code for invalid input*/;
        }
        else /*code for invalid input*/;
        if (x2 == 1 && arr[x2][y2] == 2)
            arr[x2][y2] = 4; //creates king for player 2;
    }
}

void UserInput() //accepts user inputs and generates coordinates
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
}
