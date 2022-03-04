#include<stdio.h>
const int maxn=100010;
int s[maxn]={0};
int main()
{
	int n,id,sc;
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d %d",&id,&sc);
		s[id]+=sc;
	}
	int k=1,max=-1;
	for (int i=1; i<=n; i++)
	{
		if (s[i]>max)
		{max=s[i];
		k=i;
		}
	}
	printf("%d %d",k,max);
	return 0;
}
