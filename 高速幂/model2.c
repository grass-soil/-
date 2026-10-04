#include <stdio.h>
#include <string.h>
//高精度 + 快速幂

int mul(int* ans,const int* a,const int* b,int size_a,int size_b){
	int i , j;
	
	int ret = size_a + size_b;
	int temp[20000] = {0};
	for(i = 0;i < size_a;i++)
		for(j = 0;j < size_b;j++)
		{
			temp[i + j] += a[i] * b[j];
			temp[i + j + 1] += temp[i + j] / 10;
			temp[i + j] %= 10;
		}
	while(temp[ret - 1] == 0 && ret > 1)
		ret--;
	memcpy(ans,temp,sizeof(int) * 20000);
	return ret;
}

int main(void)
{
	int i;
	
	int num;
	scanf("%d",&num);
	int size_a = 0;
	int a[20000] = {0};
	do{
		a[size_a++] = num % 10;
	}while(num /= 10);
	int n;
	scanf("%d",&n);
	//计算 a ^ n (高精度)
	int ans[20000] = {1};
	int size_ans = 1;
	while(n != 0)
	{
		if(n & 1 == 1)
			//塞一个高精度乘法 ans *= a
			size_ans = mul(ans,ans,a,size_ans,size_a);
		 //高精度 a *= a
		 size_a = mul(a,a,a,size_a,size_a);
		 n >>= 1;
	}
	for(i = size_ans - 1;i >= 0;i--)
		printf("%d",ans[i]);
	return 0;
}
