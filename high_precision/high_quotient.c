//单精度除以单精度得到高精度商 
#include <stdio.h>
int main(void)
{
	//迭代器
	int i; 
	
	//初始化 
	int a;
	scanf("%d",&a);
	int b;
	scanf("%d",&b);
	int n;
	scanf("%d",&n);
	
	//计算并输出
	printf("%d.",a / b);
	int remainder = a % b;
	for(i = 0;i < n;i++)
	{
		remainder *= 10;
		printf("%d",remainder / b);
		remainder %= b;
	}
	return 0;
}
