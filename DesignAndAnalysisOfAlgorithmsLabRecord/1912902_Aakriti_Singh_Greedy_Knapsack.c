//FRACTIONAL KNAPSACK---GREEDY METHOD
//Made By-Aakriti Singh
//Roll No.-1912902
#include<stdio.h>
struct knaps
{
    int id;
    float p;
    float w;
};
int n;
void knapsack(struct knaps *kn,int n,float m);
void sort(struct knaps *ob,int n);

int main()
{
    int i,j;
    struct knaps obj[10],temp; float m;
    printf("\nEnter the number of objects:");
    scanf("%d",&n);
    printf("\nEnter object_id profit and weight of %d objects \n",n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%f%f",&obj[i].id,&obj[i].p,&obj[i].w);
    }
    printf("\nEnter the capacity of knapsack:");
    scanf("%f",&m);
    printf("\n object_id \tprofit \t weight \t profit/weight \n");
    for(i=1;i<=n;i++)
    {
        printf("%d\t%f\t%f\t%.2f\n",obj[i].id,obj[i].p,obj[i].w,obj[i].p/obj[i].w);
    }
    sort(obj,n);
    knapsack(obj,n,m);
    return 0;
}
//sorting objects in decreasing order of profit/weight
void sort(struct knaps *ob,int n)
{
    int i,j;
    struct knaps temp;
    for(i=1;i<=n-1;i++)
    {
        for(j=1;j<=n;j++)
        {
            if((ob[j].p/ob[j].w) < (ob[j+1].p/ob[j+1].w))
            {
                temp=ob[j];
                ob[j]=ob[j+1];
                ob[j+1]=temp;
            }
        }
    }
}


void knapsack(struct knaps *kn,int n,float m)
{
    float x[10],u,profit=0.0,weight=0.0;
    int i,j;
    for(i=1;i<=n;i++)
    x[i]=0;
    u=m;
    for(i=1;i<=n;i++)
    {
        if(kn[i].w > u)
            break;
        x[i]=1;
        u=u-kn[i].w;
    }
    if(i<=n)
        x[i]=u/kn[i].w;

    for(i=1;i<=n;i++)
    {
        profit=profit + kn[i].p * x[i];
        weight=weight + kn[i].w * x[i];
    }
    printf("\nThe optimal solution vector:\n");
    for(i=1;i<=n;i++)
    printf("x[%d]=%.2f\t",kn[i].id,x[i]);
    printf("\n The profit=%.2f and Total weight=%0.2f\n",profit,weight);
}