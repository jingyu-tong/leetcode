/*
**dfs permutations
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        vector<int> used(nums.size(), 0);
        dfs(nums, 0, used, cur, ans);
        return ans;
    }
private:
    void dfs(vector<int>& nums, int loc, vector<int>& used, vector<int>& cur, vector<vector<int>>& ans) {
        if(cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        }
        
        for(int i = 0; i < nums.size(); ++i) {
            if(used[i] == 1) continue;
            used[i] = 1;//对下屏蔽
            cur.push_back(nums[i]);
            dfs(nums, i, used, cur, ans);
            cur.pop_back();
            used[i] = 0;//对上打开
        }
    }
};