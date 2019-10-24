class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if(k > n) return {};
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(n, k, 0, 0, cur, ans);
        return ans;
    }
    void dfs(int n, int k, int num, int level, vector<int>& cur, vector<vector<int>>& ans) {
        if(level == k) {
            ans.push_back(cur);
        }
        for(int i = num + 1; i <= n; ++i) {
            cur.push_back(i);
            dfs(n, k, i, level + 1, cur, ans);
            cur.pop_back();
        }
    }
};
