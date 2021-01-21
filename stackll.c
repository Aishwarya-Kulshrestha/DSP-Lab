/*This program is an implementation of stack data structure using Linked List as basic Data structure.
I have used 3 functions and a main function.*/

#include <stdio.h>   //adding Libraries
#include <conio.h>
#include <stdlib.h>

int push();     //function declaration
int pop();
void display();

struct node      //struct for node
{
	int data;
	struct node *link;
};

struct node *top;     //global variables

int push()        //pushes an element into the stack
{
	struct node *nn=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter data: \n");
	scanf("%d",&nn->data);
	if(top==NULL)
	{ 
		nn->link=NULL;
		top=nn;
	}
	else
	{
		nn->link=top;
		top=nn;
	}
	return 0;
}

int pop()     //pops an element from the stack
{
	struct node *t; int item;
	if(top==NULL)                //check for underflow
	{ 
		printf("\nStack Empty \n");
		return 0;
	}
	else 
	{
		printf("\n%d \n",top->data);
		t=top;
		top=top->link;
		free(t);
	}
	return 0;
}

void display()     //displays all elements of the stack
{
	struct node *t;
	t=top;
	while(t!=NULL)
	{
		printf("%d ",t->data);
		t=t->link;
	}
	printf("\n");
	return;
}

void main()         
{
	int c,ext=0;top=NULL;
	while(ext!=1)           //Loops the following choices until user exits the menu
	{
		printf("Choose from the options below: \n1.Push\n2.Pop\n3.Display\n4.Exit.\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1: push(); break;
			case 2: pop(); break;
			case 3: display(); break;
			case 4: ext=1;
		}
	}
	return;
}