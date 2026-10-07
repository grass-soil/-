#include <stdio.h>
#define SIZE 100000
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void sift_down(int* arr,int n,int node){ //负责堆的下沉
	if(node > n)
		return;
	int larger = node;
	int left = node * 2;
	int right = node * 2 + 1;
	if(left <= n && arr[node] < arr[left])
		larger = left;
	if(right <= n && arr[larger] < arr[right])
		larger = right;
	if(larger != node)
	{
		swap(arr + larger,arr + node);
		sift_down(arr,n,larger);
	}
}
int main(void)
{
	int i;
	srand((unsigned)time(0));
	int dest[SIZE + 1];
	for(i = 1;i <= SIZE;i++)
		dest[i] = rand() % SIZE + 1;
	for(i = 1;i <= SIZE;i++)
		printf("%d ",dest[i]);
	putchar('\n');
	for(i = SIZE / 2;i >= 1;i--) //建堆 
		sift_down(dest,SIZE,i);
	for(i = SIZE;i >= 1;i--) //排序 
	{
		swap(dest + 1,dest + i);
		sift_down(dest,i - 1,1);
	}
	for(i = 1;i <= SIZE;i++)
		printf("%d ",dest[i]);
	return 0;
}
