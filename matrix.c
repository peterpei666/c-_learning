// matrix.c

// compute product and the transpose of product.

# include <stdio.h>

int main(void)
{
	int A[3][4] = { 1, 2,  3,  1,
	                0, 1, -5,  2,
				    6, 2,  0, -2} ;
	               
	int B[4][3] = { 1,  0, -1,
 	                0,  1,  1,
				    2,  3,  4,
				    0, -1,  0} ;
	int ans[3][3]={0},anst[3][3];
	int i,j,m;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			for(m=0;m<4;m++)
			{
				ans[i][j]+=A[i][m]*B[m][j];
			}
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			anst[i][j]=ans[j][i];
		}
	}
	printf("      AXB      \n");
	printf("===============\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf(" %3d",ans[i][j]);
		}
		printf("\n");
	}
	printf("Transpose(AXB)\n");
	printf("==============\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf(" %3d",anst[i][j]);
		}
		printf("\n");
	}



	return 0;
}
