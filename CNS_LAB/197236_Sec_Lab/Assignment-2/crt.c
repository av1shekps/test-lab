#include <gmp.h>
#include <stdio.h>
#include <time.h>


void crt(mpz_t nums[], mpz_t rems[], int n)
{
	mpz_t x;
	mpz_init_set_ui(x, 1);
	int f = 1;
	while(f)
	{
		int ind;
		for(ind = 0;ind < n;ind++)
		{
			mpz_t rem;
			mpz_init(rem);
			mpz_mod(rem, x, nums[ind]);
			if(mpz_cmp(rem, rems[ind]) != 0)
			break;
		}
		if(ind == n){
		gmp_printf("Answer: %Zd\n", x);
		break;
		}
		mpz_add_ui(x, x, 1);
	}
}
void main()
{
	mpz_t nums[20], rems[20];

	int n;
	printf("Enter value of n: \n");
	scanf("%d", &n);
	int ind = 0;
	while(ind < n)
	{
		mpz_init(nums[ind]);
		mpz_init(rems[ind]);
		gmp_printf("Enter the number and remainder: \n");
		gmp_scanf("%Zd%Zd", &nums[ind], &rems[ind]);
		ind++;
	}
	ind = 0;
	while(ind < n)
	{

		gmp_printf("%Zd, %Zd\n", nums[ind], rems[ind]);
		ind++;
	}
	crt(nums, rems, n);
}
