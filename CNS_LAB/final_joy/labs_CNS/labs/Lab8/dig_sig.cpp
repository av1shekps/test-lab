#include<bits/stdc++.h>
#include <algorithm>
#include<numeric>
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
	int q=19, alpha=10;
	int Xa=5;
	
	int Ya=fex(alpha,Xa,q);
	cout<<"Public key: ("<<q<<","<<alpha<<","<<Ya<<")\nPrivate key is: "<<Xa<<endl;
	cout<<"Enter a Message (M hashed and is int): ";
	int M;
	cin>>M;
	int k;
	for(int i=2;i<q;i++)
	{
		if(__gcd(i,q-1)==1)
		{
			k=i;
			break;
		}
	}
	cout<<"k: "<<k<<endl;
	int S1=fex(alpha,k,q);
	
	int k_inv;
	for(int i=0;i<q-1;i++)
	{
		if((k*i)%(q-1)==1)
		{	k_inv=i; break;}		
	}
	
	cout<<"k_inv: "<<k_inv<<endl;
	int S2=(k_inv*(M-(Xa*S1)))%(q-1);
	if(S2<0)
		S2=(q-1)+S2;
	cout<<"S1: "<<S1<<"\nS2: "<<S2<<endl;
	//Verification
	
	int V1=fex(alpha,M,q);
	//cout<<fex(S1,S2,q)<<endl;
	int V2=(fex(Ya,S1,q)*fex(S1,S2,q))%q;
	
	cout<<"V1: "<<V1<<"\nV2: "<<V2<<endl;
}
