#include <stdio.h>
#include <ctype.h>

int main()
{	
	int msg[100];
	int n;
	printf("Enter size of the message : ");
	scanf("%d",&n);
	printf("Enter the message : ");
	
	
	for(int i=0;i<n;i++)
	{
	scanf("%d",&msg[i]);
	}
       
        
        int k=0;
        
        for(int i=0;i<n;i++)
        {
        k=k^msg[i];
        }
        if(k)
        printf("1");
        else
        printf("0");
        
        for(int i=0;i<n;i++)
        {
        printf("%d",msg[i]);
        }
        printf("\n");
        	
}
