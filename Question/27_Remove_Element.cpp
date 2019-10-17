class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) return 0;
        int left = 0;
        int right = 0;
        while(right < nums.size()) {
            if(nums[right] == val) {
                ++right;
            } else {
                nums[left++] = nums[right++];
            }
        }
        return left;
    }
};
