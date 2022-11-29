/*#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	if(b == 0)
	return a;
	else
	return (b, a % b);
}

int generate_key(int q)
{
	int key = pow(10, 17) + ((int)rand() % (q - pow(10, 17) + 1));
        
        while(gcd(q, key) != 1)
        key = pow(10, 17) + ((int)rand() % (q - pow(10, 17) + 1));
 
    	return key;
}

int modex(int a, int b, int c)
{
	int x = 1, y = a;
	
	while(b > 0)
	{
		if(b % 2 != 0)
		x = (x*y) % c;
		y = (y*y) % c;
		b = b/2;
	}
	return x % c;
}

string encrypt(string msg, int q, int h, int g)
{
	string ans;
	int k = generate_key(q);
	int s = modex(h, k, q);
	int p = modex(g, k, q);
	

	for(int i = 0;i < msg.size();i++)
	ans += msg[i];
	
	for(int i = 0;i < msg.size();i++)
	ans[i] = (char)(s * (int)ans[i]);
	
	return ans;
	
}
string getCipher(string s)
{
	srand((unsigned) time(NULL)); 
	double q = pow(10,6) + ((double)rand() % (pow(10, 17) - pow(10, 6) + 1));
	double g = 2 + ((double)rand() % (q-1));
	
	int key = generate_key(q);
	int h = modex(g, key, q);
	
	return encrypt(s, q, h, g);
	
}

int main()
{
	 string msg;
	 cout<<"Enter message for encryption: ";
	 cin>>msg;
	 cout<<"After encryption: "<<getCipher(msg)<<endl;
	 return 0;
}
*/

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

int main()
{

int n;
int choice;

n=64;

getchar();

mpz_t g;
mpz_init(g);

mpz_t p;
mpz_init(p);

mpz_t x;
mpz_init(x);

mpz_t y;
mpz_init(y);

mpz_t k;
mpz_init(k);

mpz_t c1;
mpz_init(c1);

gmp_randstate_t state;
gmp_randinit_default(state);


//~~~~~~~~~~~~~~~~~~~~~~Key Generation~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//


 mpz_urandomb(p,state,n); //Random number n bit
 mpz_nextprime(p,p); //Make it prime number


 mpz_urandomb(g,state,n); //Random number n bit



 while( mpz_cmp(p,g)<0) //Ensure that p is greater than g
 {
     mpz_urandomb(g,state,n);
 }


 gmp_printf("\nThe value of p is %Zd \n",p);
 gmp_printf("The value of g is %Zd \n",g);


mpz_urandomb(x,state,n);

 while( mpz_cmp(g,x)<0 )
 {
     mpz_urandomb(x,state,n);

 }

 gmp_printf("The value of x is %Zd \n",x);


 mpz_powm(y,g,x,p);

 gmp_printf("The value of y is %Zd \n",y);


 //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Encryption~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	char temp;
	char message[50];
	int count = 0;

    printf("\nGive message: ");

    fgets(message, sizeof(message), stdin);

    while(message[count]!='\n') 
    {
        count++;
    }

    mpz_urandomb(k,state,n);

    while( mpz_cmp(p,k)<0 ) //Ensure that p is greater than k
    {
     mpz_urandomb(k,state,n);

    }

    gmp_printf("\nThe value of k is %Zd \n",k);

    mpz_powm(c1,g,k,p); //Calculate C1

    gmp_printf("\n\nThe value of C1 is %Zd \n",c1);

    int i;
    mpz_t c2[count];

    for (i = 0; i < count; i++) {
        mpz_init2(c2[i], n);
    }

    mpz_t temp2;
    mpz_init(temp2);

    mpz_t temp3;
    mpz_init(temp3);

    mpz_powm(temp2,y,k,p); 

    gmp_printf("\n\ntemp2 = (y^k)mod p :%Zd \n",temp2);


    for(i=0; i<count; i++)
    {
        mpz_mul_si(c2[i],temp2,message[i]);
        gmp_printf("C2[%d] = %Zd\n",i,c2[i]);
    }

	mpz_clear(temp2);
	mpz_clear(temp3);
	mpz_clear(k);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Decryption~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

    mpz_t temp4;
    mpz_init(temp4);

    mpz_t temp5;
    mpz_init(temp5);

    mpz_t temp6;
    mpz_init(temp6);

    mpz_t temp7;
    mpz_init(temp7);

    int result;

    mpz_set_si(temp7,1);

    printf("\nDecrypted: ");

    for(i=0; i<count; i++)
    {
        mpz_powm(temp5,c1,x,p);
        mpz_cdiv_q(temp6,c2[i],temp5);
        result = mpz_get_ui (temp6);
        gmp_printf("%c",result);
    }
    printf("\n");
    mpz_clear(temp4);
	mpz_clear(temp5);
	mpz_clear(temp6);
	mpz_clear(temp7);;

    for (i = 0; i < count; i++) {
    mpz_clear(c2[i]);
    }
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
}

