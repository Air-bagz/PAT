#include<stdio.h>
#include<string.h>
int main()
{
    char s[12];
    scanf("%s",s);
    int len=strlen(s);
    int weight=1;    //Î»È¨³õÖµ
    int ans=0;
    for (int i=len-1; i>=2; i--)
    {
        if (s[i]>='0'&&s[i]<='9')    ans=ans+(s[i]-'0')*weight;
        else if(s[i]>='A'&&s[i]<='F')    ans=ans+(s[i]-'A'+10)*weight;
        weight=weight*16;
    }
    printf("%d",ans);
    return 0;
}
