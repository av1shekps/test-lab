#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

// Here the addition of polynomials is the XOR of the coefficients
char *addition(char f[],char g[],int n)
{
	char *ans;
	ans = (char*)malloc(n);
	for(int i=0;i<n;i++)
	{
		if((f[i]=='1'&&g[i]=='0')||(f[i]=='0'&&g[i]=='1'))	// XOR is 1 only if any one of the coefficient is 1 else 0
			ans[i]='1';
		else
			ans[i]='0';
	}
	return ans;
}

// Here for GF(2^n) the addition and subtraction results same as 1%2==1 and -1%2==1
char *subtraction(char f[],char g[],int n)
{
	char *ans;
	ans = (char*)malloc(n);
	for(int i=0;i<n;i++)
	{
		if((f[i]=='1'&&g[i]=='0')||(f[i]=='0'&&g[i]=='1'))
			ans[i]='1';
		else
			ans[i]='0';
	}
	return ans;
}

// Here for GF(2^n) the multiplication using fast multiplication
char* multiplication(char f[],char g[],char ir[],int n)
{
	char *ans;
	ans = (char *)malloc(n);
	
	char temppol[n];
	for(int i=0;i<n;i++)
	{
		temppol[i]=f[i];
		ans[i]='0';
	}
	
	for(int i=1;i<n;i++)
	{
		if(temppol[0]=='0')
		{
			for(int j=0;j<n-1;j++)
				temppol[j]=temppol[j+1];
			temppol[n-1]='0';
		}
		else
		{
			for(int j=0;j<n-1;j++)
				temppol[j]=temppol[j+1];
			temppol[n-1]='0';
			for(int j=0;j<n;j++)
			{
				if((temppol[j]=='1'&&ir[j+1]=='0')||(temppol[j]=='0'&&ir[j+1]=='1'))
					temppol[j]='1';
				else
					temppol[j]='0';
			}
		}
		if(g[n-i-1]=='1')
		{
			for(int j=0;j<n;j++)
			{
				if((ans[j]=='1'&&temppol[j]=='0')||(ans[j]=='0'&&temppol[j]=='1'))
					ans[j]='1';
				else
					ans[j]='0';
			}
		}
	}
	if(g[n-1]=='1')
	{
		for(int i=0;i<n;i++)
		{
			if((ans[i]=='1'&&f[i]=='0')||(ans[i]=='0'&&f[i]=='1'))
				ans[i]='1';
			else
				ans[i]='0';
		}
	}
	return ans;
}

long long int power(int a,int b)
{
	if(a==0||a==1) return a;
	long long int ans=1;
	for(int i=0;i<b;i++)
		ans*=a;
	return ans;
}

char *digit_to_binary(int val,int n)
{
	char *ans;
	ans = (char *)malloc(n);
	int p=0;
	while(val>0)
	{
		if(val%2==1)
			ans[n-p-1]='1';
		else
			ans[n-p-1]='0';
		val/=2;
		p++;
	}
	while(p<n)
	{
		ans[n-p-1]='0';
		p++;
	}
	return ans;
}

// Here division of polynomials is done by multiplying with its multiplicative inverse
char *multiplicative_inverse(char g[],char ir[],int n)
{
	char *ans,*temp;
	for(int i=0;i<power(2,n);i++)
	{	
		ans = digit_to_binary(i,n);
		temp = multiplication(g,ans,ir,n);
		if(temp[n-1]=='1')
		{
			bool flag=true;
			for(int j=0;j<n-1;j++)
			{
				if(temp[j]=='1')
				{
					flag=false;
					break;
				}
			}
			if(flag) return ans;
		}
	}
	return ans;
}

// Here division is done by multiplying a polynomial with its multiplicative inverse of other polynomial
char *division(char f[],char g[],char ir[],int n)
{
	char *temp;
	temp = multiplicative_inverse(g,ir,n);
	printf("Multiplicative Inverse of g is : %s\n\n",temp);
	return multiplication(f,temp,ir,n);
}

int main()
{
	int n;
	printf("\nEnter the Value of n in GF(2^n) : ");
	scanf("%d",&n);
	
	char f[100],g[100],ir[100];
	
	printf("\nEnter the first polynomial f(x) whose coefficients are in the form of binary digits : ");
	scanf("%s",f);
	
	printf("\nEnter the second polynomial g(x) whose coefficients are in the form of binary digits : ");
	scanf("%s",g);
	
	printf("\nEnter the irreducible polynomial whose coefficients are in the form of binary digits : ");
	scanf("%s",ir);
	printf("\n");
	
	printf("Addition of polynomials f and g is : %s\n\n",addition(f,g,n));
	
	printf("Subtraction of polynomials f and g is : %s\n\n",subtraction(f,g,n));
	
	printf("Multiplication of polynomials f and g is : %s\n\n",multiplication(f,g,ir,n));
	
	printf("Division of polynomials f and g is : %s\n\n",division(f,g,ir,n));
	
	return 0;
	
}
