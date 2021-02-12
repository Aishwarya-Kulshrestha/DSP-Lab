#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *arr[10]; 		//Array of pointers for Adjacency List
int mark_arr[10];   		//Integer Array for marking vertices with grp numbers


void disp(int V) 		//Function to print the adjacency list
{
	printf("\nThe Adjacency List is: \n");
	int i;
	struct node *prober=arr[0];
	for(i=0;i<=V;i++)        //loop to traverse index of array of pointers
	{
		prober=arr[i];
		while(prober) 	 //loop to traverse the list at the index i
		{
			printf("%d->%d ",i,prober->data);
			prober=prober->link;
		}
		printf("\n");
	}
	return;
}


void ConComp(int V) 		//function to calculate Connected components
{
	int marker=0;	//marker holds the current grp number to marks the vertex with it
	grpCount=1;  	//grpCount holds the total group count				
	int i;
	
	for(i=0;i<10;i++)	//loop to initialise mark_arr[] with 0
		mark_arr[i]=0;
	
	struct node *prober=arr[0];
	for(i=1;i<=V;i++)     //loop to traverse each vertex of the graph
	{
		if(mark_arr[i]==0)    //Check to see if the selected vertex is marked to a group
		{ 
			mark_arr[i]=grpCount;    //marking the vertex to a group by initialising its index pos in mark_arr[] by grpCount
			grpCount++;    
		}
		
		marker=mark_arr[i];	//initialising the marker with the group no. of the vertex
		
		prober=arr[i];   
		while(prober)		//loop to traverse the adjacency list of selected vertex 
		{			//and mark all the adjascent vertices with the same grp number
			
			if(mark_arr[prober->data]==0)	//check to see if connected vertex is unmarked with the group no.
			{
				mark_arr[prober->data]=marker;
				prober=prober->link;
			}
			
			else 
			{
				if(mark_arr[prober->data]<marker)    //check to see if the current group number is greater than the vertexs' grp no.
				{
					struct node *probe2=arr[i];  //probe2 traverses the list from begining
					int marker2=mark_arr[prober->data];  //marker2 will hold the lesser group number
					while(probe2!=prober) 		//loop to mark all vertices connected to vertex i with the lower grp number
					{
						mark_arr[probe2->data]=marker2;
						probe2=probe2->link;
					}
					marker=mark_arr[prober->data];   //changing the value of marker with the lower group number
				}
				else mark_arr[prober->data]=marker;    
   				
				prober=prober->link;
			}	
			
		}
	}
	printf("The number of connected components is %d\n",grpCount-1);   //printing number of connected components
	return;
}


void main()
{

	struct node *prober;
	int i=0,d,V,E;
	
	for(i=0;i<10;i++)      //initialising the Array of pointers with NULL
		arr[i]=NULL;
	
	char ch1,ch2;		//variables to hold 2 characters being read from file
	
	ch1 = getchar();	//reading the first character of the first line which will give us the number of vertices
	V=ch1-'0'; 		//converting char to int and storing it in V (no. of Vertices)
	
	ch1 = getchar();	//reading white space and discarding it
	
	ch2 = getchar();
	E=ch2-'0';		//converting char to int and storing it in E (no. of Edges)
	
	ch2 = getchar();	//reading a new line character and discarding it
	
	while(ch2!=EOF||ch1!=EOF)	//check to see if EOF reached
	{
		ch1 = getchar();
		if(ch1==EOF) break;
		
		struct node *new_node=(struct node *)malloc(sizeof(struct node));
		new_node->link=NULL;
		d=ch1-'0';
			
		ch2 = getchar();
		if(ch2==EOF) break;
	
		ch2 = getchar();
		if(ch2==EOF) break;
		new_node->data=ch2-'0';
		
		prober=arr[d];
		if(arr[d]!=NULL)  	//check to see if vertex 'd' is pointing to any other vertex or not
		{
			
			while(prober->link)	//probing to last node
				prober=prober->link;
			
			prober->link=new_node;	//adding new node to last node
			
		}
		else arr[d]=new_node;
				
		ch2=getchar();
	}

	disp(V);    //calling function to display the adjacency list
	ConComp(V);	//calling fxn to calculate connected components
	return;
}


