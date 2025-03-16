#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct table
{
    int bet[37];
};

struct table list;

int play(void)
{
    int outcome=0,i;
    int spin=rand()%37-1;
    for(i=0;i<37;i++)
    {
        outcome+=list.bet[i];
    }
    if(spin>0&&spin%2==1)
    {
        outcome-=36*list.bet[spin+1]+2*list.bet[0];
    }
    if(spin>0&&spin%2==0)
    {
        outcome-=36*list.bet[spin+1]+2*list.bet[1];
    }
    for(i=0;i<37;i++)
    {
        list.bet[i]=0;
    }
    return outcome;
}

int main(void)
{
    srand((unsigned int)time(NULL));
}
