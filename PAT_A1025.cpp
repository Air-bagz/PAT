#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;

struct student
{
	char id[14];
	int score;
	int local_num;
	int local_rank;
	int rank;
}stu[30010];

bool cmp(student a, student b)
{
	if (a.score != b.score)	return a.score>b.score;
	else return strcmp(a.id,b.id)<0;
}

int main()
{
	int n,k;	int total=0;
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&k);		
		for (int j=0; j<k; j++)
		{
			scanf("%s %d",stu[j+total].id,&stu[j+total].score);
			stu[j+total].local_num=i;
		}
		sort(&stu[total],&stu[total]+k,cmp);
		//排名 
		stu[total].local_rank=1;
		for (int j=1; j<k; j++)
		{
			if (stu[j+total].score==stu[j+total-1].score)	stu[j+total].local_rank=stu[j+total-1].local_rank;
				else stu[j+total].local_rank=j+1;	//分数相等则排名可以相等 
			//stu[j+total].local_rank=j+1;		//排名不相等 
		}
		total=total+k;
	}
	sort(stu,stu+total,cmp);
	printf("%d\n",total); 
	//总排名 
		stu[0].rank=1;
		for (int j=1; j<total; j++)
		{
			if (stu[j].score==stu[j-1].score)	stu[j].rank=stu[j-1].rank;
				else stu[j].rank=j+1;	//分数相等则排名可以相等 
		}
	for (int i=0; i<total; i++)
	printf("%s %d %d %d\n",stu[i].id,stu[i].rank,stu[i].local_num,stu[i].local_rank);
}
