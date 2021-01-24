#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) (((a)>(b))?(a):(b))

struct node
{
	struct node *left;
	int data;
	struct node *right;
};

struct node *head;


int height(struct node *prober);
struct node *insert(struct node *prober, int n);

int height(struct node *prober)
{
	if(prober==NULL||(prober->left==NULL&&prober->right==NULL)) return 0;	
	return 1+MAX(height(prober->left),height(prober->right));
}

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
		if (n>prober->data)
		{
			prober->right=insert(prober->right, n);
		}
		if (n<prober->data)
		{
			prober->left=insert(prober->left, n);
		}
	}
	return prober;
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

	h=height(head);
	if(n==0) printf("%d",n);
	else printf("\nh=%d",h+1);
    return 0;
}
	
	