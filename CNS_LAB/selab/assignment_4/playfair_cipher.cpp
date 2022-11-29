#include<bits/stdc++.h>
using namespace std;

int main()
{
   string s,c,o;
   
   cout<<"----------------------------------------------------"<<endl;
   cout<<"Enter input text : ";
   cin>>s;
   
   transform(s.begin(), s.end(), s.begin(), ::toupper);
   
   cout<<endl;
   
   cout<<"Enter cipher key : ";
   cin>>c;
   
   transform(c.begin(), c.end(), c.begin(), ::toupper);
   
   int cnt[26];
   
   for(int i=0;i<26;i++)
   {
   	cnt[i]=0;
   }
   
   //5x5 matrix of cipher key
   char ch[5][5];
   
   //leaving alphabet J
   cnt['J'-'A']=1;
   
   int n=s.length();
   
   //replacing J with I
   for(int i=0;i<n;i++)
   { 
   	if(s[i]=='J')
   	{
   		s[i]='I';
   	}
   }
   
   int k=c.length();
   int t=0,curr=0;
   
   cout<<endl;
   
   // printing playfair matrix wrt cipher text
   cout<<"Playfair Matrix"<<endl;
   cout<<endl;
   
   for(int i=0;i<5;i++)
   {
      for(int j=0;j<5;j++)
      {
         if(k>0)
         {
            while(cnt[c[t]-'A']!=0)
            {
            	t++;
            }
            
            cnt[c[t]-'A']++;
            ch[i][j]=c[t++];
            k--;
         }
         else
         {
            while(cnt[curr]!=0)
            {
            	curr++;
            }
            
            ch[i][j]=char(curr+'A');
            curr++;
         }
         cout<<ch[i][j]<<" ";
       }
       cout<<endl;
    }
    
    cout<<endl;
    
    // if length is odd add bogus character 'X'   
    if(n%2!=0)
    {
    	s=s+'X';
    	n++;
    }
    
      
    for(int i=0;i<n;i+=2)
    {
        int p1=-1,p2=-1,q1=-1,q2=-1;
        int flag1=0,flag2=0;
        
        // groups of 2 characters
        char c1=s[i];
        char c2=s[i+1];  
        
        // saving the coordinates
        for(int j=0;j<5;j++)
        {
           for(int k=0;k<5;k++)
           {
              if(ch[j][k]==c1)
              {
                 p1=j;p2=k;
                 flag1=1;
              }
              if(ch[j][k]==c2)
              {
                 q1=j;q2=k;
                 flag2=1;
              }
              
              if(flag1==1 && flag2==1)
              break;
            
           }
            
            if(flag1==1 && flag2==1)
            break;
        }
        
        // once both the characters are found
        
        // now checking for the 3 rules
        
        //rule1 - if in same column
        if(p1==q1)
        {
           s[i]=ch[p1][(p2+1)%5];
           s[i+1]=ch[q1][(q2+1)%5];
        }
        //rule2 - if in same row
        else if(p2==q2)
        {
           s[i]=ch[(p1+1)%5][p2];
           s[i+1]=ch[(q1+1)%5][q2];
        }
        //rule3 - opposite corners
        else
        {
            s[i]=ch[p1][q2];
            s[i+1]=ch[q1][p2];
        }
     }
     
     cout<<"Cipher text : "<<s<<endl;
     cout<<"------------------------------------------------------"<<endl;
} 
                
