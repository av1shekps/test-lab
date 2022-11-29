#include<iostream>
#include<bits/stdc++.h>
#include<gmp.h>

using namespace std;
typedef mpz_t mi;

int main()
{
	string str;
	int i;
	int flag=0;
	mpz_t cipher[100];
	
	for(i=0;i<99;i++)
		mpz_init(cipher[i]);

	mi p,q,x,p1,q1,phi,e,t1,d,msg,cip,n,t2;
	mpz_inits(p,q,x,p1,q1,phi,e,t1,d,msg,cip,n,t2,NULL);
	
	gmp_randstate_t s;
	gmp_randinit_mt(s);
	unsigned long seed;
	seed=time(NULL);
	gmp_randseed_ui(s,seed);
	mpz_set_ui(x,100000000000);
	mpz_urandomm(p,s,x);
	mpz_urandomm(q,s,x);

	mpz_nextprime(p,p);
	mpz_nextprime(q,q);

	//mpz_set_ui(p,11);
	//mpz_set_ui(q,7);
	cout<<"p: "<<p<<"\t q: "<<q<<endl;
	
	mpz_mul(n,p,q);
	
	cout<<"n: "<<n<<endl;
	mpz_sub_ui(p,p,1);
	mpz_sub_ui(q,q,1);
	mpz_mul(phi,p,q);
	//gmp_printf("%Zd  %Zd\n",p,q);

	while(!flag)
	{
		mpz_urandomm(e,s,phi);	
		mpz_gcd(t1,e,phi);
		
		if(mpz_cmp_ui(t1,1)==0)
		{	flag=1;
			break;
		}
	}
	
	mpz_invert(d,e,phi);
	cout<<"Public Key e:"<<e<< "\nn:"<<n<<endl;
	cout<<"Private Key d: "<<d<<endl;
	printf("Enter the message : ");
	
	getline(cin,str);
	cout<<"Cipher text : ";
	for(i=0;i<str.size();i++)
	{
	
		int MSG=(int)str[i];
		
		mpz_add_ui(msg,t2,MSG);
		mpz_powm(cip,msg,e,n);
		mpz_set(cipher[i],cip);
		//gmp_printf("ASCII text : %Zd\n",msg);
		cout<<cip;
	}

		printf("\nMessage text : ");
		for(i=0;i<str.size();i++)
		{
			mpz_powm(msg,cipher[i],d,n);
			int car=mpz_get_ui(msg);
			cout<<car;
		}
		printf("\n");
}
