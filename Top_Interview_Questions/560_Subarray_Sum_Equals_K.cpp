class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int ans = 0;
        unordered_map<int, int> mem{{0, 1}};  // sum, count
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            ans += mem[sum - k];
            mem[sum]++;
        }
        return ans;
    }
};