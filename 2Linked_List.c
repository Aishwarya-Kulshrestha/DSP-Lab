#include <stdio.h>       //Adding libraries
#include <conio.h>
#include <stdlib.h>

void add();         //declaring functions
void delete();
void disp();
void search();


struct node         //structure definition
{
	int data;
	struct node *link;
};

void rev(struct node *prev, struct node *curr);     //declaring reverse function after the struct is defined
struct node *new_node, *head;             //global struct variables

void add()      //Adds new nodes to the Linked List
{
	new_node=(struct node *)malloc(sizeof (struct node *));
	new_node->link=NULL;
	printf("\nEnter a Number: ");
	scanf("%d",&new_node->data);
	if(head == NULL)
		head = new_node;
	
	else 
	{
		new_node->link = head;
		head = new_node;
	}
	return;
}

void delete()       //deletes a given node from the linked list
{
	int n;
	struct node *prober, *del;
	printf("\nEnter a Number to be deleted from Linked List: ");
	scanf("%d",&n);
	prober = head;
	if(prober->data==n)            //checking if the entered number isnt the 1st element
	{
		printf("\ndeleting %d...\n",prober->data);
		del = prober;
		head = prober->link;
		free(del);
		return;
	}
	
	while(prober -> link)
	{
		if(prober->link->data==n)
		{
			printf("\ndeleting %d...\n",prober->link->data);
			del = prober->link;
			prober->link = prober->link->link;
			free(del);
		}
		if(prober->link==NULL) return;
		prober=prober->link;
	}
	return;
}

void disp()        //prints the linked list
{
	struct node *prober;
	prober=head;
	printf("\n");
	while(prober)
	{
		printf("%d ",prober->data);
		prober=prober->link;
	}
	printf("\n");
	return;
}

void search()         //searches for the given element in the linked list
{ 
	struct node *prober; int c=0,n;
	prober=head;
	printf("\nEnter a Number to be searched from Linked List: ");
	scanf("%d",&n);
	while(prober)
	{
		c++;
		if(prober->data==n) 
		{
			printf("\nFound at pos no: %d",c);
			return;
		}
		prober=prober->link;
	}
	printf("\nNot Present in the List");
	return;
}
	
void rev(struct node *prev, struct node *curr)       //reverses the linked list
{
	if(curr)
	{
		rev(curr,curr->link);
		curr->link=prev;
	}
	else head=prev ;
	
	return;
}


void main()
{
	int n;int x=1;
	while(x)     //loops the choices until x becomes 0 i.e. user chooses to exit
	{
		printf("\nChoose an action: \nEnter 1 to add a node\nEnter 2 to search a node\nEnter 3 to delete a node\nEnter 4 to reverse the linked list\nEnter 5 to display the list\nEnter 6 to exit\n");
		scanf("%d",&n);
	switch (n)          //using switch case for choices
		{
			case 1: add(); break;
			case 2: search(); break;
			case 3: delete(); break;
			case 4: rev(NULL,head); break;
			case 5: disp(); break;
			case 6: x=0; break;
			default: printf("\nChoose from mentioned options only!\n");
		}
		
	}
	return;
}

	
	
		