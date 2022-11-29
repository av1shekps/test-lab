#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter input string"<<endl;
    string str;
    cin>>str;
    int len=str.size();
    cout<<"Enter encryption key of length: "<<len<<endl;
    string key;
    cin>>key;
    string cipher_text;
    for (int i = 0; i < str.size(); i++)
        cipher_text+=char((str[i]+key[i])%26+'A');
    cout << "Ciphertext : "<< cipher_text << "\n";
    return 0;
}
