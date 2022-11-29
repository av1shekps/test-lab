#include <stdio.h>
#include <gmp.h>
#include <time.h>

void main() {
	mpz_t a, b, prime_no;
	mpz_inits(a, b, prime_no, NULL);
	
	gmp_randstate_t state;
	gmp_randinit_mt(state);
	unsigned long seed;
	seed = time(NULL);
	gmp_randseed_ui(state, seed);
	
	int bits = 1024;
	
	while(1) {
		mpz_rrandomb(a, state, bits);
		
		mpz_set(b, a);
		if(mpz_probab_prime_p(b, 25) == 2) {
			gmp_printf("%Zd\n", b);
			break;
		}
		else if(mpz_probab_prime_p(b, 25) == 1) {
			mpz_nextprime(prime_no, b);
			gmp_printf("%Zd\n", prime_no);
			break;
		}
	}
}