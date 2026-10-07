#include <stdio.h>
#define SIZE 100000
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
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
	for(i = 0;i < SIZE - 1;i++)
	{
		bool swapped = false;
		int j;
		for(j = 0;j < SIZE - 1 - i;j++)
			if(dest[j + 1] < dest[j])
			{
				swapped = true;
				int temp = dest[j];
				dest[j] = dest[j + 1];
				dest[j + 1] = temp;
			}
		if(!swapped)
			break;
	}
//	for(i = 0;i < SIZE;i++)
//		printf("%d ",dest[i]);
	return 0;
}
