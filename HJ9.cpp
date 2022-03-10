#include<stdio.h>
int main()
{
    bool hash[10]={0};        //0--9
    int n;
    scanf("%d",&n);
    int x=n % 10;
    while (x != 0)
    {
        if (hash[x]==false)    printf("%d",x);
        hash[x]=true;
        n=n/10;
        x=n%10;
    }
    return 0;
}
