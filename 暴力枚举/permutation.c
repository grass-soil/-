#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define SIZE 5
void merge_sort(int* arr,int left,int right){
	if(left >= right)
		return;
	int mid = left + (right - left) / 2;
	merge_sort(arr,left,mid);
	merge_sort(arr,mid + 1,right);
	int size = right - left + 1;
	int* temp = (int*)malloc(sizeof(int) * size);
	int i = left;
	int j = mid + 1;
	int k = 0;
	while(i <= mid && j <= right)
	{
		if(arr[i] > arr[j])
			temp[k++] = arr[j++];
		else
			temp[k++] = arr[i++];
	}
	while(i <= mid)
		temp[k++] = arr[i++];
	while(j <= right)
		temp[k++] = arr[j++];
	memcpy(arr + left,temp,sizeof(int) * size);
	free(temp);
}
void swap(int* a,int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main(void)
{
	int size = SIZE;
	int arr[] = {1,2,3,4,5};
	srand(time(0));
//	for(int i = 0;i < size;i++)
//		arr[i] = rand() % SIZE + 1;
	merge_sort(arr,0,size - 1);
	while(true)
	{
		for(int j = 0;j < size;j++)
			printf("%d ",arr[j]);
		putchar('\n');
		int i = size - 2;
		while(i >= 0 && arr[i] >= arr[i+1])
			i--; 
		if(i < 0)
			break;
		int j = size -1;
		while(j > i && arr[j] <= arr[i])
			j--;
		if(j == i)
			continue;
		swap(arr + i,arr + j);
		int first = i;
		int last = size;
		while((++first) < (--last))
			swap(arr + first,arr + last);
	}
	return 0;
}
