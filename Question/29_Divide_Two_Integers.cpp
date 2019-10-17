class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX; //overflow
        if(dividend == INT_MIN && divisor == 1) return INT_MIN;
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        long m = labs(dividend);
        long n = labs(divisor);
        int ans = 0;
        while(m >= n) {
            long t = n;
            long p = 1;
            while(m >= (t << 1)) {
                t <<= 1;
                p <<= 1;
            }
            ans += p;
            m -= t;
        }
        return ans * sign;
    }
};
