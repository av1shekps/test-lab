#include<stdio.h>
#include<gmp.h>


typedef mpz_t mi;

void gcd(mi a, mi b )//mi res)
{
	mi temp;
	mpz_init_set_ui(temp,0);
	if(mpz_cmp(b , temp)==0)
	{
		gmp_printf("GCD is: %Zd\n", a);
		return;
	}
	else
	{
		mpz_mod(temp,a,b);
		gcd(b,temp);
	}
}

int main()
{
	mpz_t a,b,res;
	mpz_init(a);
	mpz_init(b);
	
	//mpz_innit(res);
	/*gmp_randstate_t state;
	gmp_randinit_default(state);
    gmp_randseed_ui(state, time (0));
    */
    
    gmp_scanf("%Zd %Zd",a,b);
	gmp_printf("Integer a: %Zd \n", a);
	gmp_printf("Integer b: %Zd \n", b);
    
	
    gcd(a,b);
    
}
