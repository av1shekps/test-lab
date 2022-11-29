#include<gmp.h>
void main()
{
  mpz_t a,x,n,res,t;
  mpz_inits(a,x,n,res,t,NULL);
  gmp_printf("\nEnter a-");
  gmp_scanf("%Zd",a);
  gmp_printf("\nEnter x-");
  gmp_scanf("%Zd",x);
  gmp_printf("\nEnter n-");
  gmp_scanf("%Zd",n);
  mpz_set_ui(res,1);
  while(mpz_cmp_ui(x,0)!=0)
  {
     mpz_mod_ui(t,x,2);
     if(mpz_cmp_ui(t,0)!=0){
         mpz_mul(res,res,a);
         mpz_mod(res,res,n);
     }
     mpz_fdiv_q_ui(x,x,2);
     mpz_mul(a,a,a);
     mpz_mod(a,a,n);
 }
 gmp_printf("\nAns: %Zd\n",res);
 }


