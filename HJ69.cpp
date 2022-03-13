#include<stdio.h>
int main()
{
    int x,y,z,A[105][105]={0},B[105][105]={0};
    scanf("%d %d %d",&x,&y,&z);
    for (int i=1; i<=x; i++)
        for (int j=1; j<=y; j++)
            scanf("%d",&A[i][j]);
    for (int i=1; i<=y; i++)
        for (int j=1; j<=z; j++)
            scanf("%d",&B[i][j]);
    int C[105][105]={0};
    for (int i=1; i<=x; i++)
        for (int j=1; j<=z; j++)
        {
            for (int k=1; k<=y; k++)
                C[i][j]+=A[i][k]*B[k][j];
        }
    for (int i=1; i<=x; i++)
    {
        for (int j=1; j<=z; j++)
        {
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
    return 0;
}
