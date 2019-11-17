class Solution {
public:
    int jumpFloor(int number) {
        if(number < 1) return 0;
        if(number == 1) return 1;
        vector<int> dp(number + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= number; ++i) {
            dp[i] = dp[i -  1] + dp[i - 2];
        }
        return dp.back();
    }
};
// 降维
class Solution {
public:
    int jumpFloor(int number) {
        if(number < 1) return 0;
        if(number == 1) return 1;
        int pre = 1;
        int ans = 1;
        for(int i = 2; i <= number; ++i) {
            int temp = ans;
            ans =  ans + pre;
            pre = temp;
        }
        return ans;
    }
};