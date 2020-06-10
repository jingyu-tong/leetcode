class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) return {};

        dict_ = unordered_set<string>(wordDict.begin(), wordDict.end());
        return dfs(s);
    }

private:
    unordered_set<string> dict_;
    unordered_map<string, vector<string>> mem_;
    vector<string> dfs(string s) {
        if (s.empty()) return {""};
        if (mem_.count(s)) return mem_[s];

        vector<string> ans;
        for (int i = 0; i < s.size(); ++i) {
            string temp = s.substr(0, i + 1);
            if (!dict_.count(temp)) continue;
            auto words = dfs(s.substr(i + 1));
            // 拼接答案
            for (auto& str : words) {
                ans.push_back(temp + (str.empty() ? "" : " ") + str);
            }
        }
        return mem_[s] = ans;
    }
};