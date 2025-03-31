#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isArmstrong(int x)
{
    int temp=x,sum=0,m;
    while(temp)
    {
        m=temp%10;
        sum+=m*m*m;
        temp/=10;
    }
    return sum==x;
}

int main(void)
{
    int m;
    scanf("%d",&m);
    if(m<0||isArmstrong(m))
    {
        printf("%d is not an armstrong number\n",m);
    }
    else
    {
        printf("%d is an armstrong number\n",m);
    }
    return 0;
}
