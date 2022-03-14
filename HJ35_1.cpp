#include<stdio.h>
int main()
{
    int a[101],n;
    scanf("%d",&n);
    for (int i=1; i<=n; i++)
        a[i]=i*(i+1)/2;    //打好第一行的表
    for (int i=1; i<=n; i++)    //n行
    {
        for (int j=i; j<=n; j++)
            printf("%d ",a[j]-(i-1));
        printf("\n");
    }
    return 0;
}
/*
    a1  a2    a3     a4     a5
        a2-1  a3-1   a4-1   a5-1
              a3-1-1 a4-1-1 a5-1-1 
              */
