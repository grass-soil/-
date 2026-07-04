#include <stdio.h>
int to_base_n(int num,int dig);
int main(void)
{
	printf("   %d",to_base_n(1128,9));
	return 0;
}

int to_base_n(int num,int dig)
{
	int rest;
	
	if(dig <2 || dig >10)
	{
		return -1;
	}else if(num < 0)
	{
		putchar('-');
		to_base_n(-num,dig);//点睛之笔，不在当前帧修改num，而将num的变化值交给下一帧 
		return 0;
	}
	rest = num % dig;
	if(num >= dig)//终止条件变量，比如这里的num，在递归函数的函数体中不能变化，这样才能保持递归《最贴近数学函数》的本色。 
		to_base_n(num/dig,dig);//仅在再次调用时变化 
	putchar('0'+rest);//putchar的高端应用! 
	return 0;
}
/*
“递归的终止条件所依赖的变量，
在当前函数体内不仅不能作为左值被赋值，
甚至不应该被任何运算语句改变其数值。如果数据形态需要变化（如负转正），
应通过创建新的递归调用分支（新帧）来实现，而非在当前帧‘原地改造’。”

递归：其本质是“递推关系”。每一层递归都应该是独立的、封闭的计算单元。这一层的输入参数一旦确定，在函数体内就应该像刻在石碑上的数字一样永恒不变。
“递归函数体内，终止条件变量必须只读。这不是为了性能，而是为了让代码像数学公式一样严密，让后来者（包括未来的自己）不用废任何脑细胞去推测变量的当前值。”
*/
