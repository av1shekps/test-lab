#include <bits/stdc++.h>
using namespace std;

string removeSpacesAndConvertToLowerCase(string s)
{
	string res;
	for(char i : s)
	{
		if(i == ' ')
		continue;
		res += i;
	}
	for(int i = 0;i < res.size();i++)
	{
		if(res[i] >= 'A' && res[i] <= 'Z')
		res[i] += 32;
	}
	return res;
}

void generateKeyTable(string key, char keyT[5][5])
{
  	int i, j, k, flag = 0;

  	int dicty[26] = { 0 };
  	for (i = 0; i < key.size(); i++) 
  	{
    		if (key[i] != 'j')
      		dicty[key[i] - 97] = 2;
  	}

  	dicty['j' - 97] = 1;
 	i = 0; j = 0;

  	for (k = 0; k < key.size(); k++) 
  	{	
   		if (dicty[key[k] - 97] == 2) 
   		{
     			dicty[key[k] - 97] -= 1;
     			keyT[i/5][i%5] = key[k];
     			i++;
   		}
  	}	

  	for (k = 0; k < 26; k++) 
  	{
   		if (dicty[k] == 0)
   		{
     			keyT[i/5][i%5] = (char)(k + 97);
     			i++;
   		}
  	}
}


void search(char keyT[5][5], char a, char b, int arr[])
{
	int i, j;

	if (a == 'j') a = 'i';
	else if (b == 'j') b = 'i';

	for (i = 0; i < 5; i++) 
	{
		for (j = 0; j < 5; j++) 
		{
			if (keyT[i][j] == a) 
			{
				arr[0] = i;
				arr[1] = j;
			}
			else if (keyT[i][j] == b) 
			{
				arr[2] = i;
				arr[3] = j;
			}
		}
	}
}

string encrypt(string str, char keyT[5][5])
{
	int i, a[4];
	for (i = 0; i < str.size(); i += 2)
	{
		search(keyT, str[i], str[i + 1], a);

		if (a[0] == a[2]) 
		{
			str[i] = keyT[a[0]][(a[1] + 1)%5];
			str[i + 1] = keyT[a[0]][(a[3] + 1)%5];
		}
		else if (a[1] == a[3]) 
		{
			str[i] = keyT[(a[0] + 1)%5][a[1]];
			str[i + 1] = keyT[(a[2] + 1)%5][a[1]];
		}
		else 
		{
			str[i] = keyT[a[0]][a[3]];
			str[i + 1] = keyT[a[2]][a[1]];
		}
	}
	return str;
}

string encipher_text(string key, string text)
{
	key = removeSpacesAndConvertToLowerCase(key);
	text = removeSpacesAndConvertToLowerCase(key);
	if(text.size() % 2 != 0)
	text += 'z';
	char keyT[5][5];
	generateKeyTable(key, keyT);
	return encrypt(text, keyT);
}

int main()
{
	string key, text;
	cout<<"Enter key and text: ";
	cin>>key>>text;
	string enc = encipher_text(key, text);
	cout<<"Enciphered text: "<<enc<<endl;
	return 0;
}
