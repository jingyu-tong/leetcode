class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        dfs(s, 4, "", ans);
        return ans;
    }
    void dfs(string s, int k, string cur, vector<string>& ans) {
        if(k == 0) {
            if(s.empty()) ans.push_back(cur);
        } else {
            for(int i = 1; i <= 3; ++i) {
                if(s.size() >= i && isValid(s.substr(0, i))) {
                    if(k == 1) dfs(s.substr(i), k - 1, cur + s.substr(0, i), ans);
                    else dfs(s.substr(i), k - 1, cur + s.substr(0, i) + ".", ans);
                }
            }
        }
    }
    bool isValid(string s) {
        if (s.empty() || s.size() > 3 || (s.size() > 1 && s[0] == '0')) return false;
        int num = stoi(s);
        return num <= 255 && num >= 0;
    }
};
