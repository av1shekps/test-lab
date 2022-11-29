#include<bits/stdc++.h>
#include<string>

using namespace std;

int fex(int a, int b, int n)//fast expo
{
	int c=0,f=1;
	//int temp=b;
	string temp1 = bitset< 64 >(b).to_string();
	string binary="";
	bool flag=false;
	for(int i=0;i<64;i++)
	{
		if(!flag &&temp1[i]=='1')
			flag=true;
		if(flag)
		{
			binary+=temp1[i];
		}
	
		
	}
	int k=binary.size();
	for(int i=0;i<k;i++)
	{
		f=(f*f)%n;
		if(binary[i]=='1')
		{
			c+=1;
			f=(f*a)%n;
		}
	}
	return f;
}

int main()
{
	int q=107,alpha=2, Xa=67;
	int Ya=fex(alpha,Xa,q);
	//cout<<Ba<<endl;
	cout<<"Public key: ("<<q<<","<<alpha<<","<<Ya<<")\nPrivate key is: "<<Xa<<endl;
	
	cout<<"Enter a random integer:";
	int k;
	cin>>k;
	cout<<"Enter a Message (M is int): ";
	int M;
	cin>>M;
	int K=fex(Ya,k,q);
	int r=fex(alpha,k,q);
	int t=(K*M)%q;
	
	cout<<"Encrypted message (r,t): "<<r<<","<<t<<endl;
	
	cout<<"Decrypted message: ";
	
	int k1=fex(r,Xa,q);
	int k_inv;
	for(int i=1;i<q;i++)
	{
		if((k1*i)%(q)==1)
		{	k_inv=i; break;}
	}
	//k_inv%=10;
	int m=(t*k_inv)%q;
	cout<<m<<endl;
}
