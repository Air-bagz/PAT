#include<stdio.h>
#include<string.h>
int main()
{
    char s1[50];
    int x1,x2,x3,x4;
    scanf("%s",s1);
    sscanf(s1,"%d.%d.%d.%d",&x1,&x2,&x3,&x4);
    printf("%ld",x1*256*256*256+x2*256*256+x3*256+x4);//<<24    <<16    <<8
    printf("\n");
    unsigned int n;
    scanf("%d",&n);
    x4=n%256;
    n=n/256;
    x3=n%256;
    n=n/256;
    x2=n%256;
    n=n/256;
    x1=n%256;
    n=n/256;
    printf("%d.%d.%d.%d",x1,x2,x3,x4);
    return 0;
}
