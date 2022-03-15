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
		to_array(n,num);	//将n转化为数组,a[3][2][1][0]原数 	小端 
		sort(num,num+4);	//数组[0][1][2][3]从小到大,即[3][2][1][0]从大到小 	大端 
		MIN=to_number(num);	//[0][1][2][3]大端转数 
		sort(num,num+4,cmp);//数组[0][1][2][3]从大到小,即[3][2][1][0]从小到大	大端 
		MAX=to_number(num);	//同上 
		n=MAX-MIN;
		printf("%04d - %04d = %04d\n",MAX,MIN,n);
		if (n==0 || n==6174)	break; 
	}
	return 0;
}
