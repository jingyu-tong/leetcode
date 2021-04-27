class Solution {
    public int jump(int[] nums) {
        int step = 0;
        int end = 0;
        int maxpoint = 0;
        for (int i = 0; i < nums.length - 1; ++i) {
            maxpoint = Math.max(maxpoint, i + nums[i]);
            if (i == end) {
                end = maxpoint;
                ++step;
            }
        }
        return step;
    }
}
