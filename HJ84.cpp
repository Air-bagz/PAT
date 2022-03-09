#include<stdio.h>
#include<string.h>
int main()
{
    char s[251];
    while(scanf("%[^\n]\n",s)!=EOF)
    {
        int ans=0;
        for (int i=0; i<strlen(s); i++)
            if (s[i]>='A'&&s[i]<='Z')    
                ans++;
        printf("%d\n",ans);
    }
    return 0;
}
