// recursion TLE
class Solution {
public:
    bool isMatch(string s, string p) { return isMatch(s, p, 0, 0); }
    bool isMatch(string& s, string& p, int i, int j) {
        if (i == s.size() && j == p.size()) return true;
        if (j == p.size()) return false;
        if (i == s.size()) {  // 看后续p是否是*
            while (p[j] == '*') ++j;
            return (j == p.size());
        }

        if (s[i] == p[j] || p[j] == '?') return isMatch(s, p, i + 1, j + 1);
        if (p[j] == '*')
            return isMatch(s, p, i, j + 1) ||
                   isMatch(s, p, i + 1, j);  // 匹配0个 匹配任意个
        return false;
    }
};

// 记忆化递归
class Solution {
public:
    bool isMatch(string s, string p) {
        m = s.size() + 1;
        return isMatch(s, p, 0, 0);
    }
    bool isMatch(string& s, string& p, int i, int j) {
        if (mem_.count(i * m + j)) return mem_[i * m + j];
        if (i == s.size() && j == p.size()) return mem_[i * m + j] = true;
        if (j == p.size()) return mem_[i * m + j] = false;
        if (i == s.size()) {  // 看后续p是否是*
            while (p[j] == '*') ++j;
            return mem_[i * m + j] = (j == p.size());
        }

        if (s[i] == p[j] || p[j] == '?')
            return mem_[i * m + j] = isMatch(s, p, i + 1, j + 1);
        if (p[j] == '*')
            return mem_[i * m + j] =
                       isMatch(s, p, i, j + 1) ||
                       isMatch(s, p, i + 1, j);  // 匹配0个 匹配任意个
        return mem_[i * m + j] = false;
    }

private:
    unordered_map<int, bool> mem_;
    int m;
};

class Solution {
public:
    bool isMatch(string s, string p) {
        const int m = s.size();
        const int n = p.size();
        vector<vector<int>> dp(
            m + 1,
            vector<int>(n + 1));  // dp(i, j) means s(0:i) matches p(0, j)

        // dp(0, 0) = 1;
        // dp(i, j) -> x
        // 1. (s[i - 1] == p[j - 1] || p[j - 1] == '?'),  x = dp(i - 1, j - 1)
        // 2. p[j - 1] == '*', x = dp(i - 1, j) || dp(i, j - 1) 匹配0 个 or n 个
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            if (p[i - 1] == '*' && dp[0][i - 1]) dp[0][i] = 1;
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];  // 配0个，or 多个
                }
            }
        }
        return dp[m][n];
    }
};
