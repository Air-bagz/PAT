#include<stdio.h>
#include<string.h>
int main()
{
    char s[1001][1001];
    int num=1;
    while (scanf("%s",s[num])!=EOF)
    {
        num++;
    }
    for (int i=num-1; i>=1; i--)
        printf("%s ",s[i]);
    return 0;
}
