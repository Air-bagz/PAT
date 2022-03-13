#include<stdio.h>
#include<math.h>
bool pd(int n)
{
    int sum=1;    //Ô¼Êý1
    for (int i=2; i<=int(sqrt(n)); i++)
    {
        if (n % i==0)
            sum=sum+(i+n/i);
    }
    if (sum==n)    return true;
    else return false;
}
int main()
{
    int n,ans[100],num;
    scanf("%d",&n);
    for (int i=2; i<=n; i++)
        if (pd(i))
            ans[num++]=i;
    //for (int i=0; i<num; i++)
        //printf("%d ",ans[i]);
    printf("%d",num);
    return 0;
}
