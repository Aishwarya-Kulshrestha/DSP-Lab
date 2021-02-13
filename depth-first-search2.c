#include <stdio.h>

int visited[6]={0,0,0,0,0,0};
int stack[10]={0,0,0,0,0,0,0,0,0,0};
int top=-1;
int flag=0;
	
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

int dfs(int G[6][6],int v,int d)
{
	
	visited[v]=1;
	if(v==d)
	{ 
		printf("%d",v+1);
		return 1;
	}
	printf("%d ->",v+1);
	
	for(int i=5;i>=0;i--)
		if(G[v][i]==1 && visited[i]==0)
			push(i);
			
	while(top!=-1)
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
	dfs(G,v-1,d-1);
	
	return 0;
}
			
	
