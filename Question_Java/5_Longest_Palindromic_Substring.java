class Solution {
    public String longestPalindrome(String s) {
        if (s.length() <= 1)
            return s;

        boolean[][] dp = new boolean[1001][1001];
        int len = 0;
        int start = 0;
        for (int i = 0; i < s.length(); ++i) {
            for (int j = 0; j <= i; ++j) {
                dp[j][i] = i - j < 2 ? s.charAt(i) == s.charAt(j) : s.charAt(i) == s.charAt(j) && dp[j + 1][i - 1];
                if (dp[j][i] && i - j + 1 > len) {
                    len = i - j + 1;
                    start = j;
                }
            }
        }
        return s.substring(start, start + len);
    }
}

// 使用 String 调用，效率比较低，可以利用 string 的 toCharArray 转换为 char[]