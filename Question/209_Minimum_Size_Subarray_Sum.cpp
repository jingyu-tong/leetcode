class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()) return 0;
        
        int left = 0;
        int right = 0;
        int sum = 0;
        const int m = nums.size();
        int ans = m + 1;
        while(right < m) {
            while(sum < s && right < m)
                sum += nums[right++];
            
            while (sum >= s) {
                ans = min(ans, right - left);
                sum -= nums[left++];
            }
        }
        
        return ans == m + 1 ? 0 : ans;
    }
};