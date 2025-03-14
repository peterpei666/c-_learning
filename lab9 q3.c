#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE* fp=fopen("E:\\lab9\\words.inf","r");
	char list[22][20];
	char temp[20];
	int i,j;
	for(i=0;i<22;i++)
	{
		fscanf(fp,"%s",list[i]);
	}
	for(i=0;i<22;i++)
	{
		for(j=0;j<21-i;j++)
		{
			if(strcmp(list[j],list[j+1])>0)
			{
				strcpy(temp,list[j]);
				strcpy(list[j],list[j+1]);
				strcpy(list[j+1],temp);
			}
		}
	}
	for(i=0;i<22;i++)
	{
		printf("%2d: %s\n",i+1,list[i]);
	}
	return 0;
}