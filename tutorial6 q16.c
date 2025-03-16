#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* p1,const void* p2)
{
    char* a=(char*)p1;
    char* b=(char*)p2;
    return *a-*b;
}

int isSub(char* str1,char* str2)
{
    int i,j;
    int len1=(int)strlen(str1);
    int len2=(int)strlen(str2);
    qsort(str1,len1,sizeof(char),compare);
    qsort(str2,len2,sizeof(char),compare);
    if(len1>len2)
    {
        return 0;
    }
    for(i=0,j=0;i<len1;i++)
    {
        while(j<len2&&str2[j]!=str1[i])
        {
            j++;
        }
        if(j==len2)
        {
            return 0;
        }
        j++;
    }
    return 1;
}

