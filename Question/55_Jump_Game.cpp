class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty()) return true;
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];

        for(int i = 1; i < nums.size(); ++i) {
            dp[i] = max(nums[i - 1], dp[i - 1]) - 1;
            if(dp[i] < 0)
                return false;
        }
        return true;
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty()) return true;
        int reach = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if (i > reach || reach >= nums.size() - 1) break;
            reach = max(reach, i + nums[i]);
        }
        return reach >= nums.size() - 1;
    }
};
