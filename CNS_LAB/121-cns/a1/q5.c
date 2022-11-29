#include <stdio.h>

int main(){
	int size = 0;
	printf("Enter the size of the message: ");
	scanf("%d", &size);
	char s[size];
	printf("\nEnter the message word: ");
	scanf("%s", s);
	int parity = 0;

	int i = 0;
	while(i<size){
		if(s[i]=='1')
			parity++;

		i++;
	}


	printf("Codeword: %d%s\n", parity%2, s);

}
