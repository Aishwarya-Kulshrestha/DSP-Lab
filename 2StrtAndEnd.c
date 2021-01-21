#include <stdio.h>         //Adding libraries
#include <conio.h>
#include <stdlib.h>

void swap(int *a, int *b);         //declaring functions
void qisort(int *arr,int strt,int end);
void startnend(int *arr,int n,int end);

void swap(int *a, int *b)        //function to swap two values
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	return;
}

void qisort(int *arr,int strt,int end)    //this function Sorts the array using Quick sort
{
	if(strt<end)
	{
		int i=-1,j=0;
		if(strt==end) return;
	
		for(j=0;j<end;j++)
		{
			if(arr[j]>arr[end]);      //pivot is taken as the last elements here 
			
			else
			{ 
				i=i+1;
				swap(&arr[i],&arr[j]);
			}
		}
		i++;
		swap(&arr[i],&arr[end]);
	
		qisort(arr,0,i-1);     //recursive call to the same function after partitioning is done
		qisort(arr,i+1,j);      //recursive call on 2nd half of the array
	}
	
	return;
}

void startnend(int *arr,int n,int end)   //calculates start and end index of the number entered
{
	int sflag,eflag,i=0,c=0;
	while(i<=end)
	{
		if(arr[i]==n&&c==0)
		{
			sflag=i;
			c++;
		}
		if(arr[i]==n&&c!=0)
			eflag=i;
		
		i++;
	}
	if(c==0) printf("\nNo such number");	
	if(c!=0) printf("Number Found at index %d and last occurance at index %d", sflag+1,eflag+1);
	return;
}

void main()
{
	int *a,x,i,n=0;
    printf("Enter the No. of elements of the array: ");
    scanf("%d",&n);
    a = (int*)calloc(n, sizeof(int*));
    printf("\nenter elements: ");
    for(i=0;i<n;i++)                 //Taking elements of the array from user
	   scanf("%d",&a[i]);
	   
	for(i=0;i<n;i++)         //Printing the elements
	   printf("%d ",a[i]);

	qisort(a,0,n-1);       //sorting the array
	printf("\n");
	
	for(i=0;i<n;i++)       //printing the sorted array
	   printf("%d ",a[i]);
	
	printf("enter a num: ");     //asking number for finding its strt and end occurance in the array
	scanf("%d",&x);
	
	startnend(a,x,n-1);     //finding start and end occurance
	return;
}
		
	