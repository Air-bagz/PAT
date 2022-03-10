#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char s[1000][101];    //1000个长度100
bool cmp(char s1[],char s2[])
{
    return strcmp(s1,s2)<0;
}
void swap(char s1[],char s2[])
{
    char s[101];
    strcpy(s,s1);
    strcpy(s1,s2);
    strcpy(s2,s);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++)
        scanf("%s",s[i]);
 //   sort(s,s+n,cmp);    不让用
    for (int i=n-1; i>=1; i--)
    {
        for (int j=0; j<=i-1; j++)
            if (strcmp(s[j],s[j+1])>0)    
                swap(s[j],s[j+1]);
    }
    for (int i=0; i<n; i++)
        printf("%s\n",s[i]);
    return 0;
}
