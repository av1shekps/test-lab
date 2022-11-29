#include<bits/stdc++.h>
using namespace std;

int main()
{
   string s;
   string ct="";
   
   cout<<"------------------------------------------------------"<<endl;
   cout<<"Enter input text : "; 
   cin>>s;
   
   int k;
   cout<<"Enter shift key : ";
   cin>>k;
   
   for(int i=0;i<s.size();i++)
   {
      if(isupper(s[i]))
      {
      	ct=ct+char((s[i]-'A'+k)%26+'A');
      }
      else
      {
      	ct=ct+char((s[i]-'a'+k)%26+'a');
      }
   }
   
   cout<<"Cipher text : "<<ct<<endl;
   cout<<"------------------------------------------------------"<<endl;
}
