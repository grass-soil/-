#include <stdio.h>
#include <string.h>
int main(void)
{
	//迭代器 
	int i;
	int j;
	
	//读取并转换 
	char temp[20000];
	scanf("%s",temp);
	int size_a = strlen(temp);
	int a[20000] = {0};
	for(i = 0;i < size_a;i++)
		a[i] = temp[size_a - 1 - i] - '0';
	scanf("%s",temp);
	int size_b = strlen(temp);
	int b[20000] = {0};
	for(i = 0;i < size_b;i++)
		b[i] = temp[size_b - 1 - i] - '0';
	
	//运算并进位
	int ans[40000] = {0};
	for(i = 0;i < size_a;i++)
		for(j = 0;j < size_b;j++)
		{
			ans[i + j] += a[j] * b[i];
			if(ans[i + j] >= 10)
			{
				ans[i + j + 1] += ans[i + j] / 10;
				ans[i + j] %= 10; 
			}
		}
	
	//去零
	int len = size_a + size_b - 1;
	while(ans[len] == 0 && len > 0)
		len--;
		
	//输出
	for(i = len;i >= 0;i--)
		printf("%d",ans[i]);
	return 0;
}
