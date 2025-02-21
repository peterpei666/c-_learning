#include <stdio.h>

void menu(void)
{
	printf("   Currency Conversion\n");
	printf("1.  Customer sells CNY\n");
	printf("2.  Customer buys CNY\n");
	printf("3.  Quit\n");
	printf("Enter your choice:");
}

int main(void)
{
	int option,flag=1;
	float a;
	
	while(flag)
	{
		menu();
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("How much CNY are you selling? ");
				scanf("%f",&a);
				printf("For %.2f CNY you will get %.2f SGD\n\n",a,a/1000.0*201);
				break;
			case 2:
				printf("How much SGD do you have? ");
				scanf("%f",&a);
				printf("For %.2f SGD you will get %.2f SGD\n\n",a,a/100.0*490);
				break;
			case 3:
				flag=0;
				break;
			default:
				printf("Invalid command\n\n");
				break;
		}
	}
	return 0;
}