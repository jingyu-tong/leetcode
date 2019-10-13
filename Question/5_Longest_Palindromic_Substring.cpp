class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int len = 0;
        for(int i = 0; i < s.size(); ++i) {
            palindrome(s, i, i, start, len);
            palindrome(s, i, i + 1, start, len);
        }
        return s.substr(start, len);
    }
    //find the palindrome substring from left and right
    void palindrome(string& s, int left, int right, int& start, int& len) {
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        if(len < right - left - 1) {
            len = right - left - 1;
            start = left + 1;
        }
    }
};
//dp(i, j) [i, j] whether a palindrome stirng
//dp(i, j) = {1 | i == j}
//         = {s[i] == s[j] | j == i + 1}
//         = {s[i] == s[j] && dp(i + 1, j - 1)}
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0 || s.size() == 1)
            return s;
        int start = 0;
        int len = 0;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        //int dp[s.size()][s.size()];
        for(int j = 0; j < s.size(); ++j) {
            dp[j][j] = 1;
            for(int i = 0; i <= j; ++i) {
                dp[i][j] = (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]));
                if(dp[i][j] && len < j - i + 1) {
                    start = i;
                    len = j - i + 1;
                }
            }
        }

        return s.substr(start, len);
    }
};
