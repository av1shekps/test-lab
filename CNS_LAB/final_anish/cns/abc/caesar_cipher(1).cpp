#include<bits/stdc++.h>
using namespace std;
int main()
{
   string s,et="";
   cout<<"Enter input: "<<endl; 
   cin>>s;
   int k;
   cout<<"Enter shift key: "<<endl;
   cin>>k;
   for(int i=0;i<s.size();i++)
   {
      if(isupper(s[i]))
      et=et+char((s[i]-'A'+k)%26+'A');
      else
      et=et+char((s[i]-'a'+k)%26+'a');
   }
   cout<<"Cipher text: "<<et<<endl;
}
