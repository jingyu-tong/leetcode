/*
**直接减，TLE
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long long m = llabs((long long)dividend);
        long long n = llabs((long long)divisor);

        int ans = 0;
        while (m >= n) {
            m -= n;
            ++ans;
        }
        return sign * ans;
    }
};
/*
**用位移加速
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long long m = llabs((long long)dividend);
        long long n = llabs((long long)divisor);

        int ans = 0;
        while (m >= n) {
            long long t = n, p = 1;
            while (m >= (t << 1)) {
                t <<= 1;
                p <<= 1;
            }
            m -= t;
            ans += p;
        }
        return sign * ans;
    }
};

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        unsigned int m = abs(dividend);
        unsigned int n =
            abs(divisor);  // 这里用 unsigned int，可以避免用 long 超出长度

        int ans = 0;
        while (m >= n) {
            long long t = n, p = 1;
            while (m >= (t << 1)) {
                t <<= 1;
                p <<= 1;
            }
            m -= t;
            ans += p;
        }
        return sign * ans;
    }
};