/*
**recursion with memorization
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0;
        const int n = nums.size();
        mem_ = vector<int>(n, 0);
        for(int i = 0; i < n; ++i) {
            ans = max(ans, LIS(nums, i));
        }
        return ans;
    }
private:
    vector<int> mem_;
    int LIS(vector<int>& nums, int cur) {
        if(cur == 0) return 1;
        if(mem_[cur] > 0) return mem_[cur];
        int ans = 1;
        for(int i = 0; i < cur; ++i) {
            if(nums[cur] > nums[i]) 
                ans = max(ans, LIS(nums, i) + 1);
        }
        return mem_[cur] = ans;
    }
};
/*
**dp dp(n) = max(dp(n), dp(0 : n - 1) + 1);
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0;
        const int n = nums.size();
        vector<int> dp(n, 1);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[j] < nums[i])
                    dp[i] = max(dp[j] + 1, dp[i]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};