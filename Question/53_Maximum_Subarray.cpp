class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            dp[i] = dp[i - 1] <= 0 ? nums[i] : nums[i] + dp[i - 1];
        }
        return *max_element(dp.begin(), dp.end());
    }
};
