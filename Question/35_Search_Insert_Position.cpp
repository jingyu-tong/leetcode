class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = binarySearch(nums, target, 0, nums.size());
        return left;
    }
    int binarySearch(vector<int>& nums, int target, int left, int right) {
        if(left >= right) return left;

        int mid = (right - left) / 2 + left;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) return binarySearch(nums, target, mid + 1, right);
        else return binarySearch(nums, target, left, mid);
    }
};
