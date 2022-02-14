//THREADED BINARY SEARCH TREE
//Made By:-Aakriti Singh 
//Roll No.-1912902

#include<stdio.h>
#include<stdlib.h>
//convention is taken rthread(p)=1
//if there is no right child of p
//otherwise 0 and lthread(p)=1
//if there is no left child of p
//otherwise 0
struct node{
	struct node *left;
	struct node *right;
	int info;
	int rthread;
	int lthread;
};

struct node *root=NULL;

void maketree(int x);//create a single node TBST
void createtree(int n);//create TBST using n elements
void insert(struct node *,int x);//insert a new node with info x
struct node * search(struct node *root,int x);//search a given node
struct node * insuccessor(struct node *x);//to find insuccessor of a node
struct node * inpredecessor(struct node *x);//find predecessor of node
void inorder(struct node *);//inorder traversal
void preorder(struct node *);//preorder traversal
void setleft(struct node *,int);//set a new node to left of node p
void setright(struct node *,int);//set a new node to right of node p

void main()
{
	int a,n,x,c,b,ch,e;
	struct node *p;
	do{
		printf("\n 1.Create 2. Insert\t 3. Search");
		printf("\n 4.Inorder Traversal \t 5.Preorder Traversal");
		printf("\n 6.Inorder Predecessor \t 7. Inorder Successor");
		printf("\n 8.Exit \n Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\n Enter how many nodes");
			       scanf("%d",&n);
			       createtree(n);
			       inorder(root);
			       break;
			case 2:printf("\n Entre new node value to insert");
			       scanf("%d",&x);
			       insert(root,x);
			       inorder(root);
			       break;
		    case 3:printf("\n Enter element to search");
		        scanf("%d",&x);
		        p=search(root,x);
		        if(p==NULL)
		        printf("\n Node is not presemt");
		        else
		        printf("\n Node is present");
		        break;
		    case 4:inorder(root);
		           break;
		    case 5:preorder(root);
		           break;
		    case 6:printf("\n Enter node element whose predecessor you want");
		           scanf("%d",&x);
		           p=search(root,x);
		           if(p==NULL)
		           printf("\nExisting node not present whose predecessor you want");
		           else
		           {
		           	p=inpredecessor(p);
		           	if(p==NULL)
		           	printf("\n No predecessor exist");
		           	else
		           	printf("\nThe predecessor of %d is %d",x,p->info);
				   }
				   break;
			case 7:printf("\n Enter element whose successor you want");
		           scanf("%d",&x);
		           p=search(root,x);
		           if(p==NULL)
		           printf("\nExisting node not present whose successor you want");
		           else
		           {
		           	p=insuccessor(p);
		           	if(p==NULL)
		           	printf("\n No successor exist");
		           	else
		           	printf("\nThe successor of %d is %d",x,p->info);
				   }
				   break;
			case 8:printf("\nThank You");
			       break;    
		}//switch
	}while(ch>=1 && ch<=7);
}
//search a node from TBST
struct node * search(struct node *root,int x)
{
	struct node *p,*q;
	p=root;
	if(root==NULL||root->info==x) return p;
	else if(x < root->info)
	{
		if(root->lthread==1)
		return NULL;
		else
		return search(root->left,x);
	}
	else if(x > root->info)
	{
		if(root->rthread==1)
		return NULL;
		else
		return search(root->right,x);
	}
}
//Create a single node TBST and root point to that node
void maketree(int x)
{
	struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
	p->info=x;
	p->left=NULL;
	p->right=NULL;
	p->rthread=1;//p->right is thread pointer
	p->lthread=1;//p->left is thread pointer
	root=p;
}
//Create a TBST using n nodes
void createtree(int n)
{
	int i,x;
	printf("\n Enter the %d values\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		if(i==0 && root==NULL) maketree(x);//making the root of TBST
		else
		insert(root,x);//inserting into TBST
	}
}
//Insert a node into TBST
void insert(struct node *root,int x)
{
	if(root==NULL) maketree(x);//make the root node if root is NULL
	else if(x < root->info)
	{
		if(root->lthread==1)
		setleft(root,x);
		else
		{
			insert(root->left,x);
		}
	}
	else if(x >= root->info)
	{
		if(root->rthread==1)
		setright(root,x);
		else
		{
			insert(root->right,x);
		}
	}
}
//Set a new node to left of node P
void setleft(struct node *p,int x)
{
	struct node *q,*r;
	q=(struct node *)malloc(sizeof(struct node));
	q->info=x;
	r=p->left;
	q->left=r;
	p->left=q;
	q->right=p;
	q->rthread=1;
	q->lthread=1;
	p->lthread=0;
}
//Set a new node to right of node P
void setright(struct node *p,int x)
{
	struct node *q,*r;
	q=(struct node *)malloc(sizeof(struct node));
	q->info=x;
	r=p->right;
	p->right=q;
	q->right=r;
	p->rthread=0;
	q->rthread=1;
	q->left=p;
	q->lthread=1;
}
//Find successor of a given node P
struct node *insuccessor(struct node *p)
{
	struct node *succ;
	succ=p->right;
	if(p->rthread==0)
	{
		while(succ->lthread==0)
		succ=succ->left;
	}
	return succ;
}
//Find predecessor of a given node P
struct node *inpredecessor(struct node *p)
{
	struct node *pred;
	pred=p->left;
	if(p->lthread==0)
	{
		while(pred->rthread==0)
		pred=pred->right;
	}
	return pred;
}
//Preorder traversal of TBST
void preorder(struct node *p)
{
	struct node *q;
	do{
		q=p;
		while((p!=NULL)&&(p->lthread==0))
		{
			printf("%d\t",p->info);
			p=p->left;
			q=p;
		}
		if(q!=NULL)
		{
			printf("%d\t",q->info);
			p=q->right;
			while((p!=NULL)&&(q->rthread==1))
			{
				//printf("%d\t,p->info);
				q=p;
				p=p->right;
			}
		}
	}while(p!=NULL);
}
//Inorder  traversal of TBST
void inorder(struct node *p)
{
	struct node *q;
	do{
		q=p;
		while((p!=NULL)&&(p->lthread==0))
		{
			p=p->left;
			q=p;
		}
		if(q!=NULL)
		{
			printf("%d\t",q->info);
			p=q->right;
			while((p!=NULL)&&(q->rthread==1))
			{
				printf("%d\t",p->info);
				q=p;
				p=p->right;
			}//while
		}//if
	}while(p!=NULL);
}
