#include <gmp.h>
#include <stdio.h>
#include <time.h>

void gcd(mpz_t a, mpz_t b)
{
	if(mpz_cmp_d(b, 0) == 0)
	{
		gmp_printf("GCD using Euclid:%Zd\n", a);
		return ;
	}
	else
	{
		mpz_t temp;
		mpz_init(temp);
		mpz_mod(temp, a, b);
		gcd(b, temp);
	}
}
void main()
{
	mpz_t a, b;
	gmp_randstate_t state;
	gmp_randinit_default(state);
    	gmp_randseed_ui(state, time (0));

	mpz_init(a);
	mpz_init(b);
	mpz_urandomb(a, state, 32);
	mpz_urandomb(b, state, 32);
	gmp_printf("Values of a = %Zd and b = %Zd\n", a, b);
	//gmp_scanf("%Zd%Zd", a, b);
	gcd(a, b);
	mpz_t mgcd;
	mpz_init(mgcd);
	mpz_gcd(mgcd, a, b);
	gmp_printf("GCD from function:%Zd\n", mgcd);
}
