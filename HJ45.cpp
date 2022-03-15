#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
bool cmp(int x, int y)
{
    return x>y;
}
int beauty(char s[])
{
    int hash[125]={0};        //'a'---'z'    97---122
    for (int i=0; i<strlen(s); i++)
        hash[s[i]]++;
    int num=0,a[26];
    for (int i=97; i<=122; i++)
        if (hash[i]>0)    
        {
            a[num]=hash[i];
            num++;
        }
    sort(a,a+num,cmp);
    int ans=0;
    for (int i=0; i<num; i++)
        ans=ans+a[i]*(26-i);
    return ans;
}
int main()
{
    int n;
    scanf("%d",&n);
    char s[10010];
    for (int i=1; i<=n; i++)
    {
        scanf("%s",s);
        int ans=beauty(s);
        printf("%d\n",ans);
    }
    return 0;
}
