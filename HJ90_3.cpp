//满分代码2022/3/12 
#include<stdio.h>
#include<string.h>
char s[100];
int point[5]={0};
bool point_num(char s[])
{
    int num=0;
    for (int i=0; i<strlen(s); i++)
        if (s[i]=='.')    
        {
            num++;
            point[num]=i;
        }
    if (num==3)   return  true;
    else return false;
}
bool pd(int x)
{
    if (x>=0 && x<=255)
        return true;
    else return false;
}
bool pd_0(int st, int en)        //判断前导零
{
    char temp[10]="",ss[10];
    for (int i=st; i<en; i++)
    {
        sprintf(ss,"%c",s[i]);    //字符转字符串
        strcat(temp,ss);        //strcat(temp,s[i])不可以
    }
    if (strlen(temp)>1 && (temp[0]<='0' || temp[0]>'9') )        //前导0以及+-符号
        return false;
    return true;
}
int main()
{
    scanf("%s",s);
    if (!point_num(s))
    {
        printf("NO");
        return 0;
    }
    if (!pd_0(0,point[1]) || !pd_0(point[1]+1,point[2]) || !pd_0(point[2]+1,point[3]) || !pd_0(point[3]+1,strlen(s)))
    {
        printf("NO");
        return 0;
    }
    int x1=-1,x2=-1,x3=-1,x4=-1;
    sscanf(s,"%d.%d.%d.%d",&x1,&x2,&x3,&x4);		//没考虑前导0的情况 但可以规避数字之间含有其它字符的情况,01,+1无法包含
    if (pd(x1)&&pd(x2)&&pd(x3)&&pd(x4))
        printf("YES");
    else printf("NO");
    return 0;
}
