#include<stdio.h>
#include<gmp.h>

typedef mpz_t mi;

void extended_euclidean_algorithm(mpz_t res, mpz_t x, mpz_t y, mpz_t a, mpz_t b){

	mpz_t x1, o_x, y1, o_y, r, o_r;
	mpz_init_set_ui(x1, 0);
	mpz_init_set_ui(o_x, 1);
	mpz_init_set_ui(y1, 1);
	mpz_init_set_ui(o_y, 0);
	mpz_init_set(r, a);
	mpz_init_set(o_r, b);

	mpz_t quotient, temp, mult, sub;

	while(mpz_get_ui(r) != 0){
		mpz_init(quotient);
		mpz_init(temp);
		mpz_init(mult);
		mpz_init(sub);

		mpz_tdiv_q(quotient, o_r, r); 

		mpz_set(temp, r);
		mpz_mul(mult, quotient, r);
		mpz_sub(sub, o_r, mult);
		mpz_set(r, sub);
		mpz_set(o_r, temp);

		mpz_set(temp, x);
		mpz_mul(mult, quotient, x);
		mpz_sub(sub, o_x, mult);
		mpz_set(x, sub);
		mpz_set(o_x, temp);

		mpz_set(temp, y);
		mpz_mul(mult, quotient, y);
		mpz_sub(sub, o_y, mult);
		mpz_set(y, sub);
		mpz_set(o_y, temp);
	}

	// set return values
	mpz_set(gcd, o_r);
	mpz_set(x, o_x);
	mpz_set(y, o_y); 

}

int main() {

	mpz_t a, b, res, x, y;
	
    mpz_init(a);
	mpz_init(b);
	mpz_init(res);
	mpz_init(x);
	mpz_init(y);


	gmp_scanf("%Zd %Zd",a,b);
	gmp_printf("Integer a: %Zd \n", a);
	gmp_printf("Integer b: %Zd \n", b);

	extended_euclidean_algorithm(res, x, y, a, b);
	gpm_printf("Computed Result: GCD(a, b): %Zd\n", res);	
	gmp_printf("The corresponding coefficients\n x:%Zd \n y:%Zd",x,y);

	
}
