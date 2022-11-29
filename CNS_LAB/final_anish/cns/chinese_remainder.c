#include<stdio.h>
#include<stdlib.h>
#include<gmp.h>

void multiplicative_inverse(mpz_t ans, mpz_t a, mpz_t m)
{
    mpz_t m0,x,y,q,t,temp1;
    mpz_inits(m0,x,y,q,t,temp1,NULL);
    mpz_set(m0,m);
    mpz_set_ui(y,0);
    mpz_set_ui(x,1);
    if(mpz_cmp_ui(m,1)==0)
    {
    	mpz_set_ui(ans,0);
    	return;
    }
    while(mpz_cmp_ui(a,1)>0)
    {
    	mpz_div(q,a,m);
    	mpz_set(t,m);
    	mpz_mod(m,a,m);
    	mpz_set(a,t);
    	mpz_set(t,y);
    	mpz_mul(temp1,q,y);
    	mpz_sub(y,x,temp1);
    	mpz_set(x,t);
    }
	if(mpz_cmp_ui(x,0)<0)
		mpz_add(x,x,m0);
	mpz_set(ans,x);
}

int main()
{
	mpz_t n,M,ans,temp1,tempMs,tempm;
	mpz_inits(n,M,ans,temp1,tempMs,tempm,NULL);
	gmp_printf("\nEnter the Number of equation(n) : ");
	gmp_scanf("%Zd",n);
	mpz_t a[mpz_get_ui(n)];
	mpz_t m[mpz_get_ui(n)];
	mpz_t Ms[mpz_get_ui(n)];
	mpz_t X[mpz_get_ui(n)];
	for(long long int i = 0;i<mpz_get_ui(n);i++)
		mpz_inits(a[i],m[i],Ms[i],X[i],NULL);
	gmp_printf("\nEnter the remainder and modulo pair\n");
	for(long long int i = 0;i<mpz_get_ui(n);i++)
	{
		gmp_scanf("%Zd",a[i]);
		gmp_scanf("%Zd",m[i]);
	}
	mpz_set_ui(M,1);
	for(long long int i = 0;i<mpz_get_ui(n);i++)
		mpz_mul(M,M,m[i]);
	for(long long int i = 0;i<mpz_get_ui(n);i++)
		mpz_div(Ms[i],M,m[i]);
	for(long long int i = 0;i<mpz_get_ui(n);i++)
	{
		mpz_set(tempMs,Ms[i]);
		mpz_set(tempm,m[i]);
		multiplicative_inverse(X[i],tempMs,tempm);
	}
	mpz_set_ui(ans,0);
	for(long long int i = 0;i<mpz_get_ui(n);i++)
	{
		mpz_mul(temp1,a[i],X[i]);
		mpz_mul(temp1,temp1,Ms[i]);
		mpz_add(ans,ans,temp1);
	}
	mpz_mod(ans,ans,M);
	gmp_printf("\nThe Answer is %Zd\n\n",ans);
	return 0;
}
