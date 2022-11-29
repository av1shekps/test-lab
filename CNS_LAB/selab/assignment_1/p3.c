#include <stdio.h>
#include <ctype.h>

int main()
{	
	char str[100];
	printf("Enter a string : ");
	scanf("%s", str);
        
	char ans[100];
	
	int k=0;
	
	for(int i=0;i<sizeof(str);i++)
	{
	char c = str[i];
	
	if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
	ans[k]=str[i];
	//printf("%c\n",str[i]);
	k++;
	}
	}
	
	
	int i=0;
	
	while(i!=k)
	{
	printf("%c",ans[i]);
	i++;
	}
	
	printf("\n");	
}
