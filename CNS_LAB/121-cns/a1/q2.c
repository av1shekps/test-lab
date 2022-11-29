#include <stdio.h>

void reverse(char s[100],int i){
	if(s[i]=='\0'){
		return;
	}
	reverse(s, i+1);
	printf("%c", s[i]);
	return;
}

int main(){
	char s[100];

	printf("Enter the string to be reversed\n");
	scanf("%s", s);
	printf("Reversed string: ");
	reverse(s, 0);
	printf("\n");
	return 0;
}
