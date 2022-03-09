#include<stdio.h>
int main()
{
    int hash[501]={0},n,x;
    scanf("%d",&n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d",&x);
        hash[x]++;
    }
    for (int i=1; i<=500; i++)
        if (hash[i]!=0)    printf("%d\n",i);
    return 0;
}
