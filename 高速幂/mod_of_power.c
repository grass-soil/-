#include <stdio.h>
//幂的余数朴素算法 ，复杂度为n 
int main(void)
{
	int i;
	
	long long a;
	scanf("%lld",&a);
	int n;
	scanf("%d",&n);
	long long b;
	scanf("%lld",&b);
	long long ans = 1;
	for(i = 0;i < n;i++)
		ans = ((a % b) * ans) % b;
	printf("%lld",ans);
	return 0;
}
