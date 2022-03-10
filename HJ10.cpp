#include<stdio.h>
#include<string.h>
int main()
{
    char s[501];    //³¤500
    bool hash[128]={0};    //0--127
    scanf("%s",s);
    for (int i=0; i<strlen(s); i++)
    {
        if (s[i]>=0 && s[i]<=127)
            hash[s[i]]=true;
    }
    int ans=0;
    for (int i=0; i<=127; i++)
    {
        if (hash[i])    ans++;
    }
    printf("%d",ans);
    return 0;
}
