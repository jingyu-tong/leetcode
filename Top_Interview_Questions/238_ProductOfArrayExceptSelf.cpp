/*
**两个数组储存前后乘积
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        vector<int> fwd(n, 1), bwd(n, 1), ans(n);
        for (int i = 0; i < n - 1; ++i) {
            fwd[i + 1] = fwd[i] * nums[i];
        }
        for (int i = n - 1; i > 0; --i) {
            bwd[i - 1] = bwd[i] * nums[i];
        }
        for (int i = 0; i < n; ++i) {
            ans[i] = fwd[i] * bwd[i];
        }        
        return ans;
    }
};
/*
**直接用ans储存
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        vector<int> ans(n, 1);
        int right = 1;
        for (int i = 0; i < n - 1; ++i) {
            ans[i + 1] = ans[i] * nums[i];
        }
        for (int i = n - 1; i >= 0; --i) {
            ans[i] = ans[i] * right;
            right *= nums[i];
        }        
        return ans;
    }
};