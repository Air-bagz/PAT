//segment error 
#include<stdio.h>
int main()
{
    int hash[11112]={0};
    int n;
    scanf("%d",&n);
    for (int i=1; i<=n; i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        hash[a]=hash[a]+b;
    }
    for (int i=0; i<=11112; i++)
        if (hash[i]>0)
            printf("%d %d\n",i,hash[i]);
    return 0;
}
