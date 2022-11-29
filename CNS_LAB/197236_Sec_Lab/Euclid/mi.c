#include <gmp.h>
#include <stdio.h>
#include <time.h>

void mi(mpz_t n)
{
	mpz_t i;
	mpz_init_set_ui(i, 1);
	while(mpz_cmp(i, n) != 0)
	{
		mpz_t j;
		mpz_init_set_ui(j, 1);
		while(mpz_cmp(j, n) != 0)
		{
			mpz_t prod;
			mpz_init(prod);
			mpz_mul(prod, i, j);
			mpz_t rem;
			mpz_init(rem);
			mpz_mod(rem, prod, n);
			if(mpz_cmp_d(rem, 1) == 0)
			gmp_printf("For %Zd, multiplicative inverse: %Zd\n", i, j);
			mpz_add_ui(j, j, 1);
		}
		mpz_add_ui(i, i, 1);
	}
}
void main()
{
	mpz_t n;

	mpz_init(n);
	gmp_printf("Enter value of n: \n", n);
	gmp_scanf("%Zd", &n);
	mi(n);
}
