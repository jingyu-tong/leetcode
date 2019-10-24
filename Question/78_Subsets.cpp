class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans{};
        vector<int> cur;

        for(int i = 0; i <= nums.size(); ++i)
            dfs(nums, 0, i, 0, cur, ans);
        return ans;
    }
    void dfs(vector<int>& nums, int loc, int target, int level, vector<int>& cur, vector<vector<int>>& ans) {
        if(level == target) {
            ans.push_back(cur);
            return;
        }

        for(int i = loc; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            dfs(nums, i + 1, target, level + 1, cur, ans);
            cur.pop_back();
        }
    }
};
