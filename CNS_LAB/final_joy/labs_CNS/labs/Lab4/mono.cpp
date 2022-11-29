#include <bits/stdc++.h>
using namespace std;

string mapping_encrypt, mapping_decrypt;


string encrypt(string &s)
{
	string ans;
	for (int i = 0; i < s.size(); i++)
	{	if(isalpha(s[i]))
		ans.push_back(mapping_encrypt[s[i]-'a']);
		else
		ans.push_back(s[i]);
	}
	return ans;
}

string decrypt(string &s)
{
	string ans;
	for (int i = 0; i < s.size(); i++)
	{
		if(isalpha(s[i]))
		ans.push_back(mapping_decrypt[s[i]-'a']);
		else
		ans.push_back(s[i]);
	}return ans;
}

int main()
{
	char x;
	mapping_encrypt = "dbpqozifamnvkxtjrceghwyuls";
	string s;
	for (int i = 0; i< 26; i++)
	{
		mapping_decrypt[mapping_encrypt[i] - 'a'] = 'a' + i;
	}
	cout<<"enter string to encrypt : ";
	//cin.ignore();
	
	getline (cin, s);
	cout<<"The encrypted string is : "<<encrypt(s)<<"\n";
	//cin.ignore();
	cout<<"enter string to decrypt : ";
	
	getline (cin, s);
	cout<<"The decrypted string is : "<<decrypt(s)<<"\n";
	return 0;
}
