#include <bits/stdc++.h>
#include <random>
#include "gmp.h"
#include "gmpxx.h"

using namespace std;

mpz_class pow_mod(mpz_class a, mpz_class d, mpz_class& n) {
    mpz_class r = 1;

    while (d > 0) {
        if ((d & 1) == 1) {
          r = a*r % n;
        }
        d >>= 1;
        a = a*a % n;
    }

    return r;
}

mpz_class inverse(mpz_class a, mpz_class& n) {
    mpz_class r = 1;

    for(size_t i=1; i<n; i++){
    	if( (a*i)%n == 1){
    		r = i;
    		return r;
    	}
    }

    return r;
}

int main () {
	mpz_class a,q,Xa,Ya,c1,c2,M,k,K,K1,M1;
	cout<<"Enter the Global elements\nPrime number : ";
	cout<<"q = "; cin>>q;
	cout<<"Primtive root of q = "; cin>>a;

	cout<<"Enter private key Xa (< q-1) = "; cin>>Xa;

	Ya = pow_mod(a,Xa,q);
	cout<<"Public key : Ya = "<<Ya<<"\n";

	cout<<"Enter message M (<q) = "; cin>>M;
	cout<<"Enter random number k (<q) = "; cin>>k;

	cout<<"\n  Encryption...\n";

	K = pow_mod(Ya,k,q);
	c1 = pow_mod(a,k,q);
	c2 = (K*M)%q;

	cout << "Ciphertext (c1,c2) = ("<<c1<<", "<<c2<<")\n\n  Decryption... \n";

	K1 = pow_mod(c1,Xa,q);
	M1 = (c2 * inverse(K,q))%q;

	cout<<"Decrypted message : "<<M<<"\n\n";

	return 0;
}
