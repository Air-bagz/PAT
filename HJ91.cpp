#include<stdio.h>
int main()
{
    int n,m,dp[10][10];
    scanf("%d %d",&n,&m);
    dp[0][0]=0;
    for (int i=1; i<=n; i++)
        dp[i][0]=1;
    for (int j=1; j<=m; j++)
        dp[0][j]=1;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
    printf("%d",dp[n][m]);
    return 0;
}
