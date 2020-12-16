class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int diff = Integer.MAX_VALUE;
        int ans = 0;
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 2; ++i) {
            int left = i + 1;
            int right = nums.length - 1;
            while (left < right) {
                int sum = nums[left] + nums[right] + nums[i];
                if (sum == target) {
                    return target;
                } else if (sum < target) {
                    if (Math.abs(target - sum) < diff) {
                        diff = Math.abs(target - sum);
                        ans = sum;
                    }
                    ++left;
                } else {
                    if (Math.abs(target - sum) < diff) {
                        diff = Math.abs(target - sum);
                        ans = sum;
                    }
                    --right;
                }
            }
        }
        return ans;
    }
}