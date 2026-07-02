# 辗转相除法
1. **应用场景** 
求两个数字的最大公约数等。
2. **具体方法**
初始化变量a,b分别为待求取最大公约数的两个数。<br>
然后循环执行：
- 检测(a%b为0)？
- 如果为真，则终止循环，**最大公约数即为b**；如果为假，则继续：
- 将b的值赋给a，将(a%b)的值赋给b,返回到循环最初的检测条件。
3. **C的实现**
```
/*
实现分数化简，最终结果是一个最简分数，包括分母为一的情况
*/
#include <stdio.h>
int main(void)
{
	int i; 
	int j;
	int k;//中间变量，负责在ja和ia间传递数据
	int ia;
	int ja;
	
	scanf("%d/%d",&i,&j);
    //求i与j的最大公约数
	ia = i;
	ja = j;
	while(ia%ja !=0)
	{
		k = ja;
		ja= ia%ja;
		ia = k;
	}
    //求得其为ja
	printf("%d/%d",i/ja,j/ja);//约分并输出
	return 0;
} 
```
4. **数学证明**
我们不妨设两个自然数a b的最大公约数为 $gcd(a,b)$,<br>
设<br>
$a\div b = c \cdots d$ <br>
欲证明辗转相除法，只需证明 $gcd(a,b) = gcd(b,d)$ 即可(之后可以使用该定理进行迭代，直到求出最大公约数为止，或者说，当d等于0时，我们稍后详细讨论一下)<br>
设 $a,b$公约数的集合为 $A$ <br>
设 $b,d$ 公约数的集合为 $B$ <br>
设 $f$ 是 $a,b$的一个公约数，则 $f|a ， f|b ，d = a-cb$ <br>
因为 $f|a ∧f|b$ <br>
所以 $f|(a-cb)$,即 $f|d$ <br>
因为 $f|b$ <br>
所以 $A \subseteq B$ <br>
同理 <br>
设 $g$ 是 $b,d$ 的一个公约数，那么根据 $a=d+cb$ ,可得 $g|a$ <br>
因为 $g|b$ <br>
所以 $B \subseteq A$ <br>
即 $A = B$ <br>
所以 $gcd(a,b) = gcd(b,d)$ <br>
接下来迭代：<br>
由于余数小于除数，所以每一轮迭代，会使得 $(a,b)$ 中的 $b$ 不断减小，一定会减小到零. <br>