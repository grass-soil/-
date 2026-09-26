#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main(void)
{
	//迭代器 
	int i;
	
	//读入a
	char temp_a[20000] = {0};
	scanf("%s",temp_a);
	
	//读入b 
	char temp_b[20000] = {0};
	scanf("%s",temp_b);
	
	//比较并交换字符串 
	int size_a = strlen(temp_a);
	int size_b = strlen(temp_b);
	bool ispos = true;
	if((size_a < size_b) || (size_a == size_b && strcmp(temp_a,temp_b) < 0)) //!!!
	{
		char temp[20000];
		strcpy(temp,temp_a);
		strcpy(temp_a,temp_b);
		strcpy(temp_b,temp);
		size_a = strlen(temp_a);
		size_b = strlen(temp_b);
		ispos = false;
	}
	
	//赋值
	int a[20000] = {0};
	int b[20000] = {0};
	for(i = 0;i < size_a;i++)
		a[i] = temp_a[size_a - 1 -i] - '0';
	for(i = 0;i < size_b;i++)
		b[i] = temp_b[size_b - 1 -i] - '0';
	
	//计算
	int ans[20000];
	for(i = 0;i < size_a;i++)
		if(a[i] < b[i])
		{
			a[i + 1]--;
			ans[i] = a[i] + 10 - b[i];	
		}else
			ans[i] = a[i] - b[i];
	
	//清除前导零
	int j = size_a - 1;
	while(ans[j] == 0 && j > 0)
		j--;
	
	//输出
	if(!ispos)
		putchar('-');
	for(i = j;i >= 0;i--)
		printf("%d",ans[i]);
	
	return 0;
}
