class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        
        return max(mineRob(nums, 0, nums.size() - 1), mineRob(nums, 1, nums.size()));
    }
private:
    int mineRob(vector<int>& nums, int begin, int end) {
        const int n = end - begin + 1;
        if(n <= 1) return nums[begin];
        
        vector<int> dp(n, 0);
        dp[0] = 0;
        dp[1] = nums[begin];
        for(int i = 2; i < n; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i + begin - 1]);
        }
        return dp.back();
    }
};