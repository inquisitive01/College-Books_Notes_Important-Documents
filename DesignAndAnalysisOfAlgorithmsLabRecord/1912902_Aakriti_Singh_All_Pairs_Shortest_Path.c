//ALL PAIRS SHORTEST PATH
//Made By-Aakriti Singh 
//Roll No.-1912902

#include<stdio.h>
void FloydWarshal(int cost[10][10],int n);
int main()
{
	int i,j,n,e,ch,v1,v2,a[10][10],w;
	printf("\nEnter the number of vertices in the graph:");
	scanf("%d",&n);
	printf("Graph is 1.directed 2.undirected\nEnter your choice");
	scanf("%d",&ch);
	for(i=1;i<=n;i++)
	  for(j=1;j<=n;j++)
	  {
	  	if(i==j)
	  	a[i][j]=0;
	  	else
	  	a[i][j]=99;
	  }
	switch(ch)
	{
		case 1:printf("\nEnter the number of edges in the directed graph\n");
		       scanf("%d",&e);
		       printf("\nEnter the pair of vertices having edge between them and cost");
		       for(i=1;i<=e;i++)
		       {
		       	scanf("%d%d%d",&v1,&v2,&w);
		       	a[v1][v2]=w;
			   }
			   break;
		case 2:printf("\nEnter the number of edges in the undirected graph\n");
		       scanf("%d",&e);
		       printf("\nEnter the pair of vertices having edge between them");
		       for(i=1;i<=e;i++)
		       {
		       	scanf("%d%d%d",&v1,&v2,&w);
		       	a[v1][v2]=w;
		       	a[v2][v1]=w;
			   }
			   break;
	    default:printf("\nEnter correct choice");
    }
    printf("\nCost Matrix of Graph\n");
    for(i=1;i<=n;i++)
    {
    	for(j=1;j<=n;j++)
    	{
    		printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	FloydWarshal(a,n);
	return 0;
}
//FloydWarshal Function
void FloydWarshal(int cost[10][10],int n)
{
	int a[10][10],i,j,k;
	//a[i][j] is length of shortest path b/w vertex i and j
	//initialize the matrix a[][]
	for(i=1;i<=n;i++)
	  for(j=1;j<=n;j++)
	    a[i][j]=cost[i][j];
	    
	for(k=1;k<=n;k++) //for intermediate vertex k
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if((a[i][k]+a[k][j])<a[i][j])
				   a[i][j]=a[i][k]+a[k][j];
			}
		}
	}
	printf("\nThe solution Matrix A[i][j]\n");
	for(i=1;i<=n;i++)
	{
		printf("\n");
		for(j=1;j<=n;j++)
		printf("%d\t",a[i][j]);
		
	}
}
