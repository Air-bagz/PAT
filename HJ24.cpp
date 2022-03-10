#include<stdio.h>
int max(int x,int y)
{
    if (x>y)    return x;
    else    return y;
}
int main()
{
    int A[3010],dp1[3010],dp2[3010],dp[3010];
    int n;
    scanf("%d",&n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d",&A[i]);
        dp1[i]=1;
        dp2[i]=1;
    }
    for (int i=1; i<=n; i++)
        for (int j=1; j<i; j++)
            if (A[j]<A[i])
                dp1[i]=max(dp1[j]+1,dp1[i]);
    for (int i=n; i>=1; i--)
        for (int j=n; j>i; j--)
            if (A[j]<A[i])
                dp2[i]=max(dp2[j]+1,dp2[i]);
//    for (int i=1; i<=n; i++)
//        printf("%d ",dp1[i]);
//    printf("\n");
//    for (int i=1; i<=n; i++)
//        printf("%d ",dp2[i]);
    for (int i=1; i<=n; i++)
        dp[i]=dp1[i]+dp2[i]-1;    //左+右-一个自己
//    for (int i=1; i<=n; i++)
//        printf("%d ",dp[i]);
    int Max=-1;
    for (int i=1; i<=n; i++)
        if (dp[i]>Max)    Max=dp[i];
    printf("%d",n-Max);
    return 0;
}
