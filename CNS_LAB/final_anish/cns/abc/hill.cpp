#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> generateMatrix(string key,int n)
{
   vector<vector<int>> keyMatrix(n,vector<int>(n));
   int k=0;
   for(int i=0;i<n;i++)
   { 
      for(int j=0;j<n;j++)
      {
         keyMatrix[i][j]=key[k]-'A';
         k++;
      }
   }
   return keyMatrix;
}
string hillCipher(string s,vector<vector<int>> km,int n)
{
    string cipher_text="";
    vector<vector<int>> im(n,vector<int>(1));
    vector<vector<int>> cm(n,vector<int>(1,0));
    for(int i=0;i<n;i++)
    im[i][0]=s[i]-'A';
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<n;j++)
          cm[i][0]+=km[i][j]*im[j][0];
      cm[i][0]=cm[i][0]%26;
    }
    for(int i=0;i<n;i++)
      cipher_text+=char(cm[i][0]+'A');
    return cipher_text;
}
int main()
{
   cout<<"Enter input String"<<endl;
   string s;
   cin>>s;
   int n=s.size();
   cout<<"Enter key of length: "<<(n*n)<<endl;
   string key;
   cin>>key;
   vector<vector<int>> km=generateMatrix(key,n);
   string cipher_text=hillCipher(s,km,n);
   cout<<"Cipher Text: "<<cipher_text<<endl;
   return 0;
}
