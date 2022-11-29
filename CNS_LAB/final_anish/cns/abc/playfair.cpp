#include<bits/stdc++.h>
using namespace std;
int main()
{
   string s,c,o;
   cout<<"Enter input string: "<<endl;
   cin>>s;
   cout<<"Enter cipher key: "<<endl;
   cin>>c;
   char ch[5][5];
   int cnt[26];
   for(int i=0;i<26;i++)
   cnt[i]=0;
   cnt['J'-'A']=1;
   int n=s.length();
   for(int i=0;i<n;i++)
   { 
     if(s[i]=='J')
     s[i]='I';
   }
   int k=c.length();
   int t=0,curr=0;
   for(int i=0;i<5;i++)
   {
      for(int j=0;j<5;j++)
      {
         if(k>0)
         {
            while(cnt[c[t]-'A']!=0)
            t++;
            cnt[c[t]-'A']++;
            ch[i][j]=c[t++];
            k--;
         }
         else{
            while(cnt[curr]!=0)
            curr++;
            ch[i][j]=char(curr+'A');
            curr++;
         }
         cout<<ch[i][j]<<" ";
       }
       cout<<endl;
    }
    if(n%2!=0){
    s=s+'X';
    n++;
    }
    for(int i=0;i<n;i+=2)
    {
        int p1=-1,p2=-1,q1=-1,q2=-1,f1=0,f2=0;
        char a=s[i];
        char b=s[i+1];  
        for(int j=0;j<5;j++)
        {
           for(int k=0;k<5;k++)
           {
              if(ch[j][k]==a)
              {
                 p1=j;
                 p2=k;
                 f1=1;
              }
              if(ch[j][k]==b)
              {
                 q1=j;
                 q2=k;
                 f2=1;
              }
              if(f1&&f2)
              break;
            }
            if(f1&&f2)
            break;
        }
        if(p1==q1)
        {
           s[i]=ch[p1][(p2+1)%5];
           s[i+1]=ch[q1][(q2+1)%5];
        }
        else if(p2==q2)
        {
           s[i]=ch[(p1+1)%5][p2];
           s[i+1]=ch[(q1+1)%5][q2];
        }
        else
        {
            s[i]=ch[p1][q2];
            s[i+1]=ch[q1][p2];
        }
     }
     cout<<"Encrypt: "<<s<<endl;
} 
                
  
