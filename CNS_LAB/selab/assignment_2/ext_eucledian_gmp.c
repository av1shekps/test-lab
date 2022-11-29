
#include<gmp.h>
#include <stdio.h>

int main() {

	mpz_t rn1, rn2, my_result, s, t;
	
        mpz_inits(rn1,rn2,NULL);
        gmp_scanf("%Zd %Zd",rn1,rn2);
        
        if(mpz_cmp(a,b)<0)
        {
            mpz_swap(a,b);
        }
        
        gmp_printf("Numbers are %Zd , %Zd\n",rn1,rn2);
        
    	//mpz_init_set_ui(rn1,120000);
 
	//mpz_init_set_ui(rn2,546);
	
	mpz_init(my_result);
	mpz_init(s);
	mpz_init(t);
	
	
	mpz_t x, o_x, y, o_y, r, o_r;
	mpz_init_set_ui(x, 0);
	mpz_init_set_ui(o_x, 1);
	mpz_init_set_ui(y, 1);
	mpz_init_set_ui(o_y, 0);
	mpz_init_set(r, rn1);
	mpz_init_set(o_r, rn2);

	mpz_t quotient, temp, mult, sub;

	while(mpz_get_ui(r) != 0)
	{
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

	mpz_set(my_result, o_r);
	mpz_set(s, o_x);
	mpz_set(t, o_y); 

	gmp_printf("GCD is %Zd\n",my_result);
	//mpz_out_str(stdout,10,my_result);

	
}
