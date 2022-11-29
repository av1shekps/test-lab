#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *encrypt(char S[],char key[])
{
	int n = strlen(S);
	char *ans = (char *)(malloc(n+1));
	for(int i=0;i<n;i++)
	{
		if(S[i]>='A'&&S[i]<='Z')
		{
			ans[i]=key[S[i]-'A'];
		}
		else if(S[i]>='a'&&S[i]<='z')
		{
			ans[i]=key[S[i]-'a'];
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
	char keyinv[26];
	for(int i=0;i<26;i++)
	{
		keyinv[key[i]-'A']='a'+i;
	}
	for(int i=0;i<n;i++)
	{
		if(S[i]>='A'&&S[i]<='Z')
		{
			ans[i]=keyinv[S[i]-'A'];
		}
		else if(S[i]>='a'&&S[i]<='z')
		{
			ans[i]=keyinv[S[i]-'a'];
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
