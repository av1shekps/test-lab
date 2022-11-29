#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<gmp.h>
#include<time.h>
void generate_nbit_primenumber(mpz_t a,int n,int p)
{
	mpz_t l,b;
	mpz_inits(l,b,NULL);
	gmp_randstate_t state;
	gmp_randinit_mt(state);
	unsigned int seed;
	seed = time(NULL)+p;
	gmp_randseed_ui(state,seed);
	mpz_rrandomb(a,state,n);
	mpz_nextprime(a,a);
	mpz_set_ui(l,mpz_sizeinbase(a,2));
	while(mpz_cmp_ui(l,n)!=0)
	{
		mpz_rrandomb(a,state,n);
		mpz_nextprime(a,a);
		mpz_set_ui(l,mpz_sizeinbase(a,2));
	}
}
void generating_p_and_generator(mpz_t p,mpz_t a)
{
	mpz_t x,y,z,t1,t2,t3,q,r,l,phi;
	mpz_inits(x,y,z,t1,t2,t3,q,r,l,phi,NULL);
	gmp_randstate_t state;
	gmp_randinit_mt(state);
	unsigned int seed;
	seed = time(NULL);
	gmp_randseed_ui(state,seed);
	mpz_set_ui(q,2);
	srand(time(0));
	int pseed=0;
	do
	{
		int num=1023;
		generate_nbit_primenumber(r,num,pseed++);
		mpz_mul(phi,q,r);
		mpz_add_ui(p,phi,1);
		mpz_set_ui(l,mpz_sizeinbase(p,2));
	}while(mpz_cmp_ui(l,1024)!=0 || mpz_probab_prime_p(p,50)==0);
	mpz_sub_ui(t1,p,3);
	while(1)
	{
		mpz_urandomm(a,state,t1);
		mpz_add_ui(a,a,2);
		mpz_powm(t2,a,q,p);
		mpz_powm(t3,a,r,p);
		if(mpz_cmp_ui(t2,1)!=0&&mpz_cmp_ui(t3,1)!=0)
			break;
	}
}
int main()
{
	mpz_t p,pt,p1,g,q,r,k,x,y,z,c1,c2,t1;
	mpz_inits(pt,p,p1,q,r,k,g,x,y,z,c1,c2,t1,NULL);
	gmp_printf("Enter the Plain text : ");
	gmp_scanf("%Zd",pt);
	gmp_printf("\nEncrypting the message\n");
	generating_p_and_generator(p,g);
	mpz_sub_ui(p1,p,4);
	gmp_randstate_t state;
	gmp_randinit_mt(state);
	unsigned int seed;
	seed = time(NULL);
	gmp_randseed_ui(state,seed);
	mpz_urandomm(x,state,p1); // x is the private key
	mpz_add_ui(x,x,2);
	mpz_powm(y,g,x,p); // y is the public key
	mpz_urandomm(k,state,p);
	mpz_powm(c1,g,k,p);
	mpz_powm(c2,y,k,p);
	mpz_mul(c2,c2,pt);
	mpz_mod(c2,c2,p);
	gmp_printf("\nCipher Text after encryption : ( %Zd , %Zd )\n",c1,c2);
	mpz_powm(t1,c1,x,p);
	mpz_invert(t1,t1,p);
	mpz_mul(z,c2,t1);
	mpz_mod(z,z,p);
	gmp_printf("\nPlain Text after decryption : %Zd\n",z);
	return 0;
}
