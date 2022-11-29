#include<gmp.h>
void main()
{
  mpz_t a,b,c;
  mpz_inits(a,b,c,NULL);
  gmp_printf("\nEnter a-");
  gmp_scanf("%Zd",a);
  gmp_printf("\nEnter b-");
  gmp_scanf("%Zd",b);
  if(mpz_cmp(a,b)<0)
  mpz_swap(a,b);
  mpz_t spp,sp,tpp,tp,rpp,rp,sc,tc,rc,qc,t;
  mpz_inits(spp,sp,tpp,tp,rpp,rp,sc,tc,rc,qc,t,NULL);
  mpz_set_ui(spp,1);
  mpz_set_ui(sp,0);
  mpz_set_ui(tpp,0);
  mpz_set_ui(tp,1);
  mpz_set(rpp,a);
  mpz_set(rp,b);
  do
  {
     mpz_fdiv_q(qc,rpp,rp);
     mpz_mod(rc,rpp,rp);
     mpz_mul(t,qc,sp);
     mpz_sub(sc,spp,t);
     mpz_mul(t,qc,tp);
     mpz_sub(tc,tpp,t);
     mpz_set(tpp,tp);
     mpz_set(spp,sp);
     mpz_set(tp,tc);
     mpz_set(sp,sc);
     mpz_set(rpp,rp);
     mpz_set(rp,rc);
  }while(mpz_cmp_ui(rc,0)>0);  
  gmp_printf("\nGCD is: %Zd\n",rpp);
  gmp_printf("\nX=: %Zd\n",sc);
  gmp_printf("\nY=: %Zd\n",tc);
 }
