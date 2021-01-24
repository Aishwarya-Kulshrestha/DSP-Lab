#include <stdio.h>
#include <stdlib.h>

int visited[6]={0,0,0,0,0,0};
int flag=0;

struct node
{
	int data;
	struct node *link;
};

struct node *rear,*front, *Q;     
 
int enqueue(int i)  
{
	
	struct node *nn=(struct node *)malloc(sizeof(struct node));
	nn->data=i;
	nn->link=NULL;
	if(rear==NULL)
	{ 
		rear=nn;
		front=rear;
		Q=nn;
	}
	else
	{
		rear->link=nn;
		rear=nn;
	}
	return 0;
}

int dequeue()       
{
	int temp;
	struct node *t;
	if(front==NULL)          
		return 0;
	else 
	{
		temp=front->data;
		t=front;
		front=front->link;
		Q=front;
		free(t);
	}
	return temp;
}

int bfs(int G[6][6],int v,int d)
{
	if(v==d) 
	{ 
		printf("%d",v+1);
		return 1;
	}
	printf("%d ->",v+1);
	visited[v]=1;
	for(int i=0;i<6;i++)
		if(G[v][i]==1 && visited[i]==0)
			enqueue(i);
	
	while(Q)
	{
		if(visited[Q->data]==0 && flag==0) 
			flag=bfs(G,dequeue(),d);
		
		else dequeue();
	}
	return 0;
}

int main()
{
	int v,d;
	rear=front=NULL;
	int G[6][6]={{1,1,0,1,0,0},
				{1,1,1,0,1,0},
				{0,1,1,0,0,0},
				{1,0,0,1,0,0},
				{0,1,0,0,1,1},
				{0,0,0,0,1,1}};
	printf("\nEnter Start node: ");
	scanf("%d",&v);
	printf("\nEnter End node: ");
	scanf("%d",&d);
	printf("\n"); 
	bfs(G,v-1,d-1);
	
	return 0;
}
	

