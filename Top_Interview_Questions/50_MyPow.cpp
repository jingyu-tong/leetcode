/*
**直接根据定义，TLE 291/304
*/
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        
        x = n > 0 ? x : 1 / x;
        n = abs(n);
        
        for(int i = 0; i < abs(n); ++i) {
            ans *= x;
        }
        
        return ans;
    }
};
/*
**改用二分法，a^x = a^(x / 2)*a^(x / 2) 4ms
*/
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        
        double part = myPow(x, n / 2);
        
        if(n % 2 == 0) return part * part;
        if(n > 0) return part * part * x;//奇数，两个n/2加起来少一个x
        return part * part / x; //负数奇数，除x
    }
};
