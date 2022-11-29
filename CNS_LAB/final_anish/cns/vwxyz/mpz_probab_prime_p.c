#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int main(){
    mpz_t a, b, c, t;
    mpz_inits(a, b, c, t, NULL);
    
    gmp_printf("Enter a number: ");
    gmp_scanf("%Zd", a);
    
    gmp_printf("Result: %d\n", mpz_probab_prime_p(a, 100));
    
    
    
    return 0;
}