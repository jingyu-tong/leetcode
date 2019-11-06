class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;

        return dfs(s, wordDict);
    }
    vector<string> dfs(string s, vector<string>& wordDict) {
        if(mem.count(s)) return mem[s];
        if(s.empty()) return {""};
        vector<string> ans;
        for(string& word : wordDict) {
            if(s.substr(0, word.size()) != word) continue;
            auto res = dfs(s.substr(word.size()), wordDict);
            for(string& str : res) {
                ans.push_back(word + (str.empty() ? "" : " ") + str);
            }
        }
        return mem[s] = ans;
    }
    unordered_map<string, vector<string>> mem; //loc, part ans
};
