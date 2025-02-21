#include <stdio.h>

int main(void)
{
	FILE* input=fopen("E:\\lab5\\BILL.INF","r") ;
	FILE* output=fopen("E:\\lab5\\output.txt","w") ;
	int n,a,b,c;
	float pa,pb,pc,total,sum=0;
	fprintf(output,"  Bill Number    Payment($)\n");
	fprintf(output,"=============================\n");
	while(fscanf(input,"%d%d%d%d",&n,&a,&b,&c)==4)
	{
		pa=4*a;
		pb=6*b;
		pc=5*c;
		if(a>100) pa*=0.98;
		if(b>200) pb*=0.95;
		if(c>150) pc*=0.90;
		total=pa+pb+pc;
		sum+=total;
		fprintf(output,"   %d           %.2f\n",n,total);
		fprintf(output,"__________________________\n");
	}
	fprintf(output,"Total payment: $%.2f\n",sum);
	return 0;
}