#include<stdio.h>

void printPath(int parent[],int j)
{
if(parent[j]==-1)
return;
printPath(parent,parent[j]);
printf("->%d->",j);
}

int main()
{
int i,e,n,c[20][20],j,k,gr[20][20],parent[20],min,w;
int v,u,dist[20],s[20];
printf("\nEnter total no. of vertices in graph: ");
scanf("%d",&n);
//Adjacency matrix
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
gr[i][j]=0;
printf("\nEnter total no. of edges: ");
scanf("%d",&e);
//Fill the cost matrix diagonal 0 and other 100 if no edge
for(i=1;i<=e;i++)
for(j=1;j<=e;j++)
{
if(i==j) c[i][j]=0;
else c[i][j]=1000;
}
for(k=1;k<=e;k++)
{
printf("\nEnter two vertices and cost for edge-%d: ",k);
scanf("%d",&i); scanf("%d",&j);
gr[i][j]=1; gr[j][i]=1;
scanf("%d",&c[i][j]);
c[j][i]=c[i][j];
}
for(i=1;i<=n;i++)
{ printf("\n");
for(j=1;j<=n;j++)
printf("%d  ",gr[i][j]);
}
printf("\nCost matrix is:");
for(i=1;i<=n;i++)
{
printf("\n");
for(j=1;j<=n;j++)
printf("%d  ",c[i][j]);
}
printf("\nEnter the source vertex:");
scanf("%d",&v);
for(i=1;i<=n;i++)
{ s[i]=0;
dist[i]=c[v][i];
parent[i]=-1;
}
s[v]=1; //add v to the set s
dist[v]=0; //distance from source to source=0
u=v;
for(i=1;i<=n;i++) // making source parent of the remaining vertices
{ 
if(i!=v) 
parent[i]=v;
}
for(k=2;k<=n;k++)
{
min=1000; //find a vertex u not in s and dist[u] is minimum
for(i=1;i<=n;i++)
{ if((s[i]!=1) && (dist[i]<min))
{
min=dist[i];
u=i;
}
}
s[u]=1;

for(w=1;w<=n;w++)
{
if((gr[u][w]==1) && (s[w]!=1))
{ if(dist[w] > (dist[u]+c[u][w]))
{
dist[w]=dist[u]+c[u][w];
parent[w]=u;
}
}

}
printf("\nDistance:%d--->%d is: %d\t\t%d",v,u,dist[u],v);
printPath(parent,u);
}
return 0;
}
