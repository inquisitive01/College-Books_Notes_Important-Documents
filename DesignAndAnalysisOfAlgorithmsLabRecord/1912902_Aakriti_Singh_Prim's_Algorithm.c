//Program for minimum spanning tree using prim's algorithm
//Made By-Aakriti Singh 
//Roll No.-1912902

//Program for minimum spanning tree using prim's algorithm
//graph representation
#include<stdio.h>
void prims(int cost[10][10],int n);
int near[10];
int main()
{
   int i,j,n,e,ch,v1,v2,g[10][10],w;
   printf("\nEnter the number of vertices in the graph: ");
   scanf("%d",&n);
   for(i=1;i<=n;i++)
   {
       for(j=1;j<=n;j++)
           g[i][j]=99;
   }
   printf("\nGraph is: 1-Directed graph\n2-Undirected graph\nEnter your choice: ");
   scanf("%d",&ch);
   switch(ch)
   {
       case 1:printf("\nEnter number of edges in directed graph: ");
           scanf("%d",&e);
           printf("\nEnter the pair of vertices v1-->v2 and weight:\n");
           for(i=1;i<=e;i++)
           {
               scanf("%d%d%d",&v1,&v2,&w);
               g[v1][v2]=w;
           }
           break;
       case 2:printf("\nEnter number of edges in undirected graph: ");
           scanf("%d",&e);
           printf("\nEnter the pair of vertices having edge between them and weight:\n");
           for(i=1;i<=e;i++)
           {
               scanf("%d%d%d",&v1,&v2,&w);
               g[v1][v2]=w;
               g[v2][v1]=w;
           }
           break;
       default:printf("\nEnter valid choice!!\n");  
   }
   printf("\nMatrix representation:\n");
   for(i=1;i<=n;i++)
   {
       for(j=1;j<=n;j++)
       {
           printf("%d  ",g[i][j]);
       }
       printf("\n");
   }
   //Calling prim's function
   prims(g,n);
   return 0;
}
//Prim's Function
void prims(int cost[10][10],int n)
{
   int i,k,l,j,v,costmst=0,min,t[10][2],q,w;
   //finding minimum cost edge (k,l)
   min=99;
   for(i=1;i<=n;i++)
   {
       for(j=1;j<=n;j++)
       {
           if(min>cost[i][j])
           {
               min=cost[i][j];
               k=i;
               l=j;
           }
       }
   }
   t[1][1]=k;
   t[1][2]=l;
  costmst+=cost[k][l];//update cost of MST
   //initialize the near[] value of vertices
   for(i=1;i<=n;i++)
   {
       if(cost[k][i]<cost[l][i])
           near[i]=k;
       else
           near[i]=l;
   }
   near[k]=0;
   near[l]=0;
   //selecting remaining n-2 edges
   for(i=2;i<=n-1;i++)
   {
       min=99;
       //select a vertex j s.t near[j]!=0 and cost[j][near[j]] is minimum
       for(q=1;q<=n;q++)
       {
           if(cost[q][near[q]]<min && near[q]!=0)
           {
               min=cost[q][near[q]];
               j=q;
           }
       }
      //update cost of MST
   costmst+=min;
   t[i][1]=j;
   t[i][2]=near[j];
   near[j]=0;

   //update near values for other vertices
   for(k=1;k<=n;k++)
   {
       if(cost[k][near[k]] >cost[k][j] && near[k]!=0)
       {
           near[k]=j;
       }
   }
}
   printf("\nThe minimum spanning tree is as follows:\n");
   for(i=1;i<=n-1;i++)
   {
       printf("(%d,%d)",t[i][1],t[i][2]);
       printf("\n");
   }
   printf("\nCost of MST= %d",costmst);
}