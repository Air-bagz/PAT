#include<stdio.h>
#include<string.h>
typedef struct bignum
{
    int d[10000];
    int len;
    bignum()
    {
        memset(d,0,sizeof(d));
        len=0;
    }
}bignum;
void change(char s[],bignum &a)
{
    for (int i=0; i<strlen(s); i++)
    {
        a.d[i]=s[strlen(s)-1-i]-'0';
        a.len++;
    }
}
void plus(bignum a, bignum b, bignum &c)
{
    int carry=0;
    for (int i=0; i<a.len || i<b.len ; i++)
    {
        int tmp;
        tmp=a.d[i]+b.d[i]+carry;
        c.d[i]=tmp % 10;
            c.len++;
        carry=tmp / 10;
    }
    if (carry>0)
    {
        c.d[c.len]=carry;
        c.len++;
    }
}
int main()
{
    char s1[1001],s2[1001];
    scanf("%s%s",s1,s2);
    bignum a,b;
    change(s1,a);
    change(s2,b);
    bignum c;
    plus(a,b,c);
    for (int i=c.len-1; i>=0; i--)
        printf("%d",c.d[i]);
    return 0;
}
