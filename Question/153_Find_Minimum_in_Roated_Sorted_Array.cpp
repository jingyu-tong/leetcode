class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty()) return -1;

        int left = 0;
        int right = nums.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] < nums[right])
                right = mid;
            else
                left = mid + 1;
        }
        return nums[right];
    }
};
