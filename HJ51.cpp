#include<stdio.h>
int main()
{
    int n,a[1000],k;
    while(scanf("%d",&n) != EOF)
    {
        for (int i=0; i<n; i++)
        scanf("%d",&a[i]);
        scanf("%d",&k);
        printf("%d\n",a[n-k]);
    }
    return 0;
}
