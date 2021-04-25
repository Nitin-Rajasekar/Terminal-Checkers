#include<stdio.h>
#include<stdlib.h>
#include<wchar.h>

void MakeBoard(int arr[10][10]){
    for (int i=0;i<10;i++){                                                     //makes the borders of the 10x10 board
        arr[0][i]=-2;                                                           //unreachable, making it 8x8.
        arr[9][i]=-2;
        arr[i][0]=-2;
        arr[i][9]=-2;
    }
    for (int i=1;i<9;i++){
        for (int j=1;j<9;j++){
            if((i+j)%2==0){
                arr[i][j]=-1;                                                   //-1 = forbidden
            }
            else if(i==1||i==2){
                arr[i][j]=2;                                                    //2 = upper player (B), 4 = B's crown
            }
            else if(i==7||i==8){
                arr[i][j]=1;                                                    //1 = lower player (A), 3 = A's crown
            }
            else arr[i][j]=0;                                                   //0 = empty block
        }
    }
}

void Logic(int player, int x1, int x2, int y1, int y2, int arr[10][10]){
    if(player==1){
        if(arr[x1][y1]==1){                                                     //non-crowned
            if((y2-y1==1)&&((x2-x1==1)||(x1-x2==1))){                           //not a jump
                if(arr[x2][y2]==0){
                    arr[x1][y1]=0;
                    arr[x2][y2]=1;
                }
                else /*code for invalid input*/;
            }
        }
    }
}