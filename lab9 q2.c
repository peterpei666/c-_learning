#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[21];
	int len,i,f;
	while(1)
	{
		f=1;
		gets(str);
		len=(int)strlen(str);
		if(len==0)
		{
			break;
		}
		for(i=0;i<len/2;i++)
		{
			if(str[i]!=str[len-i-1])
			{
				printf("\"%s\" is not a palindrome\n",str);
				f=0;
				break;
			}
		}
		if(f)
		{
			printf("\"%s\" is a palindrome\n",str);
		}
		printf("\n");
	}
	return 0;
}