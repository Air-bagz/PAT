//���ִ���2022/3/12 
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
bool pd_0(int st, int en)        //�ж�ǰ����
{
    char temp[10]="",ss[10];
    for (int i=st; i<en; i++)
    {
        sprintf(ss,"%c",s[i]);    //�ַ�ת�ַ���
        strcat(temp,ss);        //strcat(temp,s[i])������
    }
    if (strlen(temp)>1 && (temp[0]<='0' || temp[0]>'9') )        //ǰ��0�Լ�+-����
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
    sscanf(s,"%d.%d.%d.%d",&x1,&x2,&x3,&x4);		//û����ǰ��0����� �����Թ������֮�京�������ַ������,01,+1�޷�����
    if (pd(x1)&&pd(x2)&&pd(x3)&&pd(x4))
        printf("YES");
    else printf("NO");
    return 0;
}
