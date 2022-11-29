#include<stdio.h>
#include<gmp.h>
#include<string.h>
#include<time.h>
int main()
{
	mpz_t pt;
	mpz_init(pt);
	gmp_printf("\nEnter the plain text : ");
	gmp_scanf("%Zd",pt);
	
	gmp_randstate_t state;
	gmp_randinit_mt(state);
	unsigned long seed;
	seed = time(NULL);
	gmp_randseed_ui(state,seed);
	
	mpz_t p,q,n,e,temp,t1,t2,t5,t6,phi_n;
	mpz_inits(p,q,n,e,temp,t1,t2,t5,t6,phi_n,NULL);
	mpz_set_ui(t5,500);
	mpz_urandomm(t6,state,t5); // t6 = randomnumber in 0 - 500
	mpz_set_ui(temp,2);
	mpz_pow_ui(temp,temp,mpz_get_ui(t6)); // setting the value of temp to 2^t6
	mpz_nextprime(p,temp); // setting p to next prime > 2^t6
	mpz_nextprime(q,p); // setting q to next prime > p
	mpz_mul(n,p,q); // n = p * q
	mpz_sub_ui(t1,p,1); // t1 = p-1
	mpz_sub_ui(t2,q,1); // t2 = q-1
	mpz_mul(phi_n,t1,t2); // phi(n) = (p-1) * (q-1)
	
	// now finding a value of e where 1 < e < phi(n)

	mpz_t t3,t4;
	mpz_inits(t3,t4,NULL);
	mpz_sub_ui(t3,phi_n,2); // t3 = phi(n) - 2	
	mpz_set(e,phi_n);
	mpz_gcd(t4,e,phi_n); // t4 = gcd(e,phi(n))
	while(mpz_cmp_ui(t4,1)!=0) // find value of e relatively prime to phi(n)
	{
		mpz_urandomm(e,state,t3); // here 0 <= e <= phi(n) - 3
		mpz_add_ui(e,e,2); // here 1 < e < phi(n)
		mpz_gcd(t4,e,phi_n); // t4 = gcd(e,phi(n))
	}
	gmp_printf("\n\nPublic Key ( n , e ) : ( %Zd , %Zd )",n,e);
	
	// now encrypting the message using public key
	
	mpz_t em;
	mpz_init(em);
	mpz_powm(em,pt,e,n);
	gmp_printf("\n\nEncrypted Measage : %Zd",em);
	
	// now finding the private key
	mpz_t d;
	mpz_init(d);
	mpz_invert(d,e,phi_n);
	gmp_printf("\n\nPrivate Key (d) : %Zd",d);
	
	// now decrypting the message
	mpz_t dm;
	mpz_init(dm);
	mpz_powm(dm,em,d,n);
	gmp_printf("\n\nDecrypted Measage : %Zd\n\n",dm);
	
	return 0;
}
