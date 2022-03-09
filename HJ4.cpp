#include<stdio.h>
#include<string.h>
int main()
{
    char s[120],add[10];
    scanf("%s",s);
    if (strlen(s)==0)    return 0;
    int i=strlen(s)/8;
    int j=strlen(s)%8;
    if (j!=0)    
       for (int k=0; k<8-j; k++)
           add[k]='0';
       add[8-j]='\0';
    strcat(s,add);
    for (int k=0; k<strlen(s); k++)
    {
        if (k>0&& k%8==0)    printf("\n");
        printf("%c",s[k]);
    }
    printf("\n");
    return 0;
}
