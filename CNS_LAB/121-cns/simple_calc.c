#include <gmp.h>
int main(){
	mpz_t a,b,c;
	mpz_inits(a,b,c,NULL);
	gmp_printf("\nEnter the value of a:");
	gmp_scanf("%Zd", a);
	gmp_printf("\nEnter the value of b:");
	gmp_scanf("%Zd", b);
	
	gmp_printf("Performing all the arithmetic operations on a and b:\n");
	mpz_add(c,a,b);
	gmp_printf("Sum of a and b: %Zd\n",c);
	mpz_sub(c,a,b);
	gmp_printf("Difference of a-b=%Zd\n", c);
	mpz_mul(c,a,b);
	gmp_printf("Product of a and b is %Zd\n", c);
	mpz_fdiv_q(c,a,b);
	gmp_printf("Quotient of a/b is %Zd\n", c);
	mpz_mod(c,a,b);
	gmp_printf("Remainder of a/b is %Zd\n", c);

	return 0;
}
