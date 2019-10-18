class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1, -1};
        int left = binarySearchLeft(nums, target, 0, nums.size());
        if(left >= nums.size() || nums[left] != target)
            return {-1, -1};
        int right = binarySearchRight(nums, target, left, nums.size());
        return {left, right};
    }
    int binarySearchLeft(vector<int>& nums, int& target, int left, int right) {
        if(left >= right) return left;

        int mid = (right - left) / 2 + left;
        int ans = 0;
        if(nums[mid] < target) {
            ans = binarySearchLeft(nums, target, mid + 1, right);
        } else {
            ans = binarySearchLeft(nums, target, left, mid);
        }
        return ans;
    }
    int binarySearchRight(vector<int>& nums, int& target, int left, int right) {
        if(left >= right) return left - 1;

        int mid = (right - left) / 2 + left;
        if(nums[mid] <= target) {
            return binarySearchRight(nums, target, mid + 1, right);
        } else {
            return binarySearchRight(nums, target, left, mid);
        }

    }
};
