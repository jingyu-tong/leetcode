/*
**二分
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }

private:
    int binarySearch(vector<int>& nums, int left, int right, int target) {
        if (left > right) return -1;
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;

        if (nums[mid] < nums[right]) {
            if (nums[mid] < target && nums[right] >= target)
                return binarySearch(nums, mid + 1, right, target);
            else
                return binarySearch(nums, left, mid - 1, target);
        } else {
            if (nums[left] <= target && nums[mid] > target)
                return binarySearch(nums, left, mid - 1, target);
            else
                return binarySearch(nums, mid + 1, right, target);
        }
    }
};

// iteration
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;

        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (target == nums[mid]) return mid;
            if (nums[mid] > nums[right - 1]) {  // left part
                if (target < nums[mid] && target >= nums[left]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[right - 1]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
        }
        return -1;
    }
};