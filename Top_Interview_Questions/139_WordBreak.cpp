/*
**recursion with memorization
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto i : wordDict) 
            dict.insert(i);
        
        return wordBreak(s, 0);
    }
private:
    unordered_set<string> dict;
    unordered_map<string, bool> mem_;
    bool wordBreak(string s, int part) {
        if(part > s.size()) return false;
        if(part == s.size()) return inDict(s);
        
        if(mem_.count(s)) return mem_[s];
        
        string s_left = s.substr(0, part);
        string s_right = s.substr(part);
        
        mem_[s_left] = wordBreak(s_left, 0);
        bool ans_now = mem_[s_left] && inDict(s_right);
        
        return ans_now || wordBreak(s, part + 1);
    }
    bool inDict(const string& s) {
        return dict.count(s) != 0;
    }
};
/*
**dp
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        for(auto i : wordDict) 
            dict.insert(i);
        vector<int> dp(s.size() + 1, false);
        dp[0] = true;
        
        for(int i = 1; i < dp.size(); ++i) {
            for(int j = 0; j < i; ++j) {
                if(dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
}