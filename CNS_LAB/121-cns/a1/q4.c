#include <stdio.h>

int main(){
	char s[100];

	printf("Enter the string\n");
        scanf("%s", s);
        int freq[26];
        for(int i =0; i<26;i++){
                freq[i]=0;
        }
        int i = 0;
        while(s[i]!='\0'){
                freq[s[i]-'a']++;
                i++;
        }

	printf("Characters sorted in lexicographical order: ");

        for(i = 0; i<26; i++){
                for(int j=0; j<freq[i]; j++)
			printf("%c", 'a'+i);
        }
		
	printf("\n");

	return 0;

}
