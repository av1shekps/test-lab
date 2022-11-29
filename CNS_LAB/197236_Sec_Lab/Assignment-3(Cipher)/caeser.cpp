#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void cipher_text(string text, int shift)
{
	string enc;
	for (int i=0;i<text.length();i++)
	{
        if (isupper(text[i]))
            	enc += char(int(text[i]+shift-65)%26 +65);
    	else
        	enc += char(int(text[i]+shift-97)%26 +97);
        }
        cout<<"Encrypted cipher: "<<enc<<endl;
}

int main()
{
	string text;
	int shift;
	cout<<"Enter Text: ";
	cin>>text;
	cout<<"Enter shift: ";
	cin>>shift;
	int flag = 0;
	cout<<"Enter 1 for encryption and 0 for decryption: ";
	cin>>flag;
	if(flag)
	cipher_text(text, shift);
	else
	cipher_text(text, 26-shift);
	return 0;
}
