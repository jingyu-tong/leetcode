class Solution {
public:
    vector<string> Permutation(string str) {
        if(str.empty()) return {};
        
        sort(str.begin(), str.end()); //排序，避免重复答案
        vector<string> ans;
        string cur;
        vector<int> used(str.size(), 0);
        dfs(str, used, cur, ans);
        return ans;
    }
    void dfs(string& str, vector<int>& used, string& cur, vector<string>& ans) {
        if(cur.size() == str.size()) {
            ans.push_back(cur);
            return;
        }
        for(int i = 0; i < str.size(); ++i) {
            if(used[i] == 1) continue;
            cur.push_back(str[i]);
            used[i] = 1;
            dfs(str, used, cur, ans);
            used[i] = 0;
            cur.pop_back();
            while(i < str.size() - 1 && str[i] == str[i + 1]) ++i;
        }
    }
};