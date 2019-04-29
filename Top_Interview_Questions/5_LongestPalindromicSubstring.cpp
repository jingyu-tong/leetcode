/*
**recursion TLE
*/
class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        longestPalindrome(s, 0, 0, ans);
        return ans;
    }
private:
    void longestPalindrome(string s, int begin, int loc, string& ans) {
        if(loc > s.size()) {
            return;
        }
        string cur = s.substr(begin, loc);
        if(isPalindromic(cur) && cur.size() > ans.size())
            ans = cur;
        
        for(int i = loc + 1; i <= s.size(); ++i) {
            longestPalindrome(s, begin, i, ans);
        }
        
        longestPalindrome(s, begin + 1, begin + 1, ans);
    }
    bool isPalindromic(const string& s) {
        int left = 0, right = s.size() - 1;
        while(left < right) {
            if(s[left] != s[right])
                return false;
            ++left; --right;
        }
        return true;
    }
};
/*
**DP  dp(i, j) [i,j] is a palindromic
*	  dp(i, j) = dp(i + 1, j - 1) && s[i] == s[j]
*/
class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
           
        int left = 0, right = 0, len = 0;
        for(int i = 0; i < n; ++i) {
            dp[i][i] = 1;
            for(int j = 0; j < i; ++j) {
                dp[j][i] = (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1]));
                if(dp[j][i] && len < i - j + 1) {
                    left = j;
                    right = i;
                    len = i - j + 1;
                }
            }
        }
        
        return s.substr(left, right - left + 1);
    }
};
/*
**best solution: 从中间向两边搜寻 注意，可能有中间为单独一个字母，也可能为两个
*
*/
class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.size();
        
        int start = 0, len = 0;
        for(int i = 0; i < n - 1; ++i) {
            palindrome(s, i, i, start, len);
            palindrome(s, i, i + 1, start, len);
        }
        return s.substr(start, len);
    }
private:
    void palindrome(string& s, int left, int right, int& start, int& len) {
        while(left >=0 && right < s.size() && s[left] == s[right]) {
            --left; ++right;
        }
        if(len < right - left - 1) {
            start = left + 1;
            len = right - left - 1;
        }
    }
};
};

