#include <bits/stdc++.h>
using namespace std;

void encipher_text(string text, string mapper)
{
	string result;
	for(int i = 0;i < text.size();i++)
	{
		if(text[i]>= 'a' && text[i] <= 'z')
		text[i] = toupper(text[i]);
		if(text[i] >= 'A' && text[i] <= 'Z')
		result += mapper[text[i] - 'A'];
		else
		result += text[i];
	}
	cout<<"Enciphered string: "<<result<<endl;
}

int getIndex(string mapper, char c)
{
	for(int i = 0;i < mapper.size();i++)
	{
		if(mapper[i] == c)
		return i;
	}
	return 0;
} 

void decipher_text(string text, string mapper)
{
	string result;
	string seq = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for(int i = 0;i < text.size();i++)
	{
		if(text[i]>= 'a' && text[i] <= 'z')
		text[i] = toupper(text[i]);
		if(text[i] >= 'A' && text[i] <= 'Z')
		result += 'A' + getIndex(mapper, text[i]);
		else
		result += text[i];
	}
	cout<<"deciphered string: "<<result<<endl;
}

int main()
{
	string text;
	cout<<"Enter Text: ";
	getline(cin, text);
	string mapper = "HAXQGJEPIZWSBCTNYRFMLKODUV";
	int flag = 0;
	cout<<"Enter 1 for encryption and 0 for decryption: ";
	cin>>flag;
	if(flag)
	encipher_text(text, mapper);
	else
	decipher_text(text, mapper);
	return 0;
}
