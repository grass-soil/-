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
	int left = 0;
	int right = SIZE - 1;
	while(left < right)
	{
		bool swapped = false;
		for(i = left;i < right;i++)
			if(dest[i + 1] < dest[i])
			{
				int temp = dest[i + 1];
				dest[i + 1] = dest[i];
				dest[i] = temp;
				swapped = true;
			}
		if(!swapped)
			break;
		right--;
		swapped = false;
		for(i = right;i > left;i--)
			if(dest[i - 1] > dest[i])
			{
				int temp = dest[i - 1];
				dest[i - 1] = dest[i];
				dest[i] = temp;
				swapped = true;
			}
		if(!swapped)
			break;
		left++;
	}
//	for(i = 0;i < SIZE;i++)
//		printf("%d ",dest[i]);
	return 0;
}
