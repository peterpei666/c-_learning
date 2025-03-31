#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;
    char letter;
    char code[7];
    FILE* fp=fopen("bomb.inf","r");
    while(fscanf(fp,"%s",&letter))
    {
        printf("%c    ",letter);
        fscanf(fp,"%s",code);
        for(i=0;i<6;i++)
        {
            code[i]-=i+1;
            if(code[i]<'0')
            {
                code[i]+=10;
            }
        }
        printf("%s\n",code);
    }
    return 0;
}
