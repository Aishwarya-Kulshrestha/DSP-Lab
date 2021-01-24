#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *left;
	int data;
	struct node *right;
};

struct node *head; struct node *rnode_arr[200];
int top=-1; int curr_arr[200];

struct node *insert(struct node *prober, int n);
struct node *push(struct node *a);
struct node *pop();
void dispost(struct node *prober);
void dispin(struct node *prober);
void dispre(struct node *prober,int n);

struct node *insert(struct node *prober, int n)
{
	if (prober==NULL)
	{
		prober = (struct node *)malloc(sizeof(struct node));
		prober->data=n;
		prober->left=NULL;
		prober->right=NULL;
	}
	else
	{
		if(n>prober->data)
			prober->right=insert(prober->right, n);
		
		if(n<prober->data)
			prober->left=insert(prober->left, n);
	}
	return prober;
}

void dispost(struct node *prober)
{
	if(prober==NULL) return;
	dispost(prober->left);
	dispost(prober->right);
	printf("%d ",prober->data);
	return;
}

void dispin(struct node *prober)
{
	if(prober==NULL) return;
	dispin(prober->left);
	printf("%d ",prober->data);
	dispin(prober->right);
	return;
}

void dispre(struct node *prober,int n)
{
	int i=0;
	while(i<n)
	{
		curr_arr[i]=prober->data;
		printf("%d ",prober->data);
		i++;
		if(prober->right!=NULL) push(prober->right);
		
		if(prober->left==NULL) prober=pop();
		else prober=prober->left;
	}
	return;		
}


struct node *push(struct node *a)
{	
	top++;
	rnode_arr[top]=a;
	return 0;
}

struct node *pop()
{
	struct node *temp;
	if(top==-1)
		return 0;
		
	else
	{
		temp=rnode_arr[top];
		top--;
		return temp;
	}
	return 0;
}

int main()
{
	int n,num,h;
	printf("N=");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num);
		head=insert(head,num);
	}
	dispre(head,n);
	printf("\n");
	dispin(head);
	printf("\n");
	dispost(head);
    return 0;
}