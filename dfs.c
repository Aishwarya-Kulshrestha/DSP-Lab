#include <stdio.h>
#include <stdlib.h>           //for exit() fxn

int visited[5]={0,0,0,0,0};
int stack[10]={0,0,0,0,0,0,0,0,0,0};
int top=-1;
int flag=0;          //flags is set to 1 when the node is found
	
int push(int i)
{
	top++;
	stack[top]=i;
	return 0;
}

int pop()
{
	int temp;
	if(top==-1) return 0;
	temp=stack[top];
	top--;
	return temp;
}	

int dfs(int G[5][5],int v,int d)
{
	
	visited[v]=1;      //sets the positiion of node to 1 indicating it has been visited
	if(v==d)    //returns 1 to the calling fxn when the node is found
	{ 
		printf("%d",v);
		return 1;
	}
	printf("%d ->",v);
	
	for(int i=4;i>=0;i--)         //I ran this loop in reverse order just bec they pop inorder from stack
		if(G[v][i]==1 && visited[i]==0)
			push(i);
			
	while(top!=-1)          //running loop until all nodes from stack are popped and visited
	{
		if(visited[stack[top]]==0 && flag==0)
			flag=dfs(G,pop(),d);
		
		else top--;
	}
	return 0;
}

int main()
{
	int v,d;
	int G[5][5]={{1,1,1,1,0},
				{1,1,1,0,0},
				{1,1,1,0,1},
				{1,0,0,1,0},
				{0,0,1,0,1}};
	printf("\nEnter Start node: ");
	scanf("%d",&v);
	if(v<0 || v>4)
	{
		printf("\nInvalid entry\n");
		exit(0);
	}
	printf("\nEnter End node: ");
	scanf("%d",&d);
	if(v<0 || v>4)
	{
		printf("\nInvalid entry\n");
		exit(0);
	}
	printf("\n"); 
	dfs(G,v,d);
	
	return 0;
}
			
	

			
	
