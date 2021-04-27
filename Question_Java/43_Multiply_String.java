class Solution {
    public String multiply(String num1, String num2) {
        final int m = num1.length();
        final int n = num2.length();
        int[] nums = new int[m + n];
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int num = num1.charAt(i) - '0';
                num *= num2.charAt(j) - '0';
                num += nums[i + j + 1];
                nums[i + j + 1] = num % 10;
                nums[i + j] += num / 10;
            }
        }

        StringBuilder ans = new StringBuilder();
        for (int num : nums) {
            if (ans.length() != 0 || num != 0)
                ans.append(num);
        }
        return ans.length() == 0 ? "0" : ans.toString();
    }
}