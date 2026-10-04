#include <stdio.h>
//¹Ø¼ü¹«Ê½ (a x b) % c = ((a % c) x (b % c)) % c
int main(void)
{
	long long a;
	scanf("%lld",&a);
	int n;
	scanf("%d",&n);
	long long b;
	scanf("%lld",&b);
	long long ans = 1;
	while(n != 0)
	{
		if(n & 1 == 1)
			ans = ((a % b) * ans) % b;
		a *= a;
		n >>= 1;
	}
	printf("%lld",ans);
	return 0;
}
