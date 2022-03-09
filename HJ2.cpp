#include<stdio.h>
#include<string.h>
int main()
{
    char str[1010];
    scanf("%[^\n]",str);
    char ch;
    getchar();
    scanf("%c",&ch);
    int hash[256]={0};
    for (int i=0; i<strlen(str); i++)
    {
    	if (str[i]>='A'&&str[i]<='z')
        	str[i]=str[i]&0xDF;       //11011111    ¶¼±ä´óÐ´
        hash[str[i]]++;
    }
    if (ch>='A'&&ch<='z')
        ch=ch&0xDF;
    printf("%d",hash[ch]);
    return 0;
}
