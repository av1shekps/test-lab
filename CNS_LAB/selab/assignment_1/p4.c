#include <stdio.h>
#include <ctype.h>

int main()
{	
	char str[100];
	int n;
	printf("Enter length of string : ");
	scanf("%d",&n);
	printf("Enter a string : ");
	scanf("%s", str);
        
	//int n = sizeof(str);
	
	for (int i = 0; i < n-1; i++) 
	{
      	for (int j = i+1; j < n; j++) 
      	{
         if (str[i] > str[j]) 
         {
            char c = str[i];
            str[i] = str[j];
            str[j] = c;
         }
    	}
       }
   	
   	
	printf("String after sorting is : %s \n",str);	
}
