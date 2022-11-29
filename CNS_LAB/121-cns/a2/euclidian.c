#include <gmp.h>
int main(){
	mpz_t a,b,r,A,B;
	mpz_inits(a,b,r,A,B,NULL);
	gmp_printf("Enter the two numbers a and b to find gcd(a,b)");
	gmp_printf("\na: ");
	gmp_scanf("%Zd", &a);
	gmp_printf("b: ");
	gmp_scanf("%Zd", &b);
	mpz_set(A,a); // A = a
	mpz_set(B,b); // B = b
	gmp_printf("\nStarting calculation of gcd(%Zd, %Zd)", a, b);
	// swapping a and b if a<b because it is assumed a>b for the euclidian algorithm
	if(mpz_cmp_ui(a, b)<0){
		mpz_t t; 
		mpz_inits(t,NULL);
		mpz_set(t, a); // t = a
		mpz_set(a, b); // a = b
		mpz_set(b, t); // b = t
	}
	// finding the gcd
	gmp_printf("\ngcd(%Zd, %Zd) = \n", a, b);
	while(mpz_cmp_ui(b, 0)!=0){
                mpz_set(r,b);
                mpz_mod(b,a,b); // b = a%b
                mpz_set(a,r);
		gmp_printf("gcd(%Zd, %Zd) = \n", a, b);
        }

	// gcd will be a at the end
	gmp_printf("\nGCD(%Zd, %Zd) = %Zd\n", A, B, a);
	
	return 0;
}	

