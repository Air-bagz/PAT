#include<stdio.h>
#include<string.h>
int main()
{
    char s[201],ds[201][201];
    while (scanf("%s",s)!=EOF)
    {
        int ans=-1;
        int num=0;
        for (int i=0; i<strlen(s); i++)
        {
            if (s[i]>='0'&&s[i]<='9')
            {
                num++;    
                int len=0;
                while (s[i]>='0'&&s[i]<='9')
                {
                    ds[num][len++]=s[i++];
                }//while
                ds[num][len]='\0';
                if (len>ans)    ans=len;
            }//if
        }//for
        for (int i=1; i<=num; i++)
            if (strlen(ds[i])==ans)
                printf("%s",ds[i]);
        printf(",%d\n",ans);
    }//while
    return 0;
}
