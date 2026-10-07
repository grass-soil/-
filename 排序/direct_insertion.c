#include <stdio.h>
#define SIZE 70
#include <time.h>
#include <stdlib.h>
//÷±Ω”≤Â»Î 
int main(void)
{
	int i;
	srand((unsigned)time(0));
	int dest[SIZE];
	for(i = 0;i < SIZE;i++)
		dest[i] = rand() % SIZE + 1;
	for(i = 0;i < SIZE;i++)
		printf("%d ",dest[i]);
	for(i = 1;i < SIZE;i++)
	{
		int j = i - 1;
		int temp = dest[i];
		while(j >= 0 && dest[j] > temp)
		{
			dest[j + 1] = dest[j];
			j--;
		}
		dest[j + 1] = temp;
	}
	putchar('\n');
	for(i = 0;i < SIZE;i++)
		printf("%d ",dest[i]);
	return 0;
}
