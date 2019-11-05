//recursion with memorization
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(auto& ele : wordDict)
            dict.insert(ele);


        return dfs(s, dict, 0);
    }
    bool dfs(string& s, unordered_set<string>& dict, int loc) {
        if(loc == s.size()) {
            return true;
        }
        for(int i = loc; i < s.size(); ++i) {
            string sub_str = s.substr(loc, i - loc + 1);
            if(dict.count(sub_str) == 0) continue;
            if(mem.count(i + 1) != 0) {
                if(mem[i + 1] == false) continue;
                if(mem[i + 1] == true) return true;
            }
            bool ans = dfs(s, dict, i + 1);
            mem[i + 1] = ans;
            if(ans == true) return ans;
        }
        return false;
    }
    unordered_map<int, bool> mem; //ind, ans
};
//dp(i) [0, i) is or not
//dp(i) = dp(j) && dict(substr(j, i))
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(auto& ele : wordDict)
            dict.insert(ele);

        const int n = s.size();
        vector<bool> dp(n + 1, false); //[0, i) is valid
        dp[0] = true;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < i; ++j) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }

};
