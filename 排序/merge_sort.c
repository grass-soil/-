#include <stdio.h>
#define SIZE 10
#include <time.h>
#include <stdlib.h>
#include <string.h>
//由于空间复杂度有点高 O(n)，所以不妨用malloc
void merge_sort(int* arr,int left,int right){
	if(left >= right)
		return;
	int mid = left + (right - left) / 2;
	merge_sort(arr,left,mid);
	merge_sort(arr,mid + 1,right);
	int size = right - left + 1;
	int* temp = malloc(size * sizeof(int));
	int i = left;
	int j = mid + 1;
	int k = 0;
	while(i <= mid && j <= right)
		if(arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	while(i <= mid)
		temp[k++] = arr[i++];
	while(j <= right)
		temp[k++] = arr[j++];
	memcpy(arr + left,temp,sizeof(int) * size);
	free(temp);
}
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
	merge_sort(dest,0,SIZE - 1);
	for(i = 0;i < SIZE;i++)
		printf("%d ",dest[i]);
	return 0;
}
