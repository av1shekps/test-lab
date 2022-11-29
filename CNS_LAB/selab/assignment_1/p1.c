#include <stdio.h>
#include <ctype.h>

int main()
{	
	char str[]="Hello World";
	int arr[26];
	int arr1[26];
	
	printf("String is %s\n",str);
	for(int i=0;i<26;i++)
	{
	arr[i]=0;
	arr1[i]=0;
	}
	
	for(int i=0;i<sizeof(str);i++)
	{
	if(islower(str[i]))
	{
	arr[str[i]-'a']++;
	}
	if(isupper(str[i]))
	{
	arr1[str[i]-'A']++;
	}
	}
	
	for(int i=0;i<26;i++)
	{
	printf("%c -> %d |  %c -> %d\n",'a'+i,arr[i],'A'+i,arr1[i]);
	}	
}





