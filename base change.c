#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(void)
{
    int m,base,i=199,f=0;
    char* result=(char*)malloc(sizeof(char)*200);
    memset(result,'0',200);
    scanf("%d",&m);
    scanf("%d",&base);
    if(m<0)
    {
        f=1;
        m=-m;
    }
    if(base>=9||base<=1)
    {
        return 1;
    }
    while(m)
    {
        result[i]+=m%base;
        i--;
        m/=base;
    }
    i=0;
    while(result[i]=='0')
    {
        i++;
    }
    if(f)
    {
        printf("-");
    }
    while(i<200)
    {
        printf("%c",result[i]);
        i++;
    }
    printf("\n");
    free(result);
    return 0;
}
