//Graph Coluring Problem (m-colouring problem)
#include<stdio.h>
#include<stdlib.h>
int n,m,x[10],g[10][10];
void next_value(int k);
void mcolouring(int k);
main()
{
	int i,j,e,ch,v1,v2;
	printf("\nEnter the number of vertices in the graph:");
	scanf("%d",&n);
	printf("Graph is 1.Directed 2.Undirected\nEnter your choice");
	scanf("%d",&ch);
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	g[i][j]=0;
	
	switch(ch)
	{
		case 1:printf("\nEnter the number of edges in the directed graph\n");
		       scanf("%d",&e);
		       printf("\nEnter the pair of vertices having edge between them");
		       for(i=1;i<=e;i++)
		       {
		       	scanf("%d%d",&v1,&v2);
		       	g[v1][v2]=1;
			   }
			   break;
		case 2:printf("\nEnter the number of edges in the undirected graph\n");
		       scanf("%d",&e);
		       printf("\nEnter the pair of vertices having edge between them");
		       for(i=1;i<=e;i++)
		       {
		       	scanf("%d%d",&v1,&v2);
		       	g[v1][v2]=1;
		       	g[v2][v1]=1;
			   }
			   break;
		default:printf("\nEnter correct choice");
	}
	printf("\nAdjacency Matrix Representation\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d\t",g[i][j]);
		}
		printf("\n");
	}
	printf("\nEnter the number of possible colours");
	scanf("%d",&m);
	for(i=1;i<=n;i++)
	{
		x[i]=0;
	}
	mcolouring(1);//calling of function
}
//function mcoluring
void mcolouring(int k)
{
	int i;
	static int cnt=0;
	do{
		next_value(k);
		if(x[k]==0)
		return;
		if(k==n)
		{
			cnt++;
			printf("\nSolution-%d\n",cnt);
			for(i=1;i<=n;i++)
			printf("%d\t",x[i]);
		}
		else
		mcolouring(k+1);
	}while(k<=n);
}
//function next value
void next_value(int k)
{
	int j;
	do{
		x[k]=(x[k]+1)%(m+1);
		if(x[k]==0) return;
		for(j=1;j<=n;j++)
		{
			if((g[k][j]==1)&&(x[j]==x[k]))
			break;
		}
		if(j==n+1) return;
	}while(x[k]!=0);
}
