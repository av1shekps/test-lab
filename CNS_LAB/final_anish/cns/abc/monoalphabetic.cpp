#include<iostream>
using namespace std;

int main()
{
  cout << "Enter plain text - ";
  string plain_text; getline(cin, plain_text);
  
  const string key = "QWERTYUIOPASDFGHJKLZXCVBNM";
  string cipher_text = "";
  for(auto ch : plain_text)
  {
    if(ch == ' ') {
     cipher_text += ' ';
     continue;
    }
    int n;
    if( (ch >= 'a') && (ch <= 'z') ) n = ch - 'a';
    else n = ch - 'A';
    
    cipher_text += key[n];
  }
  
  cout << "Cipher Text is - " << cipher_text << endl;
  return 0;
}
