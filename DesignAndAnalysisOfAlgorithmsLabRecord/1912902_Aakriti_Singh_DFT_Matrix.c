//DFT MATRIX
//Made By-Aakriti Singh 
//Roll No.-1912902

#include<stdio.h>
void dft(int n);
int g[10][10],vis[10],n;

//DFS function
void dfs(int v)
{
int i,w;
printf("%d\t",v);
vis[v]=1;
for(w=1;w<=n;w++)
{
if((g[v][w]==1) && (vis[w]==0))
{
dfs(w);
}
}
}

//Main function
int main()
{
int i,j,v,e,k,v1,v2;
printf("\nEnter total no. of vertices in Graph:");
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
//Reading adjacency matrix of graph
for(k=1;k<=e;k++)
{
printf("\nEnter end vertices for edge no. %d:",k);
scanf("%d",&v1);
scanf("%d",&v2);
g[v1][v2]=1;
g[v2][v1]=1;
}
//Printing adjacency matrix of graph
printf("\nAdjacency matrix of graph\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
printf("%d  ",g[i][j]);
printf("\n");
}
for(i=1;i<=n;i++)
vis[i]=0;
printf("\nDepth First Traversal of graph\n",v);
dft(n);
return 0;
}

//Dft function
void dft(int n)
{
int i;
for(i=1;i<=n;i++)
vis[i]=0;
for(i=1;i<=n;i++)
{
if(vis[i]==0)
dfs(i);
}
}
