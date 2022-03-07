//����ͼG���ڽӾ���洢
#include<stdio.h>
#include<string.h>
const int INF=1000000;	//��INFΪһ���ܴ���� 
//-----------------------------------------------------------------------
//�ڽӾ���洢ͼ
#define MaxVertexNum 100					//������Ŀ�����ֵ 
typedef struct
{
	char Vex[MaxVertexNum];					//����� 
	short Edge[MaxVertexNum][MaxVertexNum];	//�ڽӾ��󣬱߱�bool �� ö������ 
	int Dist[MaxVertexNum][MaxVertexNum];	//���� 
	int vexnum,arcnum;						//ͼ�ĵ�ǰ�������ͱ���/���� 
}MGraph;
bool visited[MaxVertexNum];			//���ʱ������ 
//------------------------------------------------------------------------
//ʹ�ö��н��й�����ȱ��� 
#define MaxSize 100				//���������Ԫ�ص������� 
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];		//�þ�̬�����Ŷ���Ԫ�� 
	int front,rear; 			//��ͷָ��Ͷ�βָ�� 
}SqQueue;
SqQueue Q;		//ȫ�ֱ�����ÿ�δ��� 
//------------------------------------------------------------------------
//ʹ��Prim�㷨����С������
bool isJoin[MaxVertexNum];		//���ʱ������ 
int lowCost[MaxVertexNum];		//�����뼯��S����̾��� 
//------------------------------------------------------------------------
//ʹ��Floyd�㷨�����·�� 
int dis[MaxVertexNum][MaxVertexNum];		//��¼���·��ֵ�ľ���
int path[MaxVertexNum][MaxVertexNum];		//��¼���·�� 
//------------------------------------------------------------------------
void menu();
//------------------------------------------------------------------------
void Graph_input(MGraph &G);
void Graph_print(MGraph G);
void visit(int v);
int FirstNeighbor(MGraph G,int x);
int NextNeighbor(MGraph G,int x,int y);
//------------------------------------------------------------------------
void beforeBFS(MGraph G); 
void BFS(MGraph G,int v);
//------------------------------------------------------------------------
void InitQueue(SqQueue &Q); 
bool EnQueue(SqQueue &Q,ElemType x);
bool DeQueue(SqQueue &Q,ElemType &x);
bool QueueEmpty(SqQueue Q);
bool QueueFull(SqQueue Q);
//------------------------------------------------------------------------
void beforeDFS(MGraph G); 
void DFS(MGraph G,int v);
//------------------------------------------------------------------------
void beforePrim(MGraph G); 
int Prim(MGraph G);
//------------------------------------------------------------------------
void Floyd(MGraph G);
void Path(int i,int j,int end);
//------------------------------------------------------------------------
int main()
{
	MGraph G;
	Graph_input(G);		//��������
	//Graph_print(G);
	menu(); //�������ݲ�չʾ�˵� 
	printf("\t\t��ѡ������:");
	int order; 
	scanf("%d",&order);
	
	int start,end;
	if (order==1)
	{
		printf("�����������ȱ��������(���):");
		scanf("%d",&start);
		beforeBFS(G);	printf("�Ӷ���%d�����õ��Ĺ�����ȱ�������:",start);	BFS(G,start);	printf("\n");
		}	
	else if (order==2)
	{
		printf("������������ȱ��������(���):");
		scanf("%d",&start);
		beforeDFS(G);	printf("�Ӷ���%d�����õ���������ȱ�������:",start);	DFS(G,start);	printf("\n");
	}
	else if	(order==3)
	{
		beforePrim(G);
		printf("��С�������ı�Ȩ֮��Ϊ:%d km",Prim(G));
		printf("\n");
	}
	else if (order==4)
	{
		printf("���������·�������:");
		scanf("%d",&start);
		printf("���������·�����յ�:");
		scanf("%d",&end);
		Floyd(G);	printf("����%d������%d�����·��Ϊ:%d km",start,end,dis[start][end]);	printf("\n");
		printf("·��Ϊ:%d--->",start);
		Path(start,end,end);	printf("\n");
//		printf("%d",end);
	}
}
void menu()
{
	int i;  
	printf("\t\t\t\t����ͼ");
	printf("\n");
	printf("\t\t*******    Data loaded successfully!   *******\t\t\n");//�����ѳɹ�����
	printf("\t\t");
	for (i=1;i<=46;i++) 
		printf("*");
	printf("\n");
	printf("\t\t**\t\t������ȱ���------1\t    **\n");
	printf("\t\t**\t\t������ȱ���------2\t    **\n");
	printf("\t\t**\t\t��С������------3\t    **\n");
	printf("\t\t**\t\t���·��------4\t\t    **\n");
	printf("\t\t");
	for (i=1;i<=46;i++) 
		printf("*"); 
	printf("\n\t\t");
	for (i=1;i<=46;i++) 
		printf("*");
	printf("\n");
}
//------------------------------------------------------------------------
void Graph_input(MGraph &G)
{
	FILE *fp;
	fp=fopen("Z:\\MGraph_in.txt","r");
	fscanf(fp,"%d %d",&G.vexnum,&G.arcnum);
	int x,y,z;
	memset(G.Edge,0,sizeof(G.Edge));		//��ϵ�ڽӾ�����0
	memset(G.Dist,0,sizeof(G.Dist)); 		
	for (int i=1; i<=G.vexnum; i++)
		for (int j=1; j<=G.vexnum; j++)
		{
			if (i==j)	G.Dist[i][j]=0;
			else  G.Dist[i][j]=INF;				//�����ڽӾ������ֵ 
		}
	for (int i=1; i<=G.arcnum; i++)
	{
		fscanf(fp,"%d %d %d",&x,&y,&z);
		G.Edge[x][y]=1;	G.Edge[y][x]=1;
		G.Dist[x][y]=z; G.Dist[y][x]=z;
	}
}
void Graph_print(MGraph G)
{
	for (int i=1; i<=G.vexnum; i++)
	{
		for (int j=1; j<=G.vexnum; j++)
			printf("%d ",G.Edge[i][j]);
		printf("\n");
	}
	for (int i=1; i<=G.vexnum; i++)
	{
		for (int j=1; j<=G.vexnum; j++)
			printf("%d ",G.Dist[i][j]);
		printf("\n");
	}
}
void visit(int v)
{
	printf("%d ",v);
}
//��ͼG�ж���x�ĵ�һ���ڽӵ㣬�����򷵻ض���š���xû���ڽӵ��ͼ�в�����x���򷵻�-1 
int FirstNeighbor(MGraph G,int x)
{
	for (int j=1; j<=G.vexnum; j++)
		if (G.Edge[x][j]==1)	//�б�(x,j)	
			return j;
	return -1;	//xû���ڽӵ�
}
//����ͼG�ж���y�Ƕ���x��һ���ڽӵ㣬���س�y֮�ⶥ��x����һ���ڽӵ�Ķ���ţ���y��x�����һ���ڽӵ㣬�򷵻�-1 
int NextNeighbor(MGraph G,int x,int y)
{
	for (int j=y+1; j<=G.vexnum; j++ )
		if (G.Edge[x][j]==1)	//�б�(x,j)
			return j;
	return -1; 
}
//------------------------------------------------------------------------
//BFS֮ǰ��Ҫ��ʼ���������кͱ������ 
void beforeBFS(MGraph G)
{
	for (int i=1; i<=G.vexnum; i++)		//����Ŵ�1��ʼ
		visited[i]=false;		//���ʱ�������ʼ��
	InitQueue(Q);		//��ʼ����������Q
}
//������ȱ���
void BFS(MGraph G,int v) //�Ӷ���v������������ȱ���ͼG 
{
	 
	visit(v);			//���ʳ�ʼ����v 
	visited[v]=true;	//��v���ѷ��ʱ�� 
	EnQueue(Q,v);		//����v�����Q 
	while (!QueueEmpty(Q))
	{
		DeQueue(Q,v);	//����v������ 
		for (int w=FirstNeighbor(G,v); w>=0; w=NextNeighbor(G,v,w))
			//���v�����ڽӵ�
			if (!visited[w])	//wΪv����δ���ʵ��ڽӶ��� 
			{
				visit(w);		//���ʶ���w 
				visited[w]=true;//��w���ѷ��ʱ�� 
				EnQueue(Q,w);	//����w�����Q 
			 }//if 
	}//while
}
//---------------------------------------------------------------
void InitQueue(SqQueue &Q)
{
	Q.rear=Q.front=0;
}
bool EnQueue(SqQueue &Q,ElemType x)		//��� 
{
	if (QueueFull(Q))	return false;		//�������� 
	Q.data[Q.rear]=x;				//rearָ����һ��Ӧ�ò����λ�� 
	Q.rear=(Q.rear+1)%MaxSize;		//��βָ����ƣ�[0,1,...,MaxSize-1]��״ 
	return true;
}
bool DeQueue(SqQueue &Q,ElemType &x)
{
	if (QueueEmpty(Q)) return false;		//�ӿձ���
	x=Q.data[Q.front];				//frontָ���ͷԪ�� 
	Q.front=(Q.front+1)%MaxSize; 	//��ͷָ����ƣ���״ 
	return true;
}
bool QueueEmpty(SqQueue Q)
{
	if (Q.rear==Q.front)	return true;	//�ӿ����� 
	else return false;
}
bool QueueFull(SqQueue Q)
{
	if ( (Q.rear+1)%MaxSize==Q.front )	return true;	//��������	����һ�� 
	else return false;
 } 
//------------------------------------------------------------------------
//DFS֮ǰ��Ҫ��ʼ��������� 
void beforeDFS(MGraph G)
{
	for (int i=1; i<=G.vexnum; i++)		//����Ŵ�1��ʼ
		visited[i]=false;		//���ʱ�������ʼ��
}
//������ȱ���
void DFS(MGraph G,int v)	//�Ӷ���v������������ȱ���ͼG 
{
	visit(v);
	visited[v]=true;
	for (int w=FirstNeighbor(G,v); w>=0; w=NextNeighbor(G,v,w))
			if (!visited[w])	//wΪv����δ���ʵ��ڽӶ��� 
			{
				DFS(G,w);
			 }//if  
}
//------------------------------------------------------------------------
void beforePrim(MGraph G)
{
	for (int i=1; i<=G.vexnum; i++)		//����Ŵ�1��ʼ
		isJoin[i]=false;		//�����������Ϊδ���� 
	for (int i=1; i<=G.vexnum; i++)	
		lowCost[i]=INF; 
}
int Prim(MGraph G)
{
	lowCost[1]=0;		//1�Ŷ��㵽����S�ľ���Ϊ0,����ȫΪINF
	int ans=0;		//�����С�������ı�Ȩ֮��
	int n=G.vexnum;
	for (int i=1; i<=n; i++)		//ѭ��n��,ÿ������һ����㵽������ 
	{
		int u=-1,MIN=INF;	//uʹlowCost[u]��С,MIN�����С��lowCost[u]; 
		for (int j=1; j<=n; j++)		//�ҵ�δ���ʵĶ�����d[]��С�� 
		{
			if (isJoin[j]==false && lowCost[j]<MIN)
			{
				u=j;
				MIN=lowCost[j];
			}
		}
	//	if (u==-1)	return -1;		//�Ҳ���С��INF��lowCost[u],��ʣ�µĶ���ͼ���S����ͨ
		isJoin[u]=true;		//���uΪ�ѷ���
		ans=ans+lowCost[u];	//���뼯��S������С�ı߼�����С������
		for (int v=1; v<=n; v++)
		{//vδ���� && u�ܵ���v	&& ��uΪ�н�����ʹv�뼯��S����
			if (isJoin[v]==false && G.Dist[u][v]!=INF && G.Dist[u][v]<lowCost[v])
				lowCost[v]=G.Dist[u][v];	 
		 } 
	}
	return ans;	//������С�������ı�Ȩ֮�� 
}
//------------------------------------------------------------------------
void Floyd(MGraph G)
{
	memset(path,0,sizeof(path));
	for (int i=1; i<=G.vexnum; i++)
		for (int j=1; j<=G.vexnum; j++)
		{
			dis[i][j]=G.Dist[i][j];
			path[i][j]=-1;
		}
	int n=G.vexnum;	
	for (int k=1; k<=n; k++)	//������Vk��Ϊ��ת�� 
	for (int i=1; i<=n; i++)	//������������iΪ�кţ�jΪ�к� 
		for (int j=1; j<=n; j++)
			if (dis[i][k]!=INF && dis[k][j]!=INF && dis[i][k]+dis[k][j]<dis[i][j])		//��VkΪ��ת���·������ 
			{
				dis[i][j]=dis[i][k]+dis[k][j];	//�������·������ 
				path[i][j]=k;			//��ת�� 
			}
}
void Path(int i,int j,int end)
{
	int k=path[i][j];
	if (k!=-1)
	{
		Path(i,k,end);
		Path(k,j,end);
	 } 
	else if (j!=end) printf("%d--->",j);
		else printf("%d",j);
}
//------------------------------------------------------------------------
