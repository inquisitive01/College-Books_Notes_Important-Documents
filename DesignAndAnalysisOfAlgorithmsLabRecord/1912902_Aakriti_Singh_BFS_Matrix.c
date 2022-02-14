//BFS MATRIX
//Made By-Aakriti Singh 
//Roll No.-1912902

#include<stdio.h>
#define max 10

int g[10][10],q[max],vis[10];
int n,front=-1,rear=-1;

//empty queue function
int emptyq()
{
if(front==-1 && rear==-1)
return 1;
else
return 0;
}

//insert into q
void qinsert(int x)
{
if((front==0) && (rear==max-1))
printf("Queue is Overflow");
else
{
rear++;
q[rear]=x;
if(front==-1)
front=0;
}
}

//delete from queue
int deleteq()
{
int d;
if(front==-1 && rear==-1)
d=0;
else
{
d=q[front];
if(front==rear)
{
front=-1;
rear=-1;
}
else
front+=1;
}
return d;
}

//BFS function
void bfs(int v)
{
int i,w;
for(i=1;i<=n;i++)
vis[i]=0;
printf("\nTraversal from vertex %d\n",v);
printf("\t%d",v);
vis[v]=1;
qinsert(v);
while(!emptyq())
{
v=deleteq();
for(w=1;w<=n;w++)
{
if(g[v][w]==1 && vis[w]==0)
{
printf("\t%d",w);
vis[w]=1;
qinsert(w);
}
}
}
}

int main()
{
int i,j,v,e,k,v1,v2;
printf("\nEnter total no of vertices in graph:");
scanf("%d",&n);
printf("\nEnter total no. of edges:");
scanf("%d",&e);
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
g[i][j]=0;
}
}
//Adjacency matrix of graph
for(k=1;k<=e;k++)
{
printf("\nEnter end vertices for edge no-%d: ",k);
scanf("%d",&v1);
scanf("%d",&v2);
g[v1][v2]=1;
g[v2][v1]=1;
}
//Printing Adjacency matrix of graph
printf("\nAdjacency matrix of graph\n");
for(i=1;i<=n;i++)
{
//printf("\n\n");
for(j=1;j<=n;j++)
{
printf("%d  ",g[i][j]);
}
printf("\n");
}
printf("\nFor BFS enter starting vertex=");
scanf("%d",&v);
bfs(v);
return 0;
}
