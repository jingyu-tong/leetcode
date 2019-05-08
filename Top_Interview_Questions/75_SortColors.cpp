class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, cur = 0;
        
        while(cur <= right) {
            if(nums[cur] == 0)
                swap(nums[cur++], nums[left++]);
            else if(nums[cur] == 2)
                swap(nums[cur], nums[right--]);
            else
                ++cur;
        }
    }
};