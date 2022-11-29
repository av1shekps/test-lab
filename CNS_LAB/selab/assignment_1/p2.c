#include <stdio.h>
#include <ctype.h>

void rev() 
{
    char c;
    scanf("%c", &c);
    
    if (c != '\n') 
    {
        rev();
        printf("%c", c);
    }
}

int main()
{
    printf("Enter a string\n");
    rev();
    printf("\n");
}




