class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(candidates, target, 0, 0, cur, ans);
        return ans;
    }
    void dfs(vector<int>& candidates, int target, int loc, int cur_sum, vector<int>& cur, vector<vector<int>>& ans) {
        if(cur_sum > target) return;
        if(loc >= candidates.size()) return;
        if(cur_sum == target) {
            ans.push_back(cur);
        }
        for(int i = loc; i < candidates.size(); ++i) {
            cur.push_back(candidates[i]);
            dfs(candidates, target, i, cur_sum + candidates[i], cur, ans);
            cur.pop_back();
        }
    }
};
