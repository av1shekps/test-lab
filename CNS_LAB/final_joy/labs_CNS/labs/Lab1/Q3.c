#include<stdlib.h>
#include<stdio.h>

int main()
{
	char a[1024],res[1024];
	fgets(a, 1024, stdin);
	int n =0,i=0;
	while(a[n]!='\0')
	{
		char c=a[n];
		
		if((c>=65&&c<=90)||(c>=96&&c<=122))
		{
			res[i]=c;
			i++;
		}
		n++;
	}
	res[i]='\0';
	printf("%s\n",res);
	
}
