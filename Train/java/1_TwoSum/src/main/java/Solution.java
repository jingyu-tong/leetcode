import java.util.HashMap;

public class Solution {
    public static int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> mem = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            if (mem.containsKey(target - nums[i]))
                //if (mem.get(target - nums[i]) != null)
                return new int[]{i, mem.get(target - nums[i])};
            mem.put(nums[i], i);
        }
        return new int[]{-1, -1};
    }
}
