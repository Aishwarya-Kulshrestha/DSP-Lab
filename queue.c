/*This program is an implementation of QUEUE using array as basic Data structure.
I have used 3 functions and a main function.*/

#include <stdio.h>     //adding Libraries
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int enqueue(int *a);      //function definitions
int dequeue(int *a);
void display(int *a);

int front; int rear; int n;        //Global Variables

int enqueue(int *a)      //adds an element at the rear and of the queue
{	
	rear=(rear+1)%n;
	if(front==rear)        //check for overflow
	{
		printf("\nQueue is FULL ");
		if(rear==0)
			rear=n-1;
		else rear=rear-1;
	}
	else 
		scanf("%d",&a[rear]);
	return 0;
}

int dequeue(int *a)      //removes an element from the front of the queue
{
	if(front==rear)       //check for underflow
	{
		printf("\nQueue is EMPTY ");
		return 0;
	}
	else
	{
		front=(front+1)%n;
		printf("\n%d ",a[front]);
		a[front]='\0';
		return 0;
	}
	return 0;
}
	
void display(int *a)    //display all elements of the queue
{ 
	int i=(front+1)%n;
	printf("\n");
	while(i<=rear)
	{	
		printf("%d ",a[i]);
		i++;
	}
	printf("\n");
	return;
}


void main()
{
	front=rear=0;n=0;
	int *a,c,ext=0;
	while(ext!=1)       //Loops the following choices until user exits the menu
	{
		printf("Choose from the options below: \n1.Enqueue\n2.Dequeue\n3.Display\n4.Create\n5.Exit.\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1: enqueue(a); break;
			case 2: dequeue(a); break;
			case 3: display(a); break;
			case 4: 
				printf("\nEnter the size of Queue: ");
				scanf("%d",&n);
				n++;
				a=(int*)calloc(n, sizeof(int*)); 
				break;
			case 5: ext=1;
		}
	}
	return;
}