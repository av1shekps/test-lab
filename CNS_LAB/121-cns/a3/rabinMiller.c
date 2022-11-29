#include <gmp.h>
#include <time.h>

int main(){
	// variable declarations
	mpz_t n,k,q,a,x,j,temp,mod,pow2;
	mpz_inits(n,k,q,a,x,j,temp,mod,pow2, NULL);

	// taking user input
	gmp_printf("Enter the odd number to test primality for: ");
	gmp_scanf("%Zd", &n);
	mpz_mod_ui(temp, n, 2);
	if(mpz_cmp_ui(temp, 0) == 0){
		gmp_printf("Input should only be an odd number\n");
		return 0;
	}

	// start the algorithm 
	gmp_printf("\nStarting the Rabin-Miller primality test on %Zd:");
	mpz_set_ui(k, 1);
	mpz_set_ui(pow2, 2);
	gmp_printf("\nDebug1");
	// calculating k and q
	do{
		// calculate q for given k
		mpz_fdiv_q(q, n-1, pow2);
		// finding remainder of n-1 and pow2 to check if q will be an integer
		mpz_mod(mod, n-1, pow2);
		// moving to next k
		mpz_add_ui(k, k, 1);
		mpz_mul_ui(pow2, pow2, 2);

		gmp_printf("\n%Zd", k); 
	}while(mpz_cmp_ui(mod, 0) != 0);
	gmp_printf("\nFound values of k and q:");
	gmp_printf("\nk= %Zd; q= %Zd", k, q);
	// initialising gmp_rand with seed
	gmp_randstate_t state;
	gmp_randinit_mt(state);
	unsigned long seed;
	seed = time(NULL);
	gmp_randseed_ui(state, seed);
	
	// select random number a between 0 and n-2, inclusive
	mpz_urandomm(a, state, n-1);
	// adding 2 to get a in range [2,n-2]
	mpz_add_ui(a, a, 2);
	// finding a^q mod n
	mpz_powm (x, a, q, n);
	
	if(mpz_cmp_ui(x, 1)==0){
		gmp_printf("\nInconclusive");
		return 0;
	}

	for(mpz_set_ui(j, 0); mpz_cmp(j, k) < 0; mpz_add_ui(j, j, 1)){
		mpz_powm_ui(x, x, 2, n);	
		if(mpz_cmp(x, n-1)==0){
			gmp_printf("\nInconclusive");
			return 0;
		}
	}

	gmp_printf("\nComposite");
}
