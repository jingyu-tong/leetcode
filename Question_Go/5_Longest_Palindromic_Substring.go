//dp(i, j) [i, j] whether a palindrome stirng
//dp(i, j) = {1 | i == j}
//         = {s[i] == s[j] | j == i + 1}
//         = {s[i] == s[j] && dp(i + 1, j - 1)}

//go的二维数组初始化很麻烦！！！
func longestPalindrome(s string) string {
    dp := make([][]bool, len(s))
    start, length := 0, 0

    for j := 0; j < len(s); j++ {
        dp[j] = make([]bool, len(s))
        dp[j][j] = true
        for i := 0; i <= j; i++ {
            dp[i][j] = (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]));
            if dp[i][j] && length < j - i + 1 {
                start = i;
                length = j - i + 1;
            }
        } 
    }

    return s[start : start + length]
}