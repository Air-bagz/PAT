#include<stdio.h>
#include<string.h>
bool pd(int x)
{
    if (x>=0 && x<=255)
        return true;
    else return false;
}
int main()
{
    char s[40];
    scanf("%s",s);
    int x1=-1,x2=-1,x3=-1,x4=-1;
    sscanf(s,"%d.%d.%d.%d",&x1,&x2,&x3,&x4);		//û����ǰ��0����� 
    printf("%d %d %d %d",x1,x2,x3,x3,x4);
    if (pd(x1)&&pd(x2)&&pd(x3)&&pd(x4))
        printf("YES");
    else printf("NO");
    return 0;
}
