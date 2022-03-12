#include<stdio.h>
int max(int x,int y)
{
    if (x>y)    return x;
    else return y;
}
int main()
{
    int n,A[201];
    int dp[201];
    scanf("%d",&n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d",&A[i]);
        dp[i]=1;
    }
    for (int i=2; i<=n; i++)
        for (int j=1; j<i; j++)
            if (A[j]<A[i])
                dp[i]=max(dp[j]+1,dp[i]);
    int ans=-1;
    for (int i=1; i<=n; i++)
        if (dp[i]>ans)    ans=dp[i];
    printf("%d",ans);
    return 0;
}
