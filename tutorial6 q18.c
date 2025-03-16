#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int dayofweek(int month,int year);

void calendar(int c[6][7],int month,int year)
{
    int i,j,day=1,start=dayofweek(month,year);
    memset(c,0,sizeof(int)*6*7);
    i=0;
    j=start-1;
    while(day<=30)
    {
        c[i][j]=day;
        j++;
        if(j>=7)
        {
            j-=7;
            i++;
        }
        day++;
    }
}
