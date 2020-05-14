// 分两部分考虑：
// 1. 异或就是二进制累加，但是不带进位
// 2. 进位可以通过&操作进行判断
// 这里需要理解计算机中，不存在正负数的其实，都是补码相加
class Solution {
public:
    int getSum(int a, int b) {
        if (!(a & b)) return a ^ b;
        return getSum(a ^ b, ((unsigned int)(a & b)) << 1);
    }
};