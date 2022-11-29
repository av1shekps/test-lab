#include<stdio.h>
#include<stdlib.h>

int main()
{
	int counter[26];
	for(int i=0;i<26;i++)
		counter[i]=0;
		
	char s[1024],res[1024];
	printf("Enter the string(lowercase alphabets) :");
	
	scanf("%s",s);
	
	//int n=strlen(s);
	/*for(int i=0;i<10;i++)
	{
		printf("%c",s[i]);
	}
*/
	int k=0;
	while (s[k] != '\0') 
	{
        counter[(int)s[k] - 97]++;
        k++;
    }
    
	printf("Count of char are:\n");
	int index = 0;
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<counter[i];j++)
		{
			res[index]=(char)(i+97);
			index++;
		}
	}
	printf("%s\n",res);
	return 0;
}
