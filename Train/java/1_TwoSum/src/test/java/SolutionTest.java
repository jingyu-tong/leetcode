import org.junit.Test;

import java.util.Arrays;

import static org.junit.Assert.*;
public class SolutionTest {
    @Test
    public void twoSumTest() {
        int[] nums = {2,7,11,15};
        int target = 9;
        int[] output1 = {0, 1};
        int[] output2 = {1, 0};
        assertTrue(Arrays.equals(output1, Solution.twoSum(nums, target)) ||
                    Arrays.equals(output2, Solution.twoSum(nums, target)));
    }
}
