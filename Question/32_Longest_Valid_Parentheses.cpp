class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> mem;
        int left = 0;
        int ans = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(') {
                mem.push(i);
            } else {
                if(mem.empty()) {
                    left = i + 1;
                } else {
                    mem.pop();
                    if(mem.empty()) {
                        ans = max(ans, i - left + 1);
                    } else {
                        ans = max(ans, i - mem.top());
                    }
                }
            }
        }
        return ans;
    }
};

//dp
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int ans = 0;
        vector<int> dp(n + 1, 0);
        for(int i = 1; i < n + 1; ++i) {
            if(s[i - 1] == ')') {
                int j = i - 2 - dp[i - 1];
                if(j >= 0 && s[j] == '(') {
                    dp[i] = dp[i - 1] + 2 + dp[j];
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
};i
