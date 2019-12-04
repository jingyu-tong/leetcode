//dfs combination
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k > n) return {};
        if(k > 9) return {};
        
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(k, 0, n, 1, cur, ans);
        return ans;
    }
private:
    void dfs(int k, int level, int n, int num, vector<int>& cur, vector<vector<int>>& ans) {
        if(k == level) {
            if(n == 0)
                ans.push_back(cur);
            return;
        }
        
        for(int i = num; i <= 9; ++i) {
            cur.push_back(i);
            dfs(k, level + 1, n - i, i + 1, cur, ans);
            cur.pop_back();
        }
    }
};