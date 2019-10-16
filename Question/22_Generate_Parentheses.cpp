class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(ans, 0, 0, n, "");
        return ans;
    }
    void dfs(vector<string>& ans, int left, int right, int n, string cur) {
        if((left == right) && left == n) {
            ans.push_back(cur);
        }
        if(left < n)
            dfs(ans, left + 1, right, n, cur + '(');
        if(right < left)
            dfs(ans, left, right + 1, n, cur + ')');
    }
};
