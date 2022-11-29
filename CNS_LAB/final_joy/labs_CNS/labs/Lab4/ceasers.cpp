#include<iostream>
#include<string>
using namespace std;
void encrypt(string s, int k)
{
	string ans=s.size();
	for (int i = 0; i < s.length(); i++)
	{
		if(isalpha(s[i]))
			ans [i] = 'a' + (s[i] - 'a' + k)%26;
		else
			ans[i]=s[i];
		
	}
	cout<<"The encrypted string is :"<<ans<<endl;	
}
void decrypt(string s, int k)
{
	string ans=s.size();
	for (int i = 0; i < s.length(); i++)
		{if(isalpha(s[i]))
			ans [i] = 'a' + (s[i] - 'a' - k + 26)%26;
		else
			ans[i]=s[i];	
	}
	cout<<"The decypted string is :"<<ans<<endl;	
}
int main()
{
	int k;
	
	cout<<"Enter the shift:";
	cin>>k;
	cout<<"Enter the string to encrypt:";
cin.ignore();
	string s;	
	getline (cin, s);
	//cout<<s;
	encrypt(s,k);
	cout<<"Enter string to decrypt:";
	getline (cin, s);
	decrypt(s,k);
	return 0;
}
