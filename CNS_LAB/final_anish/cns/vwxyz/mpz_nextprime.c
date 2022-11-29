#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int main(){
    mpz_t a, b, c, t;
    mpz_inits(a, b, c, t, NULL);
    
    // gmp_printf("Enter a number: ");
    // gmp_scanf("%Zd", a);
    mpz_set_ui(a, 97879);
    
    mpz_nextprime(b, a);
    gmp_printf("Result: %Zd\n", b);
    
    
    
    return 0;
}