#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
void to_array(int n,int num[])
{
	for (int i=0; i<4; i++)
	{
		num[i]=n%10;
		n/=10;
	}
}
int to_number(int num[])
{
	int sum=0;
	for (int i=0; i<4; i++)		//a[0][1][2][3] 
	{
		sum=sum*10+num[i];
	}
	return sum;
}
int main()
{
	int n,MIN,MAX;
	scanf("%d",&n);
	int num[5];
	while(1)
	{
		to_array(n,num);	//��nת��Ϊ����,a[3][2][1][0]ԭ�� 	С�� 
		sort(num,num+4);	//����[0][1][2][3]��С����,��[3][2][1][0]�Ӵ�С 	��� 
		MIN=to_number(num);	//[0][1][2][3]���ת�� 
		sort(num,num+4,cmp);//����[0][1][2][3]�Ӵ�С,��[3][2][1][0]��С����	��� 
		MAX=to_number(num);	//ͬ�� 
		n=MAX-MIN;
		printf("%04d - %04d = %04d\n",MAX,MIN,n);
		if (n==0 || n==6174)	break; 
	}
	return 0;
}
