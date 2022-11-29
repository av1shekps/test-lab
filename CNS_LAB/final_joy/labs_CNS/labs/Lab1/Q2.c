#include<stdlib.h>
#include<stdio.h>


void revstring(char* s,int index, int size)
{
	if(index==size)
		return;
	else
	{
	    char temp = s[index];    
    	revstring(s, index+1, size);
    	printf("%c", temp);  
	}
}
int main()
{
	char a[1024];
	fgets(a, 1024, stdin);
	int n =0;
	while(a[n]!='\0')
		n++;

	printf("Reverse string is :");
	revstring(a,0,n);
	printf("\n");
	return 0;
}
