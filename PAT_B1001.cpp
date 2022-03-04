#include<stdio.h>
int main()
{
	int ans=0;
	int n;
	scanf("%d",&n);
	while (n!=1)
	{
		if ((n&1)==0)	n=n>>1;
		else n=(3*n+1)/2;
		ans++;
	}
	printf("%d",ans);
	return 0;
 } 
