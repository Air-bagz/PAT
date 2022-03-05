#include<stdio.h>
int main()
{
	int num[10];	//0-9
	int i,j;
	for (i=0; i<=9; i++)
		scanf("%d",&num[i]);
	for (i=1; i<=9; i++)
		if (num[i]>0)
		{
			printf("%d",i);
			num[i]--;
			break;
		}
	for (i=0; i<=9; i++)
		for (j=1; j<=num[i]; j++)
			printf("%d",i);
	return 0;
}
