#include <stdio.h>

int main(void)
{
	int list[]={9,9,9,15,15,15,15,5,5,5,5,12,12,12,12};
	int n,m,a,price,i;
	float total=0;
	char c;
	
	FILE* input=fopen("E:\\lab5\\MEDICINE.INF","r") ;
	FILE* output=fopen("E:\\lab5\\output2.txt","w") ;
	fprintf(output,"  Bill NO.       Payment($)\n");
	fprintf(output,"=============================\n");
	
	while(fscanf(input,"%d%d",&n,&m)==2)
	{
		fscanf(input,"%c",&c);
		total=0;
		for(i=0;i<m;i++)
		{
			fscanf(input,"%c%d",&c,&a);
			price=a*list[c-'A'];
			total+=price;
		}
		fprintf(output,"   %d           %.2f\n",n,total);
		printf("   %d           %.2f\n",n,total);
	}
	
	return 0;
}