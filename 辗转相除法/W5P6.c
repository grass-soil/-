#include <stdio.h>
int main(void)
{
	int i;
	int j;
	int k;
	int ia;
	int ja;
	
	scanf("%d/%d",&i,&j);
	ia = i;
	ja = j;
	while(ia%ja !=0)
	{
		k = ja;
		ja= ia%ja;
		ia = k;
	}
	printf("%d/%d",i/ja,j/ja);
	return 0;
} 
