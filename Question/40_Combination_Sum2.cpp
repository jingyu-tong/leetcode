class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, 0, cur, ans);
        return ans;
    }
    void dfs(vector<int>& candidates, int target, int loc, int cur_sum, vector<int>& cur, vector<vector<int>>& ans) {
        if(cur_sum > target) return;
        if(cur_sum == target) {
            ans.push_back(cur);
            return;
        }
        for(int i = loc; i < candidates.size(); ++i) {
            if(i > loc && candidates[i] == candidates[i - 1]) continue;
            cur.push_back(candidates[i]);
            dfs(candidates, target, i + 1, cur_sum + candidates[i], cur, ans);
            cur.pop_back();
        }
    }
};
