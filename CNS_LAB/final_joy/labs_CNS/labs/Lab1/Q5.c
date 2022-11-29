#include<stdlib.h>
#include<stdio.h>

int main()
{
	int a[1024];
	int n;
	int pb;
	a[0]=0;
	scanf("%d",&n);
	int count=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==1)
			count++;
	}
	if(count%2!=0)
		a[0]=1;
	
	for(int i=0;i<=n;i++)
		printf("%d",a[i]);
	printf("\n");
}
