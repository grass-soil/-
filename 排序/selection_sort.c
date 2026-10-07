#include <stdio.h>
#define SIZE 10
#include <time.h>
#include <stdlib.h>
int main(void)
{
	int i;
	srand((unsigned)time(0));
	int dest[SIZE];
	for(i = 0;i < SIZE;i++)
		dest[i] = rand() % SIZE + 1;
	for(i = 0;i < SIZE;i++)
		printf("%d ",dest[i]);
	putchar('\n');
	for(i = 0;i < SIZE - 1;i++)
	{
		int j;
		int flag = i;
		for(j = i + 1;j < SIZE;j++)
			if(dest[flag] > dest[j])
				flag = j;
		int temp = dest[flag];
		dest[flag] = dest[i];
		dest[i] = temp;
	}
	for(i = 0;i < SIZE;i++)
		printf("%d ",dest[i]);
	return 0;
}
