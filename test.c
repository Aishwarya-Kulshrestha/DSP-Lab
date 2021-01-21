#include <stdio.h>

int main()
{
	char str[10];
	int i=0; char ch;
	printf("\nenter string\n");
	scanf("%s",&str);
	while(!((ch=='\0')))
	{
		ch=str[i];
		//if(ch=='\0')
		printf("\n%c",ch);
		i++;
	}
	
	return 0;
}