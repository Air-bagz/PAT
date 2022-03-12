#include<stdio.h>
#include<string.h>
char s[301];
int len_score(char s[])
{
    if (strlen(s)<=4)    return 5;
    else if (strlen(s)>=5 && strlen(s)<=7)    return 10;
        else     return 25;
}
int alpha_score(char s[])
{
    int num1=0,num2=0;
    for (int i=0; i<strlen(s); i++)
    {
        if (s[i]>='a' && s[i]<='z')    num1++;
        if (s[i]>='A' && s[i]<='Z')    num2++;
    }
    if (num1==0 && num2==0)    return 0;
    else if (num1==0 || num2==0)    return 10;
        else return 20;
}
int digit_score(char s[])
{
    int num=0;
    for (int i=0; i<strlen(s); i++)
        if (s[i]>='0' && s[i]<='9')    num++;
    if (num==0)    return 0;
    else if (num==1) return 10;
        else return 20;
}
int symbol_score(char s[])
{
    int num=0;
    for (int i=0; i<strlen(s); i++)
        if ( (s[i]>=0x21 && s[i]<=0x2F)||(s[i]>=0x3A && s[i]<=0x40)||(s[i]>=0x5B && s[i]<=0x60)||(s[i]>=0x7B && s[i]<=0x7E) )   num++;
    if (num==0)    return 0;
    else if (num==1) return 10;
        else return 25;
}
int main()
{
    scanf("%s",s);
    int ans=0;
    ans=ans+len_score(s)+alpha_score(s)+digit_score(s)+symbol_score(s);
    int reward;
    if (alpha_score(s)==20 && digit_score(s)>0 && symbol_score(s)>0)
        reward=5;
    else if (alpha_score(s)==10 && digit_score(s)>0 && symbol_score(s)>0)
        reward=3;
        else if (alpha_score(s)>0 && digit_score(s)>0)
            reward=2;
    ans=ans+reward;
    if (ans>=90)    printf("VERY_SECURE");
    else if (ans>=80)    printf("SECURE");
        else if (ans>=70)    printf("VERY_STRONG");
            else if (ans>=60)    printf("STRONG");
                else if (ans>=50)    printf("AVERAGE");
                    else if (ans>=25)    printf("WEAK");
                        else printf("VERY_WEAK");
    //printf("%d",ans);
    return 0;
}
