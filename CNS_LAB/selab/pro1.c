
#include<gmp.h>
#include <stdio.h>


void fact(int n){
  int i;
  mpz_t p;

  mpz_init_set_ui(p,1); 
  
  for (i=1; i <= n ; ++i){
    mpz_mul_ui(p,p,i); 
  }
  
  printf ("%d!  =  ", n);
  mpz_out_str(stdout,10,p);
  mpz_clear(p);

}

int main()
{
  mpz_t n;
  //mpz_init(n);
  //mpz_set_ui(n,0);
  
  mpz_init_set_ui(n,1);
  
  mpz_add_ui(n,n,10);
  
  printf (" n = ");
  mpz_out_str(stdout,10,n);
  printf ("\n");
  
  int f;
  scanf("%d",&f);
  
  fact(f);
  
  mpz_clear(n);
}
