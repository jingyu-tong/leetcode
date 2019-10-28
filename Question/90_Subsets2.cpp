class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans(1);
        vector<int> cur;
        sort(nums.begin(), nums.end());
        for(int i = 1; i <= nums.size(); ++i) {
            dfs(nums, 0, i, cur, ans);
        }
        return ans;
    }
    void dfs(vector<int>& nums, int loc, int level, vector<int>& cur, vector<vector<int>>& ans) {
        if(level == 0) {
            ans.push_back(cur);
            return;
        }
        for(int i = loc; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            dfs(nums, i + 1, level - 1, cur, ans);
            cur.pop_back();
            //跳过重复的
            while(i < nums.size() - 1 && nums[i] == nums[i + 1])
                ++i;
        }
    }
};
