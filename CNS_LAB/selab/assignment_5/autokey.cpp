#include<bits/stdc++.h>
using namespace std;
string generateKey(string str, string key)
{
   int len=key.size();
   for(int i=len;i<str.size();i++)
   key.push_back(str[i-len]);
   return key;
}
string cipherText(string str, string key)
{
    string cipher_text;
 
    for (int i = 0; i < str.size(); i++)
        cipher_text+=char((str[i]+key[i])%26+'A');
    return cipher_text;
}
string decryptText(string cipher_text, string key)
{
    string decrypt_text;
 
    for (int i = 0 ; i < cipher_text.size(); i++)
        decrypt_text+=char((cipher_text[i] - key[i] + 26) %26+'A');
         
    return decrypt_text;
}

int main()
{

    cout<<"-----------------------------------------------------------------"<<endl;	
   
    cout<<"Enter input string"<<endl;
    string str;
    cin>>str;
    
    cout<<"Enter encryption key"<<endl;
    string key;
    cin>>key;
    
    key = generateKey(str, key);
    string cipher_text = cipherText(str, key);
    
    
    cout << "Ciphertext : " << cipher_text << "\n";
 
    cout << "Decrypted Text : " << decryptText(cipher_text, key)<<"\n";
    
    
    cout<<"-----------------------------------------------------------------"<<endl;	
    
    return 0;
}
