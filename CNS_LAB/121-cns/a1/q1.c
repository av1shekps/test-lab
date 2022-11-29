#include <stdio.h>

int main(){
	char s[100];
	printf("Enter the string\n");
	scanf("%s", s);
	printf("\nCounting frequency of characters in string");
	int freq[26];
	for(int i =0; i<26;i++){
		freq[i]=0;
	}
	int i = 0;
	while(s[i]!='\0'){
		freq[s[i]-'a']++;
		i++;
	}

	for(i = 0; i<26; i++){
		printf("Frequency of %c is %d\n", 'a'+i, freq[i]);
	}
	return 0;
}
