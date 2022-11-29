#include<bits/stdc++.h>
using namespace std;


vector<int> get(string key)
{
   int n=key.size();
   
   vector<int> order(n);
   
   vector<pair<char,int>> p;
   
   for(int i=0;i<n;i++)
   {
   	p.push_back({key[i],i});
   	sort(p.begin(),p.end());
   }
   
   for(int i=0;i<n;i++)
   {
   	order[p[i].second]=i+1;
   }
   
   return order;
   
}   

int main()

{

  cout<<"-----------------------------------------------------------------"<<endl;
  
  string s,key;
  
  cout<<"Enter Input Text : ";
  getline(cin,s);
  
  cout<<endl;
  
  cout<<"Enter Cipher Key : ";
  cin>>key;
  
  cout<<endl;
  
  int sz = s.size();
  
  // No. of columns will be equal to size of key
  int m = key.size();
  // No. of rows is calculated based on size of text and key 
  int n = (sz+m-1)/m;
  
  // to get the permutation order of cipher key
  vector<int> permute=get(key);
  
  // nxm matrix 
  vector<vector<char>> mat(n,vector<char>(m));
  
  int cnt=0;
  
  // to fill the cipher matrix
  cout<<endl;
  
  cout<<"Matrix generated"<<endl;
  
  for(int i=0;i<n;i++)
  {
     for(int j=0;j<m;j++)
     {
        if(cnt>=sz)
        {
        	mat[i][j]='_';
        }
        else
        {
        	mat[i][j]=s[cnt++];
        }
        
        cout<<mat[i][j]<<" ";
     }
     cout<<endl;
  }
  
  cout<<endl;
  
  string ans="";
  
  // to read the matrix in encrypted form
  for(int i=0;i<m;i++)
  {   
     for(int j=0;j<n;j++)
     {
        ans+=mat[j][permute[i]-1];
     }
  }
  
  cout<<"Encrypted Text : "<<ans<<endl;
  
  cout<<"-----------------------------------------------------------------"<<endl;
   
  return 0;
}
     
