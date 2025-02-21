#include <stdio.h>

int main(void)
{
	char c;
	int flag=1;
	printf("Enter message: ");
	while((c=getchar())!='\n')
	{
		if(flag)
		{
			printf("Encrypted message: ");
			flag=0;
		}
		switch(c)
		{
			case 'a':
				printf("%c",'!');
				break;
			case 'e':
				printf("%c",'$');
				break;
			case 'i':
				printf("%c",'#');
				break;
			case 'o':
				printf("%c",'*');
				break;
			case 'u':
				printf("%c",'&');
				break;
			default:
				printf("%c",c);
				break;
		}
	}
	return 0;
}