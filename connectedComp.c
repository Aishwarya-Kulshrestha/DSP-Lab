#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *arr[10];int mark_arr[10];


void disp(int V)
{
	printf("\nThe Adjacency List is: \n");
	int i;
	struct node *prober=arr[0];
	for(i=0;i<=V;i++)
	{
		prober=arr[i];
		while(prober)
		{
			printf("%d->%d ",i,prober->data);
			prober=prober->link;
		}
		printf("\n");
	}
	return;
}


void ConComp(int V)
{
	int marker=0,grpCount=1;
	int i;
	
	for(i=0;i<10;i++)
		mark_arr[i]=0;
	
	struct node *prober=arr[0];
	for(i=1;i<=V;i++)
	{
		if(mark_arr[i]==0)
		{
			mark_arr[i]=grpCount;
			grpCount++;
		}
		
		marker=mark_arr[i];
		
		prober=arr[i];
		while(prober)
		{
			if(mark_arr[prober->data]==0)
			{
				mark_arr[prober->data]=marker;
				prober=prober->link;
			}
			
			else 
			{
				if(mark_arr[prober->data]<marker)
				{
					struct node *probe2=arr[i]; int marker2=mark_arr[prober->data];
					while(probe2!=prober)
					{
						mark_arr[probe2->data]=marker2;
						probe2=probe2->link;
					}
					marker=mark_arr[prober->data];
				}
				else mark_arr[prober->data]=marker;
   				
				prober=prober->link;
			}	
			
		}
	}
	printf("The number of connected components is %d\n",grpCount-1);
	return;
}


void main()
{

	struct node *prober;
	int i=0,d,V,E;
	
	for(i=0;i<10;i++)
		arr[i]=NULL;
	
	char ch1,ch2;
	
	ch1 = getchar();
	V=ch1-'0';
	ch1 = getchar();
	ch2 = getchar();
	E=ch2-'0';
	ch2 = getchar();
	
	while(ch2!=EOF||ch1!=EOF)
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
		if(arr[d]!=NULL) 
		{
			
			while(prober->link)
				prober=prober->link;
			
			prober->link=new_node;
			
		}
		else arr[d]=new_node;
				
		ch2=getchar();
	}

	disp(V);
	ConComp(V);
	return;
}


