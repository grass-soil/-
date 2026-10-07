#include <stdio.h>
#define SIZE 100000
#include <time.h>
#include <stdlib.h>
int main(void)
{
	int i;
	srand((unsigned)time(0));
	int dest[SIZE];
	for(i = 0;i < SIZE;i++)
		dest[i] = rand() % SIZE + 1;
//	for(i = 0;i < SIZE;i++)
//		printf("%d ",dest[i]);
//	putchar('\n');
	for(i = SIZE / 2;i > 0;i /= 2)
	{
		int j;
		for(j = i;j < SIZE;j++)
		{
			int temp = dest[j];
			int k = j - i;
			while(k >= 0 && dest[k] > temp)
			{
				dest[k + i] = dest[k];
				k -= i;
			}
			dest[k + i] = temp;
		}
	}
//	for(i = 0;i < SIZE;i++)
//		printf("%d ",dest[i]);
	return 0;
}
