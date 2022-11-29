#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *encrypt(char S[],char key[])
{
	int n = strlen(S);
	char *ans = (char *)(malloc(n+1));
	char *fullkey = (char *)(malloc(n+1));
	int j=0;
	for(int i=0;i<n;i++)
	{
		if(key[j]>='a'&&key[j]<='z')
			fullkey[i]=key[j]-'a'+'A';
		else
			fullkey[i]=key[j];
		j++;
		if(j==strlen(key))
			j=0;
	}
	for(int i=0;i<n;i++)
	{
		if(S[i]>='A'&&S[i]<='Z')
		{
			ans[i]=(fullkey[i]-'A'+S[i]-'A')%26+'A';
		}
		else if(S[i]>='a'&&S[i]<='z')
		{
			ans[i]=(fullkey[i]-'A'+S[i]-'a')%26+'a';
		}
		else
		{
			ans[i]=S[i];
		}
	}
	return ans;
}

char *decrypt(char S[],char key[])
{
	int n = strlen(S);
	char *ans = (char *)(malloc(n+1));
	char *fullkey = (char *)(malloc(n+1));
	int j=0;
	for(int i=0;i<n;i++)
	{
		if(key[j]>='a'&&key[j]<='z')
			fullkey[i]=key[j]-'a'+'A';
		else
			fullkey[i]=key[j];
		j++;
		if(j==strlen(key))
			j=0;
	}
	for(int i=0;i<n;i++)
	{
		if(S[i]>='A'&&S[i]<='Z')
		{
			ans[i]=(S[i]-'A'-(fullkey[i]-'A')+26)%26+'A';
		}
		else if(S[i]>='a'&&S[i]<='z')
		{
			ans[i]=(S[i]-'a'-(fullkey[i]-'A')+26)%26+'a';
		}
		else
		{
			ans[i]=S[i];
		}
	}
	return ans;
}

int main()
{
	char key[1000],S[1000];
	printf("\nEnter the Alphabetic Key : ");
	scanf("%[^\n]s",key);
	printf("Enter the String to be encrypted : ");
	getchar();
	scanf("%[^\n]s",S);
	char *enc;
	enc = encrypt(S,key);
	printf("\nEncryption of %s String is %s\n\n",S,enc);
	char *dec;
	dec = decrypt(enc,key);
	printf("Decryption of %s String is %s\n\n",enc,dec);
	return 0;
}
