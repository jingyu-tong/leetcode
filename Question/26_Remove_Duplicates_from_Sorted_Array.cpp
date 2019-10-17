class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans = nums.size();
        if(ans <=1) return ans;
        int left = 0;
        int right = 1;
        while(right < nums.size()) {
            if(nums[left] == nums[right]) {
                ++right;
                --ans;
            }
            else
                nums[++left] = nums[right++];
        }
        return ans;
    }
};
