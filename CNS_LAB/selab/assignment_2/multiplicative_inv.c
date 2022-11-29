#include<gmp.h>
#include <stdio.h>

int main() {

	mpz_t a,i;
	mpz_init(i);
	mpz_inits(a,NULL);
	gmp_scanf("%Zd",a);
	
	gmp_printf("Number is %Zd\n",a);
	
	mpz_t k;
	mpz_init_set_ui(k,1);
	while(mpz_get_ui(k)<=a)
	{
	    mpz_t q1,q2;
	    mpz_mul(
	}
        
        
        

		
}
