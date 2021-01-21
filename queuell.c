/*This program is an implementation of QUEUE using Linked List as basic Data structure.
I have used 3 functions and a main function.*/

#include <stdio.h>     //adding libraries
#include <conio.h>
#include <stdlib.h>

void enqueue();     //function declaration
void dequeue();
void display();

struct node        //Struct for node
{
	int data;
	struct node *link;
};

struct node *rear,*front;     //Global Variables

void enqueue()       //adds an element at the rear and of the queue
{
	struct node *nn=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter data: \n");
	scanf("%d",&nn->data);
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
	/*struct node *nn=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter data: ");
	scanf("%d",&nn->data);
	nn->link=NULL;
	rear->link=nn;
	rear=nn;
	return;*/
}

void dequeue()          //removes an element from the front of the queue
{
	struct node *t;
	if(front==NULL)            //check for underflow
	{ 
		printf("\nQueue Empty \n");
		return;
	}
	else 
	{
		printf("\n%d ",front->data);
		t=front;
		front=front->link;
		free(t);
	}
	return;
}

void display()        //display all elements of the queue
{
	struct node *t;
	t=front;
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
	int c,ext=0;front=rear=NULL;
	while(ext!=1)                     //Loops the following choices until user exits the menu
	{
		printf("Choose from the options below: \n1.enqueue\n2.Dequeue\n3.Display\n4.Exit.\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1: enqueue(); break;
			case 2: dequeue(); break;
			case 3: display(); break;
			case 4: ext=1;
		}
	}
	return;
}