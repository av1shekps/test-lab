#include<bits/stdc++.h>
using namespace std;
vector<int> generatePermutation(string key)
{
   int n=key.size();
   vector<int> permute(n);
   vector<pair<char,int>> p;
   for(int i=0;i<n;i++)
   p.push_back({key[i],i});
   sort(p.begin(),p.end());
   for(int i=0;i<n;i++)
   permute[p[i].second]=i+1;
   return permute;
   
}   
int main()
{
  cout<<"Enter Input String"<<endl;
  string s;
  cin>>s;
  int len=s.size();
  cout<<"Enter cipher key"<<endl;
  string key;
  cin>>key;
  int m=key.size();
  int n=(len+m-1)/m;
  vector<int> permute=generatePermutation(key);
  
  vector<vector<char>> cm(n,vector<char>(m));
  cout<<m<<n<<endl;
  int k=0;
  for(int i=0;i<n;i++)
  {
     for(int j=0;j<m;j++)
     {
        if(k>=len)
         cm[i][j]='_';
        else
        cm[i][j]=s[k++];
        cout<<cm[i][j]<<" ";
     }
     cout<<endl;
  }
  string cipher_text="";
  for(int i=0;i<m;i++)
  {
     cout<<permute[i]<<endl;
     for(int j=0;j<n;j++)
        cipher_text+=cm[j][permute[i]-1];
  }
  cout<<"Cipher_Text: "<<cipher_text<<endl;
  return 0;
}
     
