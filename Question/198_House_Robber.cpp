class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;

        const int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        if(n == 1) return dp.back();
        dp[1] = max(nums[0], nums[1]);
        if(n == 2) return dp.back();
        for(int i = 2; i < n; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp.back();
    }
};
