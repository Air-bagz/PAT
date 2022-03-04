#include<stdio.h>
#include<string.h>
int main()
{
	char str[90],ans[90][90];
	int num=0;
	while (scanf("%s",str)!=EOF)
		strcpy(ans[num++],str);
	num--;
	for (int i=num; i>=1; i--)
		printf("%s ",ans[i]);
	printf("%s",ans[0]);
	return 0;
}
