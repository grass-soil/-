#include <stdio.h>
#define SIZE 100000
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
void quick_sort(int arr[],int left,int right){
	if(left >= right)
		return;
	int num = left + rand() % (right - left + 1);
	int temp = arr[num];
	arr[num] = arr[left];
	arr[left] = temp;
	int i = left;
	int j = right;
	int pivot = arr[left];
	while(i < j)
	{
		while(j > i && arr[j] >= pivot) j--;
		arr[i] = arr[j];
		while(i < j && arr[i] <= pivot) i++;
		arr[j] = arr[i];
	}
	arr[i] = pivot;
	quick_sort(arr,left,i - 1);
	quick_sort(arr,i + 1,right);
}
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
	quick_sort(dest,0,SIZE - 1);
//	for(i = 0;i < SIZE;i++)
//		printf("%d ",dest[i]);
	return 0;
}
