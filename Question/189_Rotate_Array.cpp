class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.empty() || (k % nums.size() == 0)) return;
        int n = k % nums.size();
        reverse(nums.begin(), nums.end() - n);
        reverse(nums.end() - n, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
