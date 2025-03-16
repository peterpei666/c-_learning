#include <stdio.h>
#include <stdlib.h>

int direction[4][2]={-1,0,1,0,0,1,0,-1};
int dfs(int** board,int boardSize,int* colSize,int x,int y)
{
    if(x<0||x>=boardSize||y<0||y>=colSize[x]||board[x][y])
    {
        return 0;
    }
    if(x==boardSize-1&&y==colSize[x]-1)
    {
        return 0;
    }
    board[x][y]=1;
    int d,row,col;
    for(d=0;d<4;d++)
    {
        row=x+direction[d][0];
        col=y+direction[d][1];
        if(dfs(board,boardSize,colSize,row,col))
        {
            return 1;
        }
    }
    return 0;
}

int find(int** board,int boardSize,int* colSize)
{
    return dfs(board,boardSize,colSize,0,0);
}
