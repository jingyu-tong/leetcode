class Solution {
public:
    int Fibonacci(int n) {
        if(n == 0) return 0;
        if(n <= 2) return 1;
        int first = 1;
        int second = 1;
        for(int i =  3; i <= n; ++i) {
            int temp = first + second;
            first = second;
            second = temp;
        }
        return second;
    }
};