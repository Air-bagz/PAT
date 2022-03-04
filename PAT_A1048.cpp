#include<stdio.h>
const int maxn=1010;
int main()
{
	int n,m,i;
	int hash[maxn]={0};
	scanf("%d %d",&n,&m);
	int x;
	for (i=1; i<=n; i++)
	{
		scanf("%d",&x);
		hash[x]++;
	}
	for (i=1; i<=m-i; i++)
	{
		if (hash[i]>0 && hash[m-i]>0 && i!=m-i)	
		{
			printf("%d %d",i,m-i);
			return 0;
		}
		else if (i==m-i && hash[i]>=2)	
		{
			printf("%d %d",i,i);
			return 0;
		}
	}
	printf("No Solution");
	return 0;
}
