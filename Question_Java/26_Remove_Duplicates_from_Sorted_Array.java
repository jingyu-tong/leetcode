class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums.length <= 1) return nums.length;
        int cur = 0;
        for (int i = 1; i < nums.length; ++i) {
            if (nums[i] == nums[cur]) continue;
            nums[++cur] = nums[i];
        }
        return cur + 1;
    }
}