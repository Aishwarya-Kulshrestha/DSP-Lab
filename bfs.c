#include <stdio.h>
#include <stdlib.h>     //header for malloc() and exit()

int visited[5]={0,0,0,0,0};
int flag=0;        //flag is set to 1 when the node is found

struct node
{
	int data;
	struct node *link;
};

struct node *rear,*front, *Q;     /*Q just stores the start of Linked list.. front does that too, but 
					i will use Q as prober later in the code*/
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

int bfs(int G[5][5],int v,int d)
{
	visited[v]=1;           //sets the position of the node to 1 indicating that it has been visited
	if(v==d) 	//check if the dest. node is found, it returns 1
	{ 
		printf("%d",v);
		return 1;
	}
	printf("%d ->",v);
	for(int i=0;i<5;i++)    //loads the corresponding nodes in the queue
		if(G[v][i]==1 && visited[i]==0)
			enqueue(i);
	
	while(Q)    //loops until all nodes are dequeued and the queue is empty
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
	int G[5][5]={{1,1,1,1,0},
		     {1,1,1,0,0},
		     {1,1,1,0,1},
		     {1,0,0,1,0},
		     {0,0,1,0,1}};
	printf("\nEnter Start node: ");
	scanf("%d",&v);
	if(v<0 || v>4)         //check if entry out of bound
	{
		printf("\nInvalid entry\n");
		exit(0);
	}
	printf("\nEnter End node: ");
	scanf("%d",&d);
	if(v<0 || v>4) 		//check if entry out of bound
	{
		printf("\nInvalid entry\n");
		exit(0);
	}
	printf("\n"); 
	bfs(G,v,d);
	
	return 0;
}
	
