#include <stdio.h>
#include <gmp.h>
#include <time.h>

void main() {
	mpz_t a, b, c;
	mpz_inits(a, b, c, NULL);
	
	gmp_scanf("%Zd", a);
	gmp_scanf("%Zd", b);
	
	mpz_invert(c, a, b);
	gmp_printf("Modular Inverse: %Zd", c);
	
}