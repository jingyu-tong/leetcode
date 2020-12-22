class Solution {
    public int[] searchRange(int[] nums, int target) {
        if (nums.length == 0) return new int[]{-1, -1};

        int begin = search(nums, target, false);
        if (begin >= nums.length || nums[begin] != target) return new int[]{-1, -1};
        int end = search(nums, target, true);
        return new int[]{begin, end - 1};
    }
    private int search(int[] nums, int target, boolean begin) {
        int left = 0;
        int right = nums.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if ( (begin && nums[mid] > target) || (!begin && nums[mid] >= target)) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
}