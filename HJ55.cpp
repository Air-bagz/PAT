#include<stdio.h>
#include<string.h>
bool baohan(int x)
{
    char s[10];
    sprintf(s,"%d",x);
    for (int i=0; i<strlen(s); i++)
        if (s[i]=='7')    return true;
    return false;
}
int main()
{
    int n,ans=0;
    scanf("%d",&n);
    for (int i=1; i<=n; i++)
    {
        if (baohan(i))    ans++;
        else if (i % 7==0)    ans++;
    }
    printf("%d",ans);
    return 0;
}
