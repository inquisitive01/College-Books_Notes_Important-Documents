//KRUSKAL ALGORITHM FOR MINIMUM SPANNING TREE
//Made By-Aakriti Singh
//Roll No.-1912902

#include<stdio.h>
void minheapify(int i);
void createminheap();
void kruskals();

int edge[10],g[10][10],n,e,p[10];
//main function
int main()
{
    int i,j,ch,v1,v2,w;
    printf("\nEnter the number of vertices in the graph:");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            g[i][j]=999;
    printf("Graph is 1.directed 2.undirected\nEnter your choice");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:printf("\nEnter the number of edges in the directed graph\n");
            scanf("%d",&e);
            printf("\nEnter the pair of vertices having edge between them and weight");
            for(i=1;i<=e;i++)
            {
                scanf("%d%d%d",&v1,&v2,&w);
                g[v1][v2]=w;
                edge[i]=w;
            }
            break;
        case 2:printf("\nEnter the number of edges in the undirected graph\n");
            scanf("%d",&e);
            for(i=1;i<=e;i++)
            {
                scanf("%d%d%d",&v1,&v2,&w);
                g[v1][v2]=w;
                g[v2][v1]=w;
                edge[i]=w;
            }
            break;
default:printf("\nEnter the correct choice");
}
printf("\nMatrix representation:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("\t%d\t",g[i][j]);
        }
        printf("\n");
    }
    kruskals();
return 0;
}
//find function to find set that contains element x
int find(int i)
{
    int j=i;
    while(p[j]>0)
    {
        j=p[j];
    }
    return j;
}
//dunion function to find the union of two sets whose roots are j and k
void dunion(int i,int j)
{
    p[i]=j;
}
//delete a mincost edge from minheap
int mindelete()
{
    int x;
    x=edge[1];
    edge[1]=edge[e];
    e--;
    minheapify(1);
    return x;
}
//kruskal function for MST
void kruskals()
{
    int i=1,t[10][2],j,x,q,w,v1,v2,costmst=0,s,r;
    //create minheap
    createminheap();
    printf("\n Initialize each vertex in different sets");
    for(i=1;i<=n;i++)
        p[i]=-1;
    i=0;
    while(i<n-1 && e>0)
    {
        x=mindelete(); //delete a mincost edge
        //find the end vertices of mincost edge from the matrix
        for(q=1;q<=n;q++)
        {
            for(w=1;w<=n;w++)
            {
                if(g[q][w]==x)
                {
                    v1=q;
                    v2=w;
                }
            }
        }
        s=find(v1);
        r=find(v2);
        if(s!=r)
        {
            i++;
            t[i][1]=v1;
            t[i][2]=v2;
            dunion(v1,v2);
            costmst+=g[v1][v2];
        }
    }
    if(i<n-1)
        printf("\nNo minimum spanning tree");
    else
    {
        printf("\nThe spanning tree edges and cost are:\n");
        for(i=1;i<n-1;i++)
        {
            printf("edge(%d,%d) cost=%d",t[i][1],t[i][2],g[t[i][1]][t[i][2]]);
            printf("\n");
        }
        printf("\n Cost of MST=%d",costmst);
    }
}
//function to create a minheap
void createminheap()
{
    int i;
    for(i=e/2;i>=1;i--)
        minheapify(i);
}
//function to convert into minheap at index i
void minheapify(int i)
{
    int min,l,r,temp;
    l=2*i;
    r=2*i+1;
    if(l<=e && (edge[l]<edge[i]))
        min=l;
    else
        min=i;
    if(r<=e && (edge[r]<edge[min]))
        min=r;
    if(i!=min)
    {
        temp=edge[i];
        edge[i]=edge[min];
        edge[min]=temp;
        minheapify(min);
    }
}