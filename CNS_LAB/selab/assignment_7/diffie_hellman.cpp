#include<stdio.h>
#include<math.h>

typedef long long ll;

ll power(ll a, ll b,ll P)
{
	if (b == 1)
	{
	return a;
	}
	else
        {
        return (((ll )pow(a, b)) % P);
	}
}

int main()
{
	ll P, G, x, a, y, b, ka, kb;
	
	
	printf("Enter value of P : ");
	cin>>P; 

	cout<<endl;
	
	printf("Enter value of G : ");
	cin>>G;

	cout<<endl;
	
	printf("Enter value of a : ");
	cin>>a;
	
	cout<<endl;
	
	printf("The private key a for Alice : %lld\n", a);
	x = power(G, a, P); 
	
	b = 3; 
	printf("The private key b for Bob : %lld\n\n", b);
	y = power(G, b, P); 

	// Generating the secret key after the exchange of keys
	ka = power(y, a, P);
	kb = power(x, b, P); 
	
	printf("Secret key for the P1 is : %lld\n", ka);
	printf("Secret Key for the P2 is : %lld\n", kb);
	
	return 0;
}

