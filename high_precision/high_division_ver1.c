#include <stdio.h>
#include <string.h>
int main(void)
{
	//迭代器
	int i;
	
	//初始化 
	char temp[20000];
	scanf("%s",temp);
	int a[20000];
	int size_a = strlen(temp);
	for(i = 0;i < size_a;i++)
		a[i] = temp[i] - '0';
	int b;
	scanf("%d",&b);
	
	//计算
	int remainder = 0;
	int ans[20000];
	for(i = 0;i < size_a;i++)
	{
		remainder = remainder * 10 + a[i];
		ans[i] = remainder / b;
		remainder %= b;
	}
	
	//去除前导零
	int index = 0;
	while(ans[index] == 0 && index < size_a)
		index++;
		
	//输出
	for(i = index;i < size_a;i++)
		printf("%d",ans[i]);
	putchar(' ');
	printf("%d",remainder);
	
	return 0;
}
