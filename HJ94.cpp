//H={H*P+(s[i]-'A')}%MOD
#include<stdio.h>
#include<string.h>
const int P=1e7+19;
const int MOD=1e9+7;
long long hash(char s[])
{
    long long H=0;
    for (int i=0; i<strlen(s); i++)
    {
        H=( H*P+(s[i]-'A') ) % MOD;
    }
    return H;
}
int main()
{
    int n;
    scanf("%d",&n);
    char s[100][100];
    for (int i=0; i<n; i++)
        scanf("%s",s[i]);
    int a[100];    //依次存储每个候选人的哈希值
    for (int i=0; i<n; i++)
        a[i]=hash(s[i]);
    //for (int i=0; i<n; i++)
        //printf("%s %d\n",s[i],a[i]);
    int n2;
    scanf("%d",&n2);
    char ss[100][100];
    for (int i=0; i<n2; i++)
        scanf("%s",ss[i]);
    int b[100]={0},invalid=0;    //票数
    for (int i=0; i<n2; i++)
    {
        int k=hash(ss[i]);
        bool flag=false;
        for (int j=0; j<n; j++)
            if (a[j]==k)    
            {
                b[j]++;
                flag=true;
            }
        if (!flag)    invalid++;
    }
    for (int i=0; i<n; i++)
    {
        printf("%s : %d\n",s[i],b[i]);
    }
    printf("Invalid : %d",invalid);    
    //for (int i=0; i<n; i++)
        //printf("%d %d\n",a[i],b[i]);
    //printf("%d",sizeof(long long)); //4
    return 0;
}
