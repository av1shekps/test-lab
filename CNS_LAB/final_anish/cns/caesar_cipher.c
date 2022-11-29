#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *encrypt(char S[],int k)
{
	char *ans = (char *)(malloc(strlen(S)+1));
	for(int i=0;i<strlen(S);i++)
	{
		if(S[i]>='A'&&S[i]<='Z')
			ans[i]=(S[i]-'A'+k)%26+'A';
		else if(S[i]>='a'&&S[i]<='z')
			ans[i]=(S[i]-'a'+k)%26+'a';
		else
			ans[i]=S[i];
	}
	return ans;
}
char *decrypt(char S[],int k)
{
	char *ans = (char *)(malloc(strlen(S)+1));
	for(int i=0;i<strlen(S);i++)
	{
		if(S[i]>='A'&&S[i]<='Z')
			ans[i]=(S[i]-'A'-k+26)%26+'A';
		else if(S[i]>='a'&&S[i]<='z')
			ans[i]=(S[i]-'a'-k+26)%26+'a';
		else
			ans[i]=S[i];
	}
	return ans;
}
int main()
{
	char S[1000];
	printf("\nEnter the String to be Encrypted : ");
	scanf("%[^\n]s",S);
	int key;
	printf("Enter the number of key shifts : ");
	scanf("%d",&key);
	char *enc;
	enc = encrypt(S,key);
	printf("\nEncryption of %s String is %s\n\n",S,enc);
	char *dec;
	dec = decrypt(enc,key);
	printf("Decryption of %s String is %s\n\n",enc,dec);
	return 0;
}
