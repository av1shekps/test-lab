#include<stdio.h>
#include<stdlib.h>
#include<gmp.h>
#include<time.h>
int main()
{
	mpz_t a,p,temp1,temp2,temp3,temp4;
	mpz_inits(a,p,temp1,temp2,temp3,temp4,NULL);
	gmp_printf("\nEnter the Number : ");
	gmp_scanf("%Zd",p);
	gmp_randstate_t state;
	gmp_randinit_mt(state);
	unsigned long seed;
	seed = time(NULL);
	gmp_randseed_ui(state,1000);
	mpz_sub_ui(temp1,p,4);
	for(int i=0;i<1000;i++)		// applying theorem by generating 1000 random numbers
	{
		if(mpz_cmp_ui(temp1,0)==0)
			mpz_set_ui(temp1,2);
		else
			mpz_urandomm(a,state,temp1);
		mpz_add_ui(a,a,2);
		mpz_gcd(temp2,a,p);		// temp2 contains the gcd of a and p
		if(mpz_cmp_ui(temp2,1)!=0)
		{
			gmp_printf("\n%Zd is Composite Number\n\n",p);
			return 0;
		}
		mpz_sub_ui(temp3,p,1);	// temp3 contains the value of p-1
		mpz_powm(temp4,a,temp3,p);	// temp4 contains the value of a^(p-1)%p
		if(mpz_cmp_ui(temp4,1)!=0)
		{
			gmp_printf("\n%Zd is Composite Number\n\n",p);
			return 0;
		}		
	}
	gmp_printf("\n%Zd may be a prime number\n\n",p);
	return 0;
}
