/*This Program uses a doubly linked list and a hash table to sort the given numbers using radix sort*/

#include<stdio.h>
#include<stdlib.h>     //included for malloc function
#include<math.h>    //included for pow function

struct node       //double list node structure
{
	struct node *left;
	int data;
	struct node *right;
};

struct node *new_node, *curr_node,*prober,*head, *arr[10]; //global variables
int size=10;int n=0;int loop_c=0;

int insert();        //function declaration
void radix();
void push(int d, int pos);
void init_arr();
void disp();

int insert()          //inserts the elements into the linked list one by one
{
	int i=0,temp_max=0,flag=0;
	scanf("%d",&n);
	if(n<=0) flag=-1;   //check for any 0 or -ve number entered as number of elements
	while(i<n)
	{
		new_node=(struct node *) malloc(sizeof (struct node *));
		scanf("%d",&new_node->data);
		if((new_node->data)<0) flag=-1;       //check for any -ve number entered
		if((new_node->data)>temp_max) temp_max=new_node->data;   //checking and storing the max number entered
		if(i==0)     //If its the 1st node of the list
		{
			new_node->left=NULL;
			head=new_node;
			curr_node=new_node;
			i++;
			continue;
		}
		if(i==n-1) new_node->right=NULL;      //if its the last node of the list
		
		curr_node->right=new_node;
		new_node->left=curr_node;
		curr_node=new_node;
		
		i++;
	}
	while(temp_max!=0)     //computing the number of digits of the max number
	{
	    temp_max=temp_max/10;
	    loop_c++;   //stores the number of digits
	}
	if(flag==-1) return flag;   //Flags any Invalid input
	return 0;
}

void radix()          //sorts the list using radix sort
{
	int div=0;int i=0,temp;
	struct node *probe1=head, *probe2=head;
	for(i=0;i<loop_c;i++)     //loops for the number of digits in the max number of the list
	{                         //eg. if max number was 345 then it will loop 3 times
	    init_arr();//flushes the array
	    probe1=head;
	    probe2=head;
		while(probe1)       //takes a number from the list and places it in the array acc to its key value
		{
		    temp=probe1->data;
			div=((probe1->data)/(int)pow(10, i))%10;  //calculating digit acc to the count of pass
			push(temp,div);
			
			probe1=probe1->right;  
		}
		for(int j=0;j<size;j++)   //puts back the partially sorted elements of array into the double Linked list
		    if(arr[j]!=NULL)
	        {
		        probe1=arr[j];
		        while(probe1) 
		        {
			        probe2->data=probe1->data;
			        probe1=probe1->right;
			        probe2=probe2->right;
		        }
		
	        }
	}
	return;
}

void push(int d, int pos)       //pushes element into the array acc to given key value
{
	new_node=(struct node *) malloc(sizeof (struct node *));
	new_node->left=NULL;
	new_node->data=d;
	new_node->right=NULL;
	
	if(arr[pos]==NULL) 
		arr[pos]=new_node;
		
	else
	{
		prober=arr[pos];
		while(prober->right) 
			prober=prober->right;
		
		new_node->left=prober;
		prober->right=new_node;
	}
	return;
}
			

void init_arr()      //intialises the array with NULL
{
	for(int i=0;i<size;i++)
	{
	    free(arr[i]);
	    arr[i]=NULL;
	}
		
	return;
}

void disp()    //displays the linked list
{
	prober=head;
	while(prober)
	{
		printf("%d ",prober->data);
		prober=prober->right;
	}
	return;
}

int main()  
{
    int flag=0;
	init_arr();
	flag=insert();
	if(flag==-1) printf("INVALID INPUT"); //check for invalid inputs
	else
	{
	    radix();
	    disp();
	}
	
	return 0;
}