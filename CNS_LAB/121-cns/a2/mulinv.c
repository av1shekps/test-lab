#include <gmp.h>
int main()
{
    mpz_t r, q, x, y, x1, x2, y1, y2, r1, r2, gcd, temp, brk;
    mpz_inits(r, q, x, y, x1, x2, y1, y2, r1, r2, gcd, temp, brk, NULL);
    mpz_set_ui(brk, 1);
    gmp_printf("Enter the value of a whose multiplicative inverse under b is to be calculated: \n");
    gmp_scanf("%Zd", r2);
    gmp_scanf("%Zd", r1);
    gmp_printf("Initiating the calcultion of multiplicative inverse of a under b\n\n", r2, r1);

    mpz_set_ui(x2, 1);
    mpz_set_ui(x1, 0);

    mpz_set_ui(y2, 0);
    mpz_set_ui(y1, 1);

    mpz_set_ui(gcd,1);

    while(mpz_cmp_ui(brk, 0)!=0)
    {
        // calculate qi and ri
        mpz_fdiv_q(q,r2, r1);
        mpz_fdiv_r(r,r2, r1);

        // calculate xi
        mpz_mul(temp, q, x1);
        mpz_sub(x, x2, temp);

        // calculate yi
        mpz_mul(temp, q, y1);
        mpz_sub(y, y2, temp);

        // make s2 = s1 and s1 = s
        mpz_set(x2,x1);
        mpz_set(x1, x);
	        // make t2 = t1 and t1 = t
        mpz_set(y2, y1);
        mpz_set(y1, y);

        mpz_set(r2, r1);
        mpz_set(r1, r);

        if (mpz_cmp_ui(r, 0)==0){
            mpz_set_ui(brk, 0);
        }
    }
    gmp_printf("GCD: %Zd\n", r2);

    if(mpz_cmp_ui(r2,1)!=0){
    	gmp_printf("\nMultiplicative inverse doesn't exist\n");
    }else{
    	gmp_printf("\n Multipicative inverse: %Zd\n", x2);
    }
}

