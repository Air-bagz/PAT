#include<stdio.h>
int main()
{
	int n;
	char c;
	scanf("%d %c",&n,&c);
	int i;
	for (i=1; i<=n; i++)	printf("%c",c);
	printf("\n");
	int row;
	if ((n&1) == 0)	row=n>>1;
	else row=(n>>1)+1;	
	for (i=2; i<=row-1; i++)
	{
		printf("%c",c);
		for (int j=2; j<=n-1; j++)
		 printf(" ");
		printf("%c\n",c);
	}
	for (i=1; i<=n; i++)	printf("%c",c);
	printf("\n");
}
