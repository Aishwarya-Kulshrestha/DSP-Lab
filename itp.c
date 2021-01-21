#include <stdio.h>
#include <stdlib.h>

char eqn[50],opStack[50];
int top=-1;

struct node
{
	char data;
	struct node *link;
};

struct node *rear,*front;

void enqueue(char ch)
{
	struct node *nn=(struct node *)malloc(sizeof(struct node));
	nn->data=ch;
	nn->link=NULL;
	if(rear==NULL)
	{ 
		rear=nn;
		front=rear;
	}
	else
	{
		rear->link=nn;
		rear=nn;
	}
	return;
}

char dequeue()   
{
	struct node *temp; char ch;
	if(front==NULL)  
	{ 
		printf("\nQueue Empty \n");
		return ' ';
	}
	else 
	{
		ch=front->data;
		temp=front;
		front=front->link;
		free(temp);
		return ch;
	}
}

void display()
{
	struct node *temp;
	temp=front;
	while(temp!=NULL)
	{
		printf("%c ",temp->data);
		temp=temp->link;
	}
	printf("\n");
	return;
}

void push(char ch)
{	
	top++;
	opStack[top]=ch;
	return;
}

char pop()
{
	char temp;
	if(top==-1)
	{ 
		printf("\nstack empty\n"); 
		return ' ';
	}
	else
	{
		temp=opStack[top];
		top--;
		return temp;
	}
	return ' ';
}

void InToPost()
{
	char ch, TempCh; int i=0;
	scanf("%s",&eqn);
	
	while(1)
	{
		ch=eqn[i];
		
		if(ch=='\0') 
			break;
		
		i++;
		
		if(ch>='0'&&ch<='9')
			enqueue(ch);
		
		else if(ch=='+'||ch=='-')
			{
				if(opStack[top]=='+'||opStack[top]=='-'||top==-1)
					push(ch);
				else 
				{
					TempCh=pop();
					enqueue(TempCh);
					push(ch);
				}
			}
			
		else push(ch);
	}
	
	while(top!=-1)
	{
		TempCh=pop();
		enqueue(TempCh);
	}
	
	display();
	return;
}

int main()
{
	InToPost();
	return 0;
}
		
			
			
		
		
		
		
	