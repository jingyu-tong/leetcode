class Solution {
public:
    int numDistinct(string s, string t) {
        const int ls = s.size();
        const int lt = t.size();

        vector<vector<unsigned int>> dp(lt + 1, vector<unsigned int>(ls + 1));

        for(auto& ele : dp[0])
            ele = 1;

        for(int i = 1; i <= lt; ++i) {
            for(int j = 1; j <= ls; ++j) {
                if(s[j - 1] == t[i - 1]) {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
                } else
                    dp[i][j] = dp[i][j - 1];
            }
        }
        return dp[lt][ls];
    }
};
