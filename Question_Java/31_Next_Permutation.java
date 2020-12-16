class Solution {
    public void nextPermutation(int[] nums) {
        if (nums.length <= 1)
            return;
        for (int i = nums.length - 1; i > 0; --i) {
            if (nums[i] > nums[i - 1]) {
                int j = nums.length - 1;
                for (j = nums.length - 1; j >= i; --j) {
                    if (nums[j] > nums[i - 1])
                        break;
                }
                swap(nums, i - 1, j);
                reverse(nums, i, nums.length - 1);
                return;
            }
        }
        reverse(nums, 0, nums.length - 1);
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    private void reverse(int[] nums, int i, int j) {
        while (i < j) {
            swap(nums, i++, j--);
        }
    }
}