class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        vector<bool> used(nums.size(), false);
        dfs(nums, 0, used, cur, ans);
        return ans;
    }
    void dfs(vector<int>& nums, int level, vector<bool>& used, vector<int>& cur, vector<vector<int>>& ans) {
        if(level >= nums.size()) {
            ans.push_back(cur);
            return;
        }

        for(int i = 0; i < nums.size(); ++i) {
            if(used[i] == true) continue;
            cur.push_back(nums[i]);
            used[i] = true;
            dfs(nums, level + 1, used, cur, ans);
            used[i] = false;
            cur.pop_back();
        }
    }
};
