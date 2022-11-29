#include<gmp.h>
#include <stdio.h>

int main() {

	mpz_t a,b,r;
	
        mpz_inits(a,b,NULL);
        gmp_scanf("%Zd %Zd",a,b);
        
        
        if(mpz_cmp(a,b)<0)
        {
            mpz_swap(a,b);
        }
        
        gmp_printf("Numbers are %Zd , %Zd\n",a,b);
        
	while(mpz_get_ui(b) != 0)
	{
	     mpz_mod(r,a,b);
	     mpz_set(a,b);
	     mpz_set(b,r);
	}

	gmp_printf("GCD is %Zd\n",a);
		
}
