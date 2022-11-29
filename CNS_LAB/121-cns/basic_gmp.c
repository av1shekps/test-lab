#include <gmp.h>
int main(){
	mpz_t a,b,c;
	mpz_inits(a,b,c,NULL);
	gmp_printf("Enter value of a: ");
	gmp_scanf("%Zd", a);
	gmp_printf("\nEnter value of b: ");
	gmp_scanf("%Zd", b);
	if(mpz_cmp(a,b)>0)
		gmp_printf("a is greater than b\n");
	else
		gmp_printf("b is greater than a\n");
	
	return 0;
}
