#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int main()
{
	mpz_t a1,a2,m1,m2,M,x,temp;			
	mpz_inits(a1,a2,m1,m2,M,x,temp,NULL);
	
	mpz_t M1, M2; 
	mpz_inits(M1, M2, NULL);
	
	gmp_printf("\nEnter  a1 \n: ");	
	gmp_scanf("%Zd",a1);
	
	gmp_printf("Enter  m1 \n: ");	
	gmp_scanf("%Zd",m1);
	
	gmp_printf("Enter  a2 \n: ");	
	gmp_scanf("%Zd",a2);
	
	gmp_printf("Enter  m2 \n: ");	
	gmp_scanf("%Zd",m2);

	mpz_mul(M,m1,m2);

	mpz_set_ui(M1,0);
 	
 	for(M1; mpz_cmp(M1,m1)<0 ; mpz_add_ui(M1,M1,1))
 	{
 	mpz_mul(temp,m1,M1);
 	mpz_mod(temp,temp,m2);

 	if( mpz_cmp_ui(temp,1) == 0)
	{
	break;
	}
 	}

	mpz_set_ui(M2,0);
 	
 	for(M2; mpz_cmp(M2,m2)<0 ; mpz_add_ui(M2,M2,1))
 	{
 	mpz_mul(temp,m2,M2);
 	mpz_mod(temp,temp,m1);

 	if( mpz_cmp_ui(temp,1) == 0)
 	{
	break;
	}
 	}

 	mpz_mul(x,a1,m2);
 	mpz_mul(x,x,M2);

 	mpz_mul(temp,a2,m1);
 	mpz_mul(temp,temp,M1);
 	mpz_add(x,x,temp);

 	mpz_mod(x,x,M);

 	printf("\n------------------------------------------------------\n");
 	gmp_printf("\nx = %Zd mod %Zd\n",x,M);
 	printf("\n------------------------------------------------------\n"); 	
	
	return 0;
}
