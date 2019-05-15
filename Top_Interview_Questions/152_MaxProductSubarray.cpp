/*
**dp储存最大最小乘积，使用第n个元素最大值一定在 nums[n], num[n]*max, nums[n]*min产生
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int n = nums.size();
        int ans = nums[0];
        vector<int> max_ans(n, 0);
        vector<int> min_ans(n, 0);
        max_ans[0] = nums[0];
        min_ans[0] = nums[0];
        for(int i = 1; i < n; ++i) {
            max_ans[i] = max(nums[i], max(max_ans[i - 1] * nums[i], min_ans[i - 1] * nums[i]));
            min_ans[i] = min(nums[i], min(max_ans[i - 1] * nums[i], min_ans[i - 1] * nums[i]));
            ans = max(ans, max_ans[i]);
        }
        return ans;
    }
};
/*
**使用两个变量即可
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int n = nums.size();
        int ans = nums[0];
        int max_ans = nums[0];
        int min_ans = nums[0];
        for(int i = 1; i < n; ++i) {
            int last_max = max_ans;
            int last_min = min_ans;
            max_ans = max(nums[i], max(last_max * nums[i], last_min * nums[i]));
            min_ans = min(nums[i], min(last_max * nums[i], last_min * nums[i]));
            ans = max(ans, max_ans);
        }
        return ans;
    }
};
