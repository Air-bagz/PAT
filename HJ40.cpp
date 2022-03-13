#include<stdio.h>
#include<string.h>
int main()
{
    char s[1001];
    scanf("%[^\n]",s);
    int ans1=0,ans2=0,ans3=0,ans4=0;
    for (int i=0; i<strlen(s); i++)
    {
        if ( (s[i]>='A' && s[i]<='Z')||(s[i]>='a' && s[i]<='z') )    
            ans1++;
        else if (s[i]==' ')    ans2++;
            else if (s[i]>='0' && s[i]<='9')    ans3++;
                else if (s[i]>0 && s[i]<=255)    ans4++;    //s[strlen(s)]='\0'==0
    }
    printf("%d\n%d\n%d\n%d",ans1,ans2,ans3,ans4);
    return 0;
}
