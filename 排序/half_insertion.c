#include <stdio.h>
#define SIZE 10
#include <time.h>
#include <stdlib.h>
//’€∞Î≤Â»Î
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
	for(i = 1;i < SIZE;i++)
	{
		if(dest[i] >= dest[i - 1])
			continue;
		int temp = dest[i];
		int left = 0;
		int right = i - 1;
		while(left <= right)
		{
			int mid = left + (right - left) / 2;
			if(dest[mid] > temp)
				right = mid - 1;
			else
				left = mid + 1;
		}
		int j;
		for(j = i - 1;j >= left;j--)
			dest[j + 1] = dest[j];
		dest[left] = temp;
	}
	for(i = 0;i < SIZE;i++)
		printf("%d ",dest[i]);
	return 0;
}
