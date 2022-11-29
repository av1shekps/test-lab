#include<gmp.h>
void main()
{
  mpz_t a,m,c,x,r;
  mpz_inits(a,m,c,x,r,NULL);
  gmp_printf("\nEnter a-");
  gmp_scanf("%Zd",a);
  gmp_printf("\nEnter m-");
  gmp_scanf("%Zd",m);
  mpz_set_ui(x,1);
  do{
     mpz_mul(c,a,x);
     mpz_mod(r,c,m);
     if(mpz_cmp_ui(r,1)==0)
     break;
     mpz_add_ui(x,x,1);
     }while(mpz_cmp(x,m)<0);
   gmp_printf("\nMultiplicative Inverse: %Zd\n",x);
}
  