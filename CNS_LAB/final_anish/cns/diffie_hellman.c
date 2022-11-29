#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<gmp.h>
#include<time.h>
void generate_nbit_primenumber(mpz_t a,int n)
{
	mpz_t l,b;
	mpz_inits(l,b,NULL);
	gmp_randstate_t state;
	gmp_randinit_mt(state);
	unsigned int seed;
	seed = time(NULL);
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
	srand(time(0));
	do
	{
		int num=(rand()%(1023))+2;
		generate_nbit_primenumber(q,num);
		num=1024-num;
		generate_nbit_primenumber(r,num);
		mpz_mul(phi,q,r);
		mpz_add_ui(p,phi,1);
		mpz_set_ui(l,mpz_sizeinbase(p,2));
	}while(mpz_cmp_ui(l,1024)!=0);
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
	mpz_t a,b,c,d,q,t1,xa,xb,ya,yb,ka,kb;
	mpz_inits(a,b,c,d,q,t1,xa,xb,ya,yb,ka,kb,NULL);
	gmp_randstate_t state;
	gmp_randinit_mt(state);
	unsigned int seed;
	seed = time(NULL);
	gmp_randseed_ui(state,seed);
	generating_p_and_generator(q,a);
	mpz_sub_ui(t1,q,2);
	mpz_urandomm(xa,state,t1);
	mpz_add_ui(xa,xa,2);
	mpz_powm(ya,a,xa,q);
	mpz_urandomm(xb,state,t1);
	mpz_add_ui(xb,xb,2);
	mpz_powm(yb,a,xb,q);
	mpz_powm(ka,yb,xa,q);
	mpz_powm(kb,ya,xb,q);
	gmp_printf("\nKey with User a : %Zd\n",ka);
	gmp_printf("\nKey with User b : %Zd\n",kb);
	if(mpz_cmp(ka,kb)==0)
		gmp_printf("\nThe Keys are same\n\n");
	else
		gmp_printf("\nThe Keys are different\n\n");
	return 0;
}
