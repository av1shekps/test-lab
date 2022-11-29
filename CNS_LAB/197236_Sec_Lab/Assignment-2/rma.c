#include<gmp.h>
void power(mpz_t x,mpz_t y,mpz_t p,mpz_t result)
{
   mpz_t res;
   mpz_set_ui(res,1);
   mpz_t t;
   mpz_mod(x,x,p);
   while(mpz_cmp_ui(y,0)>0)
   {
      mpz_mod_ui(t,y,2);
      if(mpz_cmp_ui(t,1)==0)
      {
         mpz_mul(res,res,x);
         mpz_mod(res,res,p);
      }
      mpz_div_ui(y,y,2);
      mpz_mul(x,x,x);
      mpz_mod(x,x,p);
   }
   mpz_set(result,res);
}
int millerTest(mpz_t d,mpz_t n)
{
   mpz_t a,t,x;
   gmp_randstate_t state;
   gmp_randinit_default(state);
   mpz_set(t,n);
   mpz_sub_ui(t,n,4);
   mpz_urandomm(a,state,t);
   mpz_sub_ui(t,n,1);
   mpz_add_ui(a,a,2);
    gmp_printf("D");
   power(a,d,n,x);
    gmp_printf("E");
   if(mpz_cmp_ui(x,1)||mpz_cmp(x,t))
   return 1;
   while(!mpz_cmp(d,t))
   {
     mpz_mul(x,x,x);
     mpz_mod(x,x,n);
     mpz_mul_ui(d,d,2);
     if(mpz_cmp_ui(x,1))
     return 0;
     if(mpz_cmp(x,t))
     return 1;
   }
   return 0;
}
int isPrime(mpz_t n,mpz_t k)
{
gmp_printf("\nZ %Zd",n);
  if(mpz_cmp_ui(n,1)<=0||mpz_cmp_ui(n,4)==0)
  return 0;
  gmp_printf("\nY");
  if(mpz_cmp_ui(n,3)<=0)
  {
     gmp_printf("X");
     return 1;
  }   
  if(mpz_cmp_ui(n,5)==0){
  gmp_printf("\nY");
  mpz_t d;
  mpz_set(d,n);
  mpz_sub_ui(d,d,1);
  gmp_printf("\nZ %Zd",d);
  mpz_t t;
  mpz_mod_ui(t,d,2);
  
  while(mpz_cmp_ui(t,0)==0)
  {
    mpz_div_ui(d,d,2);
     gmp_printf("\nA %Zd",d);
    mpz_mod_ui(t,d,2);
  }
   gmp_printf("\nB");
  mpz_t i;
  mpz_set_ui(i,0);
  while(mpz_cmp(i,k)<0)
  {
      gmp_printf("\nC");
     if(!millerTest(d,n))
     return 0;
      gmp_printf("\nF");
     mpz_add_ui(i,i,1);
  }
  }
  return 1;
  }
void main()
{
  mpz_t k,n,i;
  mpz_inits(k,n,i,NULL);
  gmp_printf("\nEnter k-");
  gmp_scanf("%Zd",k);
  gmp_printf("\nEnter n-");
  gmp_scanf("%Zd",n);
  gmp_printf("\nQ");
  mpz_set_ui(i,1);
  while(mpz_cmp(i,n)<0)
  {
     gmp_printf("\nP");
     if(isPrime(i,k))
     gmp_printf("%Zd ",i);
     mpz_add_ui(i,i,1);
   }
 }

