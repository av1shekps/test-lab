#include <gmp.h>
int main()
{
    mpz_t a[3], n[3], m[3], x[3];
    mpz_t answer, M;
    mpz_inits(a[0], a[1], a[2], n[0], n[1], n[2], m[0], m[1], m[2], x[0], x[1], x[2], answer, M, NULL);
    gmp_printf("Enter the numbers in order of reminders and then corresponding FF set\n");
    gmp_scanf("%Zd %Zd %Zd %Zd %Zd %Zd", a[0], n[0], a[1], n[1], a[2], n[2]);
    mpz_set_si(M, 1);
    mpz_mul(M, M, n[0]);
    mpz_mul(M, M, n[1]);
    mpz_mul(M, M, n[2]);
    mpz_cdiv_q(m[0], M, n[0]);
    mpz_cdiv_q(m[1], M, n[1]);
    mpz_cdiv_q(m[2], M, n[2]);
    mpz_invert(x[0], m[0], n[0]);
    mpz_invert(x[1], m[1], n[1]);
    mpz_invert(x[2], m[2], n[2]);
    mpz_set_ui(answer, 0);
    mpz_t temp;
    mpz_init(temp);
    mpz_mul(temp, a[0], m[0]);
    mpz_mul(temp, temp, x[0]);
    mpz_add(answer, answer, temp);
    mpz_mul(temp, a[1], m[1]);
    mpz_mul(temp, temp, x[1]);
    mpz_add(answer, answer, temp);
    mpz_mul(temp, a[2], m[2]);
    mpz_mul(temp, temp, x[2]);
    mpz_add(answer, answer, temp);
    mpz_mod(answer, answer, M);
    gmp_printf("answer is : %Zd\n", answer);
}
