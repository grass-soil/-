#include <stdio.h>
#define SIZE 100
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
//基数为10 
typedef struct node{
	int num;
	struct node* next;
} NODE;
void append(NODE** head,NODE** tail,NODE* node){ //增长链表（将新元素链接到链表末尾）
	node -> next = NULL;
	if(*head == NULL)
	{
		*head = node;
		*tail = node;
	}else
	{
		(*tail) -> next = node;
		*tail = node;
	}
}
int main(void)
{
	int i;
	srand((unsigned)time(0));
	int dest[SIZE];
	for(i = 0;i < SIZE;i++)
		dest[i] = rand() % INT_MAX + 1;
	for(i = 0;i < SIZE;i++)
		printf("%d ",dest[i]);
	putchar('\n');
	int max = 0;
	for(i = 0;i < SIZE;i++)
		if(dest[i] > max)
			max = dest[i];
	//创建链表
	NODE* head = NULL;
	NODE* tail = NULL;
	for(i = 0;i < SIZE;i++)
	{
		NODE* newnode = (NODE*)malloc(sizeof(NODE));
		newnode -> num = dest[i];
		append(&head,&tail,newnode);
	}
	NODE* newhead = NULL;
	tail = NULL;
	//基数排序主体 
	for(i = 1;i < max;i *= 10)
	{
		NODE* bucket_head[10] = {NULL}; //链表队列 
		NODE* bucket_tail[10] = {NULL};
		NODE* curr = head;
		while(curr != NULL) //入桶 
		{
			NODE* next_node = curr -> next;
			int digit_num = (curr -> num) / i % 10;
			append(bucket_head + digit_num,bucket_tail + digit_num,curr);
			curr = next_node;
		}
		//出桶
		int j;
		for(j = 0;j < 10;j++)
		{
			if(bucket_head[j] == NULL)
				continue;
			if(newhead == NULL)
				newhead = bucket_head[j];	
			else
				tail -> next = bucket_head[j];
			tail = bucket_tail[j];
		}
		head = newhead;
		newhead = NULL;
		tail = NULL;
	}
	//链表拷贝到数组
	NODE* curr = head;
	for(i = 0;i < SIZE;i++)
	{
		dest[i] = curr -> num;
		curr = curr -> next;
	}
	//销毁链表
	curr = head;
	while(curr != NULL)
	{
		NODE* next_node = curr -> next;
		free(curr);
		curr = next_node;
	}
	for(i = 0;i < SIZE;i++)
		printf("%d ",dest[i]);
	return 0;
}
