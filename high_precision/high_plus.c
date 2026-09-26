#include <stdio.h>
#include <string.h>
int main(void)
{
	char temp[20001];
	int a[20000] = {0};
	int b[20000] = {0};
	int ans[20001] = {0};
	
	//初始化a 
	scanf("%s",temp);
	int size_a = strlen(temp);
	int i;
	for(i = size_a - 1;i >= 0;i--)
		a[size_a - 1 - i] = temp[i] - '0';
		
	//初始化b
	scanf("%s",temp);
	int size_b = strlen(temp);
	int j;
	for(j = size_b - 1;j >= 0;j--)
		b[size_b - 1 - j] = temp[j] - '0';
		
	//计算并进位 
	int max = ((size_a > size_b)?(size_a):(size_b));
	for(int i = 0;i < max + 1;i++)
	{
		ans[i] += a[i] + b[i];
		ans[i + 1] += ans[i] / 10;	//难点 
		ans[i] %= 10;
	}
	
	//清除前导零 
	while(ans[max] == 0 && max > 0)
		max--;
		
	//输出
	int k;
	for(k = max;k >= 0;k--)
		printf("%d",ans[k]);
	return 0;
}
