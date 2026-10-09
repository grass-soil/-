#include <stdio.h>
#define SIZE 4
#include <time.h>
#include <stdlib.h>
int main(void)
{
	srand(time(0));
	int dest[SIZE];
	for(int i = 0;i < SIZE;i++)
		dest[i] = i + 1;
	const long long size = (long long)SIZE;
	long long cases = (1LL << size);
	for(long long i = 0;i < cases;i++)
	{
		for(long long j = 0;j < size;j++)
			if(i >> j & 1L == 1L)
				printf("%d ",dest[j]);
		putchar('\n');
	}
	return 0;
}
