# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define n 8

void restore(int grid[n][n],int x,int y)
{
    if(x>=n||y>=n)
    {
        return;
    }
    int temp;
    if(x+1<n&&grid[x+1][y]<grid[x][y])
    {
        temp=grid[x][y];
        grid[x][y]=grid[x+1][y];
        grid[x+1][y]=temp;
        restore(grid,x+1,y);
    }
    if(y+1<n&&grid[x][y+1]<grid[x][y])
    {
        temp=grid[x][y];
        grid[x][y]=grid[x][y+1];
        grid[x][y+1]=temp;
        restore(grid,x,y+1);
    }
}

int main(void)
{
    int G[n][n];
    int i,j,m,temp;
    int i1,j1;
    long checksum,sorted;
    srand((unsigned int)time(NULL));
    for (j=0; j<n; j++)
    {
        for (i=0; i<n; i++)
        {
            G[i][j] = rand()%200;
        }
    }
    printf ("\n\nRaw Data:\n");
    checksum=0;
    for (i1=0; i1<n; i1++)
    {
        for ( j1=0; j1<n; j1++)
        {
            printf ("%5d",G[i1][j1]);
            checksum += G[i1][j1];
        }
        printf ("\n");
    }
    printf ("Checksum = %ld",checksum);
    for(i=0;i<n;i++)
    {
        for(m=1;m<n;m++)
        {
            for(j=0;j<n-m;j++)
            {
                if(G[i][j]>G[i][j+1])
                {
                    temp=G[i][j];
                    G[i][j]=G[i][j+1];
                    G[i][j+1]=temp;
                }
            }
        }
    }
    printf ("\n\nAfter row sort:\n");
    checksum=0;
    for (i1=0; i1<n; i1++)
    {
        for (j1=0; j1<n; j1++)
        {
            printf ("%5d",G[i1][j1]);
            checksum += G[i1][j1];
        }
        printf ("\n");
    }
    printf ("Checksum = %ld",checksum);
    for(i=0;i<n;i++)
    {
        for(m=1;m<n;m++)
        {
            for(j=0;j<n-m;j++)
            {
                if(G[j][i]>G[j+1][i])
                {
                    temp=G[j][i];
                    G[j][i]=G[j+1][i];
                    G[j+1][i]=temp;
                }
            }
        }
    }
    printf ("\n\nAfter column sort:\n");
    checksum=0;
    for ( i1=0; i1<n; i1++)
    {
        for (j1=0; j1<n; j1++)
        {
            printf ("%5d",G[i1][j1]);
            checksum += G[i1][j1];
        }
        printf ("\n");
    }
    printf ("Checksum = %ld",checksum);
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n;j++)
        {
            if(G[i][j]>G[i+1][0])
            {
                temp=G[i][j];
                G[i][j]=G[i+1][0];
                G[i+1][0]=temp;
                restore(G,i+1,0);
            }
        }
    }
    printf ("\n\nAfter interchange and restoration:\n");
    checksum=0;
    sorted =1;
    for (i1=0; i1<n; i1++)
    {
        for (j1=0; j1<n; j1++)
        {
            printf ("%5d",G[i1][j1]);
            checksum += G[i1][j1];
            if (! ( i1==(n-1) && j1 == (n-1) ) )
            {
                if ( *(&G[0][0] + i1*n +j1) > *(&G[0][0] + i1*n +j1 + 1) )
                {
                    sorted =0;
                }
            }
        }
        printf ("\n");
    }
    printf ("Checksum = %ld",checksum);
    if(sorted==1)
    {
        printf ("   sorted\n\n");
    }
    else
    {
        printf ("    not sorted\n\n");
    }
    return 0;
}

