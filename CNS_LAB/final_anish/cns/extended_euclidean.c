#include<stdio.h>
#include<stdlib.h>
#include<gmp.h>

void extened_euclidean(mpz_t ans,mpz_t bx,mpz_t by,mpz_t a,mpz_t b)
{
	mpz_t x1,y1,x2,y2,r1,r2,q,x,y,r,tempa,tempb,temp1,temp2,temp3;
	mpz_inits(x1,x2,y1,y2,r1,r2,q,x,y,r,tempa,tempb,temp1,temp2,temp3,NULL);
	mpz_set_ui(x1,1);
	mpz_set_ui(y1,0);
	mpz_set_ui(x2,0);
	mpz_set_ui(y2,1);
	mpz_set(r1,a);
	mpz_set(r2,b);
	mpz_set(tempa,a);
	mpz_set(tempb,b);
	while(mpz_cmp_ui(r2,0)!=0)
	{
		// calcualating q
		mpz_fdiv_q(q,tempa,tempb);
	
		// calculating x
		mpz_mul(temp1,q,x2);
		mpz_sub(x,x1,temp1);
		
		// calculating y
		mpz_mul(temp1,q,y2);
		mpz_sub(y,y1,temp1);
		
		// calculating r
		mpz_mul(temp1,a,x);
		mpz_mul(temp2,b,y);
		mpz_add(r,temp1,temp2);
		
		mpz_set(x1,x2);
		mpz_set(y1,y2);
		mpz_set(r1,r2);
		mpz_set(x2,x);
		mpz_set(y2,y);
		mpz_set(r2,r);
		mpz_set(tempa,tempb);
		mpz_set(tempb,r);
	}

	mpz_set(ans,r1);
	mpz_set(bx,x1);
	mpz_set(by,y1);	
	
}

int main()
{
	mpz_t a,b,x,y,ans;
	mpz_inits(a,b,x,y,ans,NULL);
	gmp_printf("Enter Two Numbers a and b : \n");
	gmp_scanf("%Zd",a);
	gmp_scanf("%Zd",b);
	extened_euclidean(ans,x,y,a,b);
	gmp_printf("\nBezout Coefficients x and y are %Zd and %Zd\n\n",x,y);
	gmp_printf("GCD of %Zd and %Zd is %Zd\n\n",a,b,ans);
	return 0;
}
