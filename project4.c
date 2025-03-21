#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

void insert(char*** words,int* count)
{
    int capacity=10,i=0;
    *words=(char**)malloc(capacity*sizeof(char*));
    while(1)
    {
        if(i>=capacity-1)
        {
            capacity+=10;
            *words=(char**)realloc(*words,capacity*sizeof(char*));
        }
        (*words)[i]=(char*)malloc(MAX*sizeof(char));
        scanf("%s",(*words)[i]);
        i++;
        if((*words)[i-1][strlen((*words)[i-1])-1]=='.')
        {
            (*words)[i-1][strlen((*words)[i-1])-1]='\0';
            break;
        }
    }
    *count=i;
}

void lower_letter(char** words,int size)
{
    int i,j;
    for(i=0;i<size;i++)
    {
        for(j=0;j<strlen(words[i]);j++)
        {
            if(words[i][j]<='Z'&&words[i][j]>='A')
            {
                words[i][j]+='a'-'A';
            }
        }
    }
}

void into_board(int board[26][26],char** words,int size)
{
    int i,j,x,y;
    for(i=0;i<26;i++)
    {
        for(j=0;j<26;j++)
        {
            board[i][j]=0;
        }
    }
    for(i=0;i<size;i++)
    {
        for(j=0;j<strlen(words[i])-1;j++)
        {
            x=words[i][j]-'a';
            y=words[i][j+1]-'a';
            board[x][y]++;
        }
    }
}

void ignore(int* x,int* y,int board[26][26])
{
    int i,j;
    *x=0;
    *y=0;
    for(i=0;i<=26;i++)
    {
        for(j=0;j<=26;j++)
        {
            if(board[i][j])
            {
                *x+=1<<i;
                break;
            }
        }
    }
    for(i=0;i<=26;i++)
    {
        for(j=0;j<=26;j++)
        {
            if(board[j][i])
            {
                *y+=1<<i;
                break;
            }
        }
    }
}

void print(int board[26][26],int x,int y)
{
    int i,j;
    printf("  ");
    for(i=0;i<26;i++)
    {
        if(y&(1<<i))
        {
            printf("  %c",'a'+i);
        }
    }
    printf("\n");
    for(i=0;i<26;i++)
    {
        if(x&(1<<i))
        {
            printf("%c ",'a'+i);
            for(j=0;j<26;j++)
            {
                if(y&(1<<j))
                {
                    printf("%3d",board[i][j]);
                }
            }
            printf("\n");
        }
    }
}

int main(void)
{
    char** words=NULL;
    int count,x,y,i;
    int board[26][26];
    insert(&words,&count);
    lower_letter(words,count);
    into_board(board,words,count);
    for(i=0;i<count;i++)
    {
        free(words[i]);
    }
    free(words);
    ignore(&x,&y,board);
    print(board,x,y);
}
