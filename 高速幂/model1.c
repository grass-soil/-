#include <stdio.h>
//非高精度 
int main(void)
{
	long long a;
	scanf("%lld",&a);
	int n;
	scanf("%d",&n);
	long long r = 1;
	while(n != 0)
	{
		if(n & 1 == 1)
			r *= a;
		a = a * a;
		n >>= 1;
	}
	printf("%lld",r);
	return 0;
}
