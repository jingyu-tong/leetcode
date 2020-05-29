/*
**dfs permutations
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) return {};

        vector<vector<int>> ans;
        vector<int> used(nums.size(), 0);
        vector<int> cur;
        dfs(nums, used, cur, ans);
        return ans;
    }
    void dfs(vector<int>& nums, vector<int>& used, vector<int>& cur,
             vector<vector<int>>& ans) {
        if (cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            used[i] = 1;
            cur.push_back(nums[i]);
            dfs(nums, used, cur, ans);
            cur.pop_back();
            used[i] = 0;
        }
    }
};