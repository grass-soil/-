就是将已经计算的结果存储起来，方便下次快速使用。  <dir>
实现：可以考虑采用unordered_map，递归来设计缓存。
```
#include <iostream>
#include <unordered_map>
#include <algorithm> // for min, max

using namespace std;

// 使用 unordered_map 来存储已经计算过的数字的周期长度  * ! *
unordered_map<long long, int> memo; //缓存

// 计算一个数字 n 的周期长度
int getCycleLength(long long n) {
    // 如果 n 是 1，周期长度为 1（序列只包含 1 自身）
    if (n == 1) {
        return 1;
    }

    // 如果 n 已经计算过，直接返回缓存的结果
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }

    // 否则，根据规则计算下一个数，并递归计算其周期长度
    long long next;
    if (n % 2 == 1) {
        next = 3 * n + 1;
    } else {
        next = n / 2;
    }

    // 当前 n 的周期长度 = 1 (n 自身) + 下一个数的周期长度
    int length = getCycleLength(next) + 1;

    // 将计算结果存入缓存，以便复用
    memo[n] = length;

    return length;
}

int main() {
    int i, j;
    // 循环读取输入，直到文件结束
    while (cin >> i >> j) {
        // 确定需要计算的区间范围
        int left = min(i, j);
        int right = max(i, j);

        int maxLength = 0;
        // 遍历区间内的每一个整数
        for (int k = left; k <= right; k++) {
            // 计算当前数字的周期长度，并更新最大值
            maxLength = max(maxLength, getCycleLength(k));
        }

        // 输出结果：注意 i 和 j 要保持输入时的顺序
        cout << i << " " << j << " " << maxLength << endl;
    }
    return 0;
}
```
