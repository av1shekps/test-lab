#include <gmp.h>
#include <stdio.h>
#include <time.h>

void gcd(mpz_t a, mpz_t b, mpz_t x, mpz_t y)
{
	if(mpz_cmp_d(b, 0) == 0)
	{
		gmp_printf("GCD using Euclid:%Zd\n", a);
		mpz_t x, y;
		mpz_set_ui(x, 1);
		mpz_set_ui(y, 0);
		return ;
	}
	else
	{
		mpz_t temp, q, mul, x1, y1;
		mpz_init(temp);
		mpz_init(q);
		mpz_init(mul);
		mpz_init(x1);
		mpz_init(y1);
		mpz_mod(temp, a, b);
		gcd(b, temp, x1, y1);
		mpz_cdiv_q(q, b, a);
		mpz_mul(mul, q, x1);
		mpz_t tx;
		mpz_init(tx);
		mpz_sub(tx, y1, mul);
		mpz_set(x, tx);
		mpz_set(y, x1);
	}
}
void main()
{
	mpz_t a, b, x, y;
	gmp_randstate_t state;
	gmp_randinit_default(state);
    	gmp_randseed_ui(state, time (0));

	mpz_init(a);
	mpz_init(b);
	mpz_init(x);
	mpz_init(y);
	
	mpz_init_set_ui(x, 0);
	mpz_init_set_ui(y, 0);
	mpz_urandomb(a, state, 32);
	mpz_urandomb(b, state, 32);
	gmp_printf("Values of a = %Zd and b = %Zd\n", a, b);
	
	gcd(a, b, x, y);
}
