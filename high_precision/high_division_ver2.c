#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool cmp(int x[],int y[]){
	int i;
	for(i = 1;i <= x[0];i++)
	{
		if(x[i] > y[i])
			return true;
		if(x[i] < y[i])
			return false;
	}
	return true;
}

int main(void)
{
	//迭代器
	int i;
	int j;
	
	//初始化 
	char temp[20000];
	scanf("%s",temp);
	int a[20001];
	a[0] = strlen(temp);
	for(i = 1;i <= a[0];i++)
		a[i] = temp[i - 1] - '0';
	scanf("%s",temp);
	int b[20001];
	b[0] = strlen(temp);
	for(i = 1;i <= b[0];i++)
		b[i] = temp[i - 1] - '0';
	
	//计算
	int ans[20001] = {0};
	ans[0] = a[0] - b[0] + 1;
	for(i = 1;i <= ans[0];i++)
	{
		int t[40001] = {0};
		t[0] = b[0] + i - 1;
		for(j = 1;j <= b[0];j++)
			t[j + i - 1] = b[j];
		a[0] = t[0];
		ans[i] = 0;
		while(cmp(a,t))
		{
			ans[i]++;
			for(j = 1;j <= a[0];j++)
			{
				if(a[j] < t[j])
				{
					a[j] += 10;
					a[j - 1]--;
				}
				a[j] -= t[j];
			}
		}
	}
	
	//删除前导零
	int index_ans = 1; 
	while(ans[index_ans] == 0 && index_ans < ans[0])
		index_ans++;
	int index_a = 1;
	while(a[index_a] == 0 && index_a < a[0])
		index_a++;
	
	//输出
	for(i = index_ans;i <= ans[0];i++)
		printf("%d",ans[i]);
	putchar(' ');
	for(i = index_a;i <= a[0];i++)
		printf("%d",a[i]);
	return 0;	
}
