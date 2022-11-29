#include<gmp.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{
	mpz_t a,x,n,res,t;
	mpz_inits(a,x,n,res,t,NULL);
	gmp_printf("Enter num-");
	gmp_scanf("%Zd",a);
	gmp_printf("Enter pow-");
	gmp_scanf("%Zd",x);
	gmp_printf("Enter mod-");
	gmp_scanf("%Zd",n);
	mpz_set_ui(res,1);
	
	while(mpz_cmp_ui(x,0)!=0)
	{
		mpz_mod_ui(t,x,2);
		
		if(mpz_cmp_ui(t,0)!=0)
		{
			mpz_mul(res,res,a);
			mpz_mod(res,res,n);
		}
		
		mpz_fdiv_q_ui(x,x,2);
		mpz_mul(a,a,a);
		mpz_mod(a,a,n);
	}
	gmp_printf("\na^x mod n = %Zd\n",res);
	return 0;
 }

