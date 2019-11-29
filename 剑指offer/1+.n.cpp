class Solution {
public:
    int Sum_Solution(int n) {
        int ans = n;
        ans && (ans += Sum_Solution(n - 1)); //利用短路特性，ans为0时不求解
        return ans;
    }
};