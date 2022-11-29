#include <gmp.h>
int main()
{
    mpz_t r, q, x, y, x1, x2, y1, y2, r1, r2, gcd, temp, brk;
    mpz_inits(r, q, x, y, x1, x2, y1, y2, r1, r2, gcd, temp, brk, NULL);
    mpz_set_ui(brk, 1);
    gmp_printf("Enter the value of a and b for GCD(a,b): ");
    gmp_scanf("%Zd", r2);
    gmp_scanf("%Zd", r1);
    gmp_printf("Initiating the calcultion of GCD(%Zd,%Zd)\n\n", r2, r1);

    mpz_set_ui(x2, 1);
    mpz_set_ui(x1, 0);

    mpz_set_ui(y2, 0);
    mpz_set_ui(y1, 1);

    mpz_set_ui(gcd,1);

    while(mpz_cmp_ui(brk, 0)!=0)
    {
        gmp_printf("q(i)=%Zd, r(i)=%Zd, s(i)=%Zd, t(i)=%Zd\n\n", q, r, x, y);

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
    gmp_printf("a,b: %Zd,%Zd\n", x2, y2);
    gmp_printf("GCD: %Zd\n", r2);
}
