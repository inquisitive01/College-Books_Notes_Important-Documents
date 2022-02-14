//PROGRAM FOR SINGLE SOURCE SHORTEST PATH (SSSP)
//Made By-Aakriti Singh 
//Roll No.-1912902

#include<stdio.h>
//gr IS ADJACENCY MATRIX , c[i][j] COST MATRIX , dist[i] , 1<=i<=n DISTANCE FROM SOURCE TO OTHERS VERTEX i
int main()
{
	int i,e,n,c[20][20],j,k,gr[20][20],min,w;
	int v,u,dist[20],s[20],path[20],l;
	printf("\n ENTER TOTAL VERTICES IN GRAPH:");
	scanf("%d",&n);
	//ADJANCENCY MATRIX
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			gr[i][j]=0;
			
	printf("\n ENTER TOTAL NO. OF EDGES:");
	scanf("%d",&e);
	//FILL THE COST MATRIX DIAGONAL 0 AND ALL OTHER 1000 IF NO EDGE
	for(i=1;i<=e;i++)
		for(j=1;j<=e;j++)
			if(i==j)
				c[i][j]=0;
			else
				c[i][j]=1000;
	for(k=1;k<=e;k++)
	{
		printf("\n ENTER 2 VERTICES FOR EDGE-%d AND ITS COST:",k);
		scanf("%d%d",&i,&j);
		gr[i][j]=1;				gr[j][i]=1;
		scanf("%d",&c[i][j]);
		c[j][i]=c[i][j];
	}
	//PRINT ADJANCENCY MATRIX
	printf("\nADJANCENCY MATRIX\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%d",gr[i][j]);
		printf("\n");
	}
	//PRINT COST ADJANCENCY MATRIX 
	printf("\nCOST MATRIX\n");
	for(i=1;i<=n;i++)
	{
		printf("\n");
		for(j=1;j<=n;j++)
			printf("%d   ",c[i][j]);
	}
	printf("\n ENTER THE SOURCE VERTEX:");
	scanf("%d",&v);
	//INITIALIZE THE dist[] VALUE AND SET s
	for(i=1;i<=n;i++)
	{
		s[i]=0;
		path[i]=v;
		dist[i]=c[v][i];
	}
	s[v]=1;		//ADD SOURCE VERTEX v INTO SET s
	path[1]=v;
	dist[v]=0;	//DISTANCE FROM SOURCE TO SOURCE = 0
	u=v;
	for(k=2;k<=n;k++)
	{
		min=1000;	
		for(i=1;i<=n;i++)		//FIND A VERTEX u NOT IN s AND dist[u] IS MINIMUM
		{
			if( (s[i]==0) && (dist[i]<min) )
			{
				min=dist[i];
				u=i;
			}
		}
		s[u]=1;
		//path[k]=u;
		//UPDATE THE dist[] VALUE OF ADJANCENCY VERTICES w FROM u
		for(w=1;w<=n;w++)
		{
			if( (gr[u][w]==1) && (s[w]==0) )
			{
				if(dist[w]>(dist[u]+c[u][w]))
				{
					dist[w]=dist[u]+c[u][w];
					path[w]=u;
				}
			}
		}
	}
	for(i=1;i<=n;i++)
		if(i!=v)
		{
			printf("\n DISTANCE:%d----->%d IS:%d	PATH: %d",v,i,dist[i],i);
			j=i;
			do
			{
				j=path[j];
				printf("<-%d",j);
			}while(j!=v);
		}
	return 0;
}
