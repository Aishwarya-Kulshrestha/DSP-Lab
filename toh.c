#include <stdio.h>
#include <conio.h>

void hanoi(int n,char s,char d,char e);

int count;

void hanoi(int n,char s,char d,char e)
{
	if(n==0) return;
	hanoi(n-1,s,e,d);
	printf("\nPEG %c-> PEG %c",s,d);count++;
	hanoi(n-1,e,d,s);
	return;
}

void main()
{
	count=0;
	int n;char s='S', d='D', e='E';
	printf("\nenter count of disks: ");
	scanf("%d",&n);
	hanoi(n,s,d,e);
	printf("\n\nTotal moves: %d\n\n",count);
}