不使用/或者*，并且复杂度为对数级的正整数除法算法:

```

int divide(int numerator, int denominator) {
    if (denominator == 0) return -1; // 错误处理
    if (numerator == 0) return 0;

    // 处理符号
    int sign = (numerator > 0) ^ (denominator > 0) ? -1 : 1;
    long long a = llabs((long long)numerator);
    long long b = llabs((long long)denominator);

    long long quotient = 0;

    // 外层循环：从最高位开始试
    for (int i = 31; i >= 0; i--) {
        if ((b << i) <= a) {
            a -= (b << i);
            quotient |= (1LL << i);
        }
    }
    return (int)(sign * quotient);
  }

```

可以类比十进制除法的竖式运算
