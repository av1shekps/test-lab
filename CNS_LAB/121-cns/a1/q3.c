#include <stdio.h>

int main(){
	char s[100];

	printf("Enter the string: ");
	scanf("%s", s);

	printf("String after removing all the characters other than alphabets: ");
	int i=0;
	while(s[i]!=0){
		if(s[i]-'a'<=25 && s[i]-'a'>=0)
			printf("%c", s[i]);
		i++;
	}
	printf("\n");

	return 0;
}
