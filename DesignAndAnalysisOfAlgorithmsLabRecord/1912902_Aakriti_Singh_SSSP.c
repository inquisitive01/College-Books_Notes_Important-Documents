//SINGLE SOURCE SHORTEST PATH PROBLEM
//Made By-Aakriti Singh
//Roll No.-1912902

#include<stdio.h>
// gr is adjacency matrix, c[i][j] cost matrix,
//dist[i], 1<=i<=n distance from source to other vertex i
int main()
{
	int i,e,n,c[20][20],j,k,gr[20][20],min,w;
	int v,u,dist[20],s[20];
	printf("Enter total no. of vertices in graph ");
	scanf("%d",&n);
	//Adjacency matrix
	for(i=1;i<=n;i++)
	 for(j=1;j<=n;j++)
	  gr[i][j]=0;
	  
	printf("\nEnter total no. of edges ");
	scanf("%d",&e);
	//Fill the cost matrix diagonal 0 and all other 1000 if no edge
	for(i=1;i<=e;i++)
	  for(j=1;j<=e;j++)
	   {
	   	if(i==j)
	   	  c[i][j]=0;
	   	else c[i][j]=1000;
	   }
    for(k=1;k<=e;k++)
    {
    	printf("\nEnter two vertices for edge-%d and its cost:",k);
    	scanf("%d",&i); scanf("%d",&j);
    	 gr[i][j]=1;     gr[j][i]=1;
    	 scanf("%d",&c[i][j]);
    	 c[j][i]=c[i][j];
	}
	printf("\nAdjacency matrix is");
	for(i=1;i<=n;i++)//print adjacency matrix
	{
		printf("\n");
		for(j=1;j<=n;j++)
		printf("%d ",gr[i][j]);
	}
	printf("\nCost matrix is");//print cost adjacency matrix
	for(i=1;i<=n;i++)
	   {
	   	printf("\n");
	   	for(j=1;j<=n;j++)
	   	  printf("%d ",c[i][j]);
	   }
	printf("\nEnter the source vertex: ");
	scanf("%d",&v);
	for(i=1;i<=n;i++)//initialize the dist[] value and set s
	{
		s[i]=0;
		dist[i]=c[v][i];
	}
	s[v]=1;//add v to the set s
	dist[v]=0;//distance from source to source = 0
	u=v;
	for(k=2;k<=n;k++)
	{
		min=10000;//find a vertex u not in s and dist[u] is minimum
		for(i=1;i<=n;i++)
		{
			if((s[i]==0)&&(dist[i]<min))
			{
				min=dist[i];
				u=i;
			}
		}
		s[u]=1;
		//update the dist[] value of adjacent vertex w from u
		for(w=1;w<=n;w++)
		{
			if((gr[u][w]==1)&&(s[w]==0))
			{
				if(dist[w]>(dist[u]+c[u][w]))
                    dist[w]=dist[u]+c[u][w];
			}
		}
		printf("\nDistance:%d--->%d is:%d",v,u,dist[u]);
	}
	return 0;	
}//main

