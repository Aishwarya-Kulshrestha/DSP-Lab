/*This program is an implementation of stack data structure using Array as basic Data structure.
I have used 3 functions and a main function.*/

#include <stdio.h>   //adding Libraries
#include <conio.h>
#include <stdlib.h>

int push(int *a);   //function declaration
int pop(int *a);
void display(int *a);

int top; int max;     //global variables

int push(int *a) //pushes an element into the stack
{	
	top++;
	if(top==max)  //check for overflow
	{
		printf("\nstack full\n");
		return 0;
	}
	else
	{
		scanf("%d",&a[top]);
		return 0;
	}
}

int pop(int *a)  //pops an element from the stack
{
	if(top==-1)  //check for underflow
	{ 
		printf("\nstack empty\n"); 
		return 0;
	}
	else
	{
		printf("\n%d\n",a[top]);
		top--;
		return 0;
	}
	return 0;
}
	
void display(int *a)  //displays all elements of the stack
{ 
	int i=0;
	printf("\n");
	while(i<max)
	{	
		printf("%d ",a[i]);
		i++;
	}
	printf("\n");
	return;
}


void main()
{
	top=-1;max=0;
	int *a,c,ext=0;
	while(ext!=1)    //Loops the following choices until user exits the menu
	{
		printf("Choose from the options below: \n1.Push\n2.Pop\n3.Display\n4.Create\n5.Exit.\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1: push(a); break;
			case 2: pop(a); break;
			case 3: display(a); break;
			case 4: 
				printf("\nEnter the size of stack: ");
				scanf("%d",&max);
				a=(int*)calloc(max, sizeof(int*)); 
				break;
			case 5: ext=1;
		}
	}
	return;
}