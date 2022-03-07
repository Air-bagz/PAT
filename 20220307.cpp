//无向图G，邻接矩阵存储
#include<stdio.h>
#include<string.h>
const int INF=1000000;	//设INF为一个很大的数 
//-----------------------------------------------------------------------
//邻接矩阵存储图
#define MaxVertexNum 100					//顶点数目的最大值 
typedef struct
{
	char Vex[MaxVertexNum];					//顶点表 
	short Edge[MaxVertexNum][MaxVertexNum];	//邻接矩阵，边表；bool 或 枚举类型 
	int Dist[MaxVertexNum][MaxVertexNum];	//距离 
	int vexnum,arcnum;						//图的当前顶点数和边数/弧数 
}MGraph;
bool visited[MaxVertexNum];			//访问标记数组 
//------------------------------------------------------------------------
//使用队列进行广度优先遍历 
#define MaxSize 100				//定义队列中元素的最大个数 
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];		//用静态数组存放队列元素 
	int front,rear; 			//队头指针和队尾指针 
}SqQueue;
SqQueue Q;		//全局遍历或每次代入 
//------------------------------------------------------------------------
//使用Prim算法求最小生成树
bool isJoin[MaxVertexNum];		//访问标记数组 
int lowCost[MaxVertexNum];		//顶点与集合S的最短距离 
//------------------------------------------------------------------------
//使用Floyd算法求最短路径 
int dis[MaxVertexNum][MaxVertexNum];		//记录最短路径值的矩阵
int path[MaxVertexNum][MaxVertexNum];		//记录最短路径 
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
	Graph_input(G);		//读入数据
	//Graph_print(G);
	menu(); //载入数据并展示菜单 
	printf("\t\t请选择输入:");
	int order; 
	scanf("%d",&order);
	
	int start,end;
	if (order==1)
	{
		printf("请输入广度优先遍历的起点(序号):");
		scanf("%d",&start);
		beforeBFS(G);	printf("从顶点%d出发得到的广度优先遍历序列:",start);	BFS(G,start);	printf("\n");
		}	
	else if (order==2)
	{
		printf("请输入深度优先遍历的起点(序号):");
		scanf("%d",&start);
		beforeDFS(G);	printf("从顶点%d出发得到的深度优先遍历序列:",start);	DFS(G,start);	printf("\n");
	}
	else if	(order==3)
	{
		beforePrim(G);
		printf("最小生成树的边权之和为:%d km",Prim(G));
		printf("\n");
	}
	else if (order==4)
	{
		printf("请输入最短路径的起点:");
		scanf("%d",&start);
		printf("请输入最短路径的终点:");
		scanf("%d",&end);
		Floyd(G);	printf("顶点%d到顶点%d的最短路径为:%d km",start,end,dis[start][end]);	printf("\n");
		printf("路径为:%d--->",start);
		Path(start,end,end);	printf("\n");
//		printf("%d",end);
	}
}
void menu()
{
	int i;  
	printf("\t\t\t\t无向图");
	printf("\n");
	printf("\t\t*******    Data loaded successfully!   *******\t\t\n");//数据已成功载入
	printf("\t\t");
	for (i=1;i<=46;i++) 
		printf("*");
	printf("\n");
	printf("\t\t**\t\t广度优先遍历------1\t    **\n");
	printf("\t\t**\t\t深度优先遍历------2\t    **\n");
	printf("\t\t**\t\t最小生成树------3\t    **\n");
	printf("\t\t**\t\t最短路径------4\t\t    **\n");
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
	memset(G.Edge,0,sizeof(G.Edge));		//关系邻接矩阵清0
	memset(G.Dist,0,sizeof(G.Dist)); 		
	for (int i=1; i<=G.vexnum; i++)
		for (int j=1; j<=G.vexnum; j++)
		{
			if (i==j)	G.Dist[i][j]=0;
			else  G.Dist[i][j]=INF;				//距离邻接矩阵最大值 
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
//求图G中顶点x的第一个邻接点，若有则返回顶点号。若x没有邻接点或图中不存在x，则返回-1 
int FirstNeighbor(MGraph G,int x)
{
	for (int j=1; j<=G.vexnum; j++)
		if (G.Edge[x][j]==1)	//有边(x,j)	
			return j;
	return -1;	//x没有邻接点
}
//假设图G中顶点y是顶点x的一个邻接点，返回除y之外顶点x的下一个邻接点的顶点号，若y是x的最后一个邻接点，则返回-1 
int NextNeighbor(MGraph G,int x,int y)
{
	for (int j=y+1; j<=G.vexnum; j++ )
		if (G.Edge[x][j]==1)	//有边(x,j)
			return j;
	return -1; 
}
//------------------------------------------------------------------------
//BFS之前需要初始化辅助队列和标记数组 
void beforeBFS(MGraph G)
{
	for (int i=1; i<=G.vexnum; i++)		//结点编号从1开始
		visited[i]=false;		//访问标记数组初始化
	InitQueue(Q);		//初始化辅助队列Q
}
//广度优先遍历
void BFS(MGraph G,int v) //从顶点v出发，广度优先遍历图G 
{
	 
	visit(v);			//访问初始顶点v 
	visited[v]=true;	//对v做已访问标记 
	EnQueue(Q,v);		//顶点v入队列Q 
	while (!QueueEmpty(Q))
	{
		DeQueue(Q,v);	//顶点v出队列 
		for (int w=FirstNeighbor(G,v); w>=0; w=NextNeighbor(G,v,w))
			//检测v所有邻接点
			if (!visited[w])	//w为v的尚未访问的邻接顶点 
			{
				visit(w);		//访问顶点w 
				visited[w]=true;//对w做已访问标记 
				EnQueue(Q,w);	//顶点w入队列Q 
			 }//if 
	}//while
}
//---------------------------------------------------------------
void InitQueue(SqQueue &Q)
{
	Q.rear=Q.front=0;
}
bool EnQueue(SqQueue &Q,ElemType x)		//入队 
{
	if (QueueFull(Q))	return false;		//队满报错 
	Q.data[Q.rear]=x;				//rear指向下一个应该插入的位置 
	Q.rear=(Q.rear+1)%MaxSize;		//队尾指针后移，[0,1,...,MaxSize-1]环状 
	return true;
}
bool DeQueue(SqQueue &Q,ElemType &x)
{
	if (QueueEmpty(Q)) return false;		//队空报错
	x=Q.data[Q.front];				//front指向队头元素 
	Q.front=(Q.front+1)%MaxSize; 	//队头指针后移，环状 
	return true;
}
bool QueueEmpty(SqQueue Q)
{
	if (Q.rear==Q.front)	return true;	//队空条件 
	else return false;
}
bool QueueFull(SqQueue Q)
{
	if ( (Q.rear+1)%MaxSize==Q.front )	return true;	//队满条件	牺牲一个 
	else return false;
 } 
//------------------------------------------------------------------------
//DFS之前需要初始化标记数组 
void beforeDFS(MGraph G)
{
	for (int i=1; i<=G.vexnum; i++)		//结点编号从1开始
		visited[i]=false;		//访问标记数组初始化
}
//深度优先遍历
void DFS(MGraph G,int v)	//从顶点v出发，深度优先遍历图G 
{
	visit(v);
	visited[v]=true;
	for (int w=FirstNeighbor(G,v); w>=0; w=NextNeighbor(G,v,w))
			if (!visited[w])	//w为v的尚未访问的邻接顶点 
			{
				DFS(G,w);
			 }//if  
}
//------------------------------------------------------------------------
void beforePrim(MGraph G)
{
	for (int i=1; i<=G.vexnum; i++)		//结点编号从1开始
		isJoin[i]=false;		//标记数组设置为未访问 
	for (int i=1; i<=G.vexnum; i++)	
		lowCost[i]=INF; 
}
int Prim(MGraph G)
{
	lowCost[1]=0;		//1号顶点到集合S的距离为0,其余全为INF
	int ans=0;		//存放最小生成树的边权之和
	int n=G.vexnum;
	for (int i=1; i<=n; i++)		//循环n次,每次增加一个结点到集合中 
	{
		int u=-1,MIN=INF;	//u使lowCost[u]最小,MIN存放最小的lowCost[u]; 
		for (int j=1; j<=n; j++)		//找到未访问的顶点中d[]最小的 
		{
			if (isJoin[j]==false && lowCost[j]<MIN)
			{
				u=j;
				MIN=lowCost[j];
			}
		}
	//	if (u==-1)	return -1;		//找不到小于INF的lowCost[u],则剩下的顶点和集合S不连通
		isJoin[u]=true;		//标记u为已访问
		ans=ans+lowCost[u];	//将与集合S距离最小的边加入最小生成树
		for (int v=1; v<=n; v++)
		{//v未访问 && u能到达v	&& 以u为中介点可以使v离集合S更近
			if (isJoin[v]==false && G.Dist[u][v]!=INF && G.Dist[u][v]<lowCost[v])
				lowCost[v]=G.Dist[u][v];	 
		 } 
	}
	return ans;	//返回最小生成树的边权之和 
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
	for (int k=1; k<=n; k++)	//考虑以Vk作为中转点 
	for (int i=1; i<=n; i++)	//遍历整个矩阵，i为行号，j为列号 
		for (int j=1; j<=n; j++)
			if (dis[i][k]!=INF && dis[k][j]!=INF && dis[i][k]+dis[k][j]<dis[i][j])		//以Vk为中转点的路径更短 
			{
				dis[i][j]=dis[i][k]+dis[k][j];	//更新最短路径长度 
				path[i][j]=k;			//中转点 
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
