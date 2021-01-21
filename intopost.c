#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

char a[200], opstack[200], post[200]; int operand[200];
int top1,top2,top3,max;

void display(char *array);
void push(char *a,char ch,int *top);
char pop(char *a,int *top);
void intopost();
void postsol();
int popI(int *a,int *top);
void pushI(int *a,int ch,int *top);

void push(char *a,char ch,int *top) //pushes an element into the stack
{	

	*top=*top+1;
	a[*top]=ch;
	return;
}

void pushI(int *a,int ch,int *top) //pushes an element into the stack
{	

	*top=*top+1;
	a[*top]=ch;
	return;
}

char pop(char *a,int *top)  //pops an element from the stack
{
	int temp=0;
	if(*top==-1)  //check for underflow
	{	
		a[0]='\0';
		return '\0';
	}
	else
	{
		temp=*top;
		*top=*top-1;
		return a[temp];
		
	}
}

int popI(int *a,int *top)  //pops an element from the stack
{
	int temp=0;
	if(*top==-1)  //check for underflow
	{	
		return 0;
	}
	else
	{
		temp=*top;
		*top=*top-1;
		return a[temp];
		
	}
}

void intopost()
{
	int c=0,i=0,j=0;
	printf("Enter the equation: ");
	gets(a);
	
	while(a[i])
	{
		i++;
		c++;
	}

	for(i=0;i<c;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			post[j]=a[i];
			j++;
		}
		
		else if(a[i]=='*'||a[i]=='/')
		{
			if(opstack[top1]=='/'||opstack[top1]=='*') 
			{
				post[j]=pop(opstack,&top1);
				j++;
				push(opstack,a[i],&top1);
			}
			
			//if(opstack[top1]!='/'||opstack[top1]!='*')
			else push(opstack,a[i],&top1);
							
		}
			
		else //if(a[i]=='+'||a[i]=='-')
		{
			if(opstack[top1]=='/'||opstack[top1]=='*'||opstack[top1]=='+'||opstack[top1]=='-')
			{
				post[j]=pop(opstack,&top1);
				j++;
				push(opstack,a[i],&top1);
			}
			
			else push(opstack,a[i],&top1);
		}
			
	}

	if(top1!=-1) 
	{
		while(top1!=-1)
		{
			post[j]=pop(opstack,&top1);
			j++;
		}
	}
		
	display(post);
	return;
}

void display(char *array)
{
	int i=0;
	while(array[i])
	{
		printf("%c ",array[i]);
		i++;
	}
		
	return;
}

void postsol()
{
	int i=0,a,b,s; char ch; char c;
	while(post[i])
	{
		if(post[i]>='0'&&post[i]<='9')
		{
			c=post[i];
			a=c-'0';
			pushI(operand,a,&top2);
		}
		
		else 
		{
			ch=post[i];
			a=popI(operand,&top2);
			b=popI(operand,&top2);
			switch(ch)
			{
				case '+': s=a+b; pushI(operand,s,&top2);break;
				case '-': s=a-b; pushI(operand,s,&top2);break;
				case '/': s=a/b; pushI(operand,s,&top2);break;
				case '*': s=a*b; pushI(operand,s,&top2);
			}			
		}
		
		i++;		
	}
	printf("\nthe solution for the equaion= %d",operand[0]);
}
		
		
void main()
{
	max=200;
	top1=top2=top3=-1;
	intopost();
	postsol();
	return;
}

	
	
		
	
