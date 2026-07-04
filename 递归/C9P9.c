#include <stdio.h>
#include <stdbool.h>
double power(double base,int pow);
int main(void)
{
	printf("%f",power(0,));
	return 0;
}

double power(double base,int pow)
{
	double num = base;
	bool enfor = true;
	
	if(0.0==base && pow<= 0)
	{
		printf("err\n");
		num = 0.0;
		enfor = false;
	}else if(pow < 0)
	{
		num = power(1/base,-pow);
	}else if(0==pow)
	{
		num = 1.0;
	}
	if(enfor&&pow>1)
	{
		num = base*power(base,pow-1);
	}
	return num;
} 
