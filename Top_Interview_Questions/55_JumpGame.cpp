/*
**dfs, TLE 74/75
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        return dfs(nums, 0);
    }
private:
    bool dfs(vector<int>& nums, int loc) {
        if(loc >= nums.size() - 1 || nums[loc] + loc >= nums.size() - 1) 
            return true;
        bool ans = false;
        
        for(int i = 1; i <= nums[loc]; ++i) {
            ans = ans || dfs(nums, loc + i);
        }
        return ans;
    }
};
/*
**dp 20ms
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        
        for(int i = 1; i < nums.size(); ++i) {
            dp[i] = max(nums[i - 1], dp[i - 1]) - 1;
            if(dp[i] < 0) return false;
        }
        return true;
    }
};
/*
**参考了一下答案，最好的解法是Greedy Algorithm 不需要维护数组 
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), reach = 0;
        for (int i = 0; i < n; ++i) {
            if (i > reach || reach >= n - 1) break;
            reach = max(reach, i + nums[i]);
        }
        return reach >= n - 1;
    }
};