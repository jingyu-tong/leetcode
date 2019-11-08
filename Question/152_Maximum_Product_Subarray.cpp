class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int m = nums.size();
        //最大乘大
        //最小乘小 also might be the result
        vector<int> maxdp(m);
        vector<int> mindp(m);
        maxdp[0] = nums[0];
        mindp[0] = nums[0];
        for(int i = 1; i < m; ++i) {
            int tempmax = max(maxdp[i - 1] * nums[i], mindp[i - 1] * nums[i]);
            int tempmin = min(maxdp[i - 1] * nums[i], mindp[i - 1] * nums[i]);
            maxdp[i] = tempmax > maxdp[i] ? tempmax : nums[i];
            mindp[i] = tempmin < mindp[i] ? tempmin : nums[i];

        }
        return *max_element(maxdp.begin(), maxdp.end());
    }
};
