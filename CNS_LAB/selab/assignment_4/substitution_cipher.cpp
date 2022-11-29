#include<bits/stdc++.h>
using namespace std;

string encrypt, decrypt;

int main()
{
	cout<<"----------------------------------------------------"<<endl;
	
	// mapping used for encryption and decryption    
	encrypt = "defghijklmnopqrstuvwxyzabc";
	
	//int range = 1000 - 1 + 1;
	//int num = rand() % range + 1;
	
	//cout<<num<<endl;
	//while(num--)
	//{
	//next_permutation(encrypt.begin(), encrypt.end());
	//}
	
	cout<<encrypt<<endl;
	
	string s;
	
	for(int i=0;i<26;i++)
	{
		decrypt[encrypt[i]-'a']='a'+i;
	}
	
	cout<<"Enter input text for encryption : ";
	cin>>s;
	cout<<endl;
		
	string ans;
	
	for(int i=0;i<s.size();i++)
	{
		int id = s[i]-'a';
		ans.push_back(encrypt[id]);
	}
	
	cout<<"The encrypted string is : "<<ans<<endl;
	cout<<endl;
	
	//cout<<"Enter input text for decryption : ";
	//cin>>s;
	//cout<<endl;
	
	/*string dec;
	
	for(int i=0;i<s.size();i++)
	{
		int id = s[i]-'a';
		dec.push_back(decrypt[id]);
	}
	
	cout<<"The decrypted string is : "<<dec<<endl;
	*/cout<<"----------------------------------------------------"<<endl;
	
	return 0;
}
