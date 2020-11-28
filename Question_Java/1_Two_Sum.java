class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> mem = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            if (mem.containsKey(target - nums[i])) {
                return new int[]{i, mem.get(target - nums[i])};
            }
            mem.put(nums[i], i);
        }
        return new int[]{-1, -1};
    }
}