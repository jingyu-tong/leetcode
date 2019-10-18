class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1) return;
        int i;
        int j;
        for(i = nums.size() - 1; i >=1; --i) {
            if(nums[i] > nums[i - 1]) { //begin to decrease
                for(j = nums.size() - 1; j >= i; --j) {
                    if(nums[j] > nums[i - 1])
                        break;
                }
                swap(nums[i - 1], nums[j]);
                reverse(nums.begin() + i, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};
