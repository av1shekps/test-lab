#include<stdio.h>
#include<stdlib.h>
#include<gmp.h>
#include<time.h>
int main()
{
	mpz_t num,temp1,temp2,temp3,temp4,a,k,j,md;
	mpz_inits(num,temp1,temp2,temp3,temp4,a,j,k,md,NULL);
	gmp_printf("\nEnter the Number for Primality Test : ");
	gmp_scanf("%Zd",num);
	mpz_mod_ui(md,num,2);
	if(mpz_cmp_ui(md,0)==0)
	{
		gmp_printf("\nThe Number is Composite\n\n");
		return 0;
	}
	if(mpz_cmp_ui(num,2)==0||mpz_cmp_ui(num,3)==0)
	{
		gmp_printf("\n%Zd is a prime number\n\n",num);
		return 0;
	}
	mpz_sub_ui(temp1,num,1);	// temp1 contains num-1 value
	mpz_set(temp3,temp1);
	mpz_sub_ui(temp3,num,4);	// temp3 for generating random numbers num-4+2
	mpz_mod_ui(temp2,temp1,2);
	mpz_set_ui(k,0);
	while(mpz_cmp_ui(temp2,0)!=0)   // finding the value of q in 2^k * q
	{
		mpz_div_ui(temp1,temp1,2);
		mpz_add_ui(k,k,1);
		mpz_mod_ui(temp2,temp1,2);
	}	// here temp1 is the value of q
	gmp_randstate_t state;
	gmp_randinit_mt(state);
	unsigned long seed;
	seed = time(NULL);
	gmp_randseed_ui(state,1000);
	mpz_urandomm(a,state,temp3);
	mpz_add_ui(a,a,2);	// a contains the random number 1 < a < n-1
	mpz_powm(temp4,a,temp1,num);
	if(mpz_cmp_ui(temp4,1)==0) 
	{
		gmp_printf("\n%Zd is Inconclusive( May be Prime )\n\n",num);
		return 0;
	}
	mpz_set_ui(j,0);
	mpz_t temp5,n_1;
	mpz_inits(temp5,n_1,NULL);
	mpz_set(temp5,temp1);
	mpz_sub_ui(n_1,n_1,1);
	while(mpz_cmp(j,k)<0)
	{
		mpz_powm(temp4,a,temp5,num);
		if(mpz_cmp(temp4,n_1)==0) 
		{
			gmp_printf("\n%Zd is Inconclusive( May be Prime )\n\n",num);
			return 0;
		}
		mpz_mul_ui(temp5,temp5,2);
		mpz_add_ui(j,j,1);
	}
	gmp_printf("\n%Zd is Composite Number\n\n",num);
	return 0;
}
