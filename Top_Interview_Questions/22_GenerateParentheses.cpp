class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(n, n, "", ans);
        return ans;
    }
private:
    void dfs(int left, int right, string cur, vector<string>& ans) {
        if(left > right) return;
        if(left == 0 && right == 0) {
            ans.push_back(cur);
            return;
        }
        if(left > 0)
            dfs(left - 1, right, cur + '(', ans);
        if(right > 0)
            dfs(left, right - 1, cur + ')', ans);
    }
};