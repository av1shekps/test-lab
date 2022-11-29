#include <gmp.h>
#include <stdio.h>
#include <time.h>

void rabinMiller(mpz_t d, mpz_t num, int res)
{
	gmp_randstate_t state;
	gmp_randinit_default(state);
    	gmp_randseed_ui(state, time (0));
    	mpz_t r;
    	mpz_init(r);
    	mpz_urandomb(r, state, 16);
    	mpz_t m;
    	mpz_init(m);
    	mpz_mod(m, r, num-4);
    	mpz_t a;
    	mpz_init(a);
    	mpz_add_ui(a, m, 2);
    	mpz_t x;
    	mpz_init(x);
    	mpz_powm(x, a, d, num);
    	if(mpz_cmp_d(x, 1) == 0 || mpz_cmp(x, num - 1) == 0)
    	{
    		res = 1;
    		return ;
    	}
    	while(mpz_cmp(d, num-1) != 0)
    	{
    		mpz_mul(x, x, x);
    		mpz_mod(x, x, num);
    		mpz_mul_ui(d, d, 2);
    		
    		if(mpz_cmp_d(x, 1) == 0)
    		{
    			res = 0;
    			return ;
    		}
    		if(mpz_cmp(x, num - 1) == 0)
    		{
    			res = 1;
    			return ;
    		}
    		
    	}
    	res = 0;
    	return ;
}

void checkPrime(mpz_t num, mpz_t itr)
{
	if(mpz_cmp_d(num, 1) == 0 || mpz_cmp_d(num, 4) == 0)
	return ;
	if(mpz_cmp_d(num, 2) == 0 || mpz_cmp_d(num, 3) == 0)
	gmp_printf("%Zd ", num);
	
	mpz_t d;
	mpz_init_set(d, num - 1);
	mpz_t m;
	mpz_init(m);
	mpz_mod_ui(m, d, 2);
	while(mpz_cmp(m, 0) == 0)
	{
		mpz_cdiv_q_ui(d, d, 2);
		mpz_mod_ui(m, d, 2);
	}
	mpz_t itrs;
	mpz_init_set(itrs, 0);
	int res = 0;
	while(mpz_cmp(itrs, itr) != 0)
	{
		rabinMiller(d, num, res);
		if(res == 0)
		return ;
	}
	gmp_printf("%Zd ", num);
}
void main()
{
	mpz_t itr, range;
	mpz_init(itr);
	mpz_init(range);
	
	gmp_printf("Enter number of iterations and range: \n");
	gmp_scanf("%Zd%Zd", &itr, &range);
	mpz_t ind;
	mpz_init_set_ui(ind, 1);
	while(mpz_cmp(ind, range) != 0)
	{
	gmp_printf("%Zd\n", ind);
		checkPrime(ind, itr);
		mpz_add_ui(ind, ind, 1);
	}
}
