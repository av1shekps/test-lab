#include<stdio.h>
#include<stdlib.h>

int main()
{
	int counter[26];
	for(int i=0;i<26;i++)
		counter[i]=0;
		
	char s[1024];
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
        counter[(int)(s[k] - 97)]++;
        k++;
    }
    
	printf("Count of char are:\n");
	for(int i=0;i<26;i++)
	{
		if(counter[i]!=0)
		{
			printf("%c -> %d \n", (char)(i+97), counter[i]);
		}
	}
	return 0;
}
