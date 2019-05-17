/*
**按不同起点划分为多段，分别赋值
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.empty() || (k % nums.size()) == 0) return;
        int n = nums.size();
        int start = 0, pre = 0, cur = nums[0], idx = 0;
        for(int i = 0; i < n; ++i) {
            pre = cur;
            idx = (idx + k) % n;
            cur = nums[idx];
            nums[idx] = pre;
            if(idx == start) {  //绕了一圈，该周期结束，前往下一个 
                idx = ++start;
                cur = nums[idx];
            }
        }
    }
};
/*
**将前n - k个和后k个分别翻转后，再翻转
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty() || (k %= nums.size()) == 0) return;
        int n = nums.size();
        reverse(nums.begin(), nums.begin() + n - k);
        reverse(nums.begin() + n - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};