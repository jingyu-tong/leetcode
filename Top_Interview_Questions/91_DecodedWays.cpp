/*
**dfs TLE
*/
class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0) return 0;
        if(s.size() == 1) return 1 <= (s[0] - '0');
        int ans = 0;
        dfs(s, 0, ans);
        return ans;
    }
private:
    void dfs(string s, int loc, int& ans) {
        if(loc > s.size() - 1) {
            ++ans;
            return;
        }
        //1 number or two number
        int temp = s[loc] - '0';
        if(1 <= temp && temp <= 26)
            dfs(s, loc + 1, ans);
        
        if(loc <= s.size() - 2 && s[loc] != '0') {
            temp = temp * 10 + (s[loc + 1] - '0');
            if(1 <= temp && temp <= 26)
                dfs(s, loc + 2, ans);            
        }
    }
};
/*
**dp(n) = not zero ? dp(n - 1) + is valid ? dp(n - 2)
*/
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || (s.size() > 1 && s[0] == '0')) return 0;
        const int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for(int i = 1; i < dp.size(); ++i) {
            dp[i] = (s[i - 1] == '0') ? 0 : dp[i - 1];//用一个 
            if(i > 1 && s[i - 2] != '0') {
                int temp = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
                if(1 <= temp && temp <= 26)
                dp[i] += dp[i - 2];              

            }
        }
        return dp.back();
    }
};