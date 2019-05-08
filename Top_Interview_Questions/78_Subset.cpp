class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(nums, 0, cur, ans);
        return ans;    
    }
private:
    void dfs(vector<int>& nums, int loc, vector<int>& cur, vector<vector<int>>& ans) {
        if(loc == nums.size()) {
            ans.push_back(cur);
            return;
        }
        
        //with or without nums[loc]
        cur.push_back(nums[loc]);
        dfs(nums, loc + 1, cur, ans);
        cur.pop_back();
        
        dfs(nums, loc + 1, cur, ans);
    }
};
/*
**对于单个起点，用for循环更快
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(nums, 0, cur, ans);
        return ans;    
    }
private:
    void dfs(vector<int>& nums, int loc, vector<int>& cur, vector<vector<int>>& ans) {
        ans.push_back(cur);    
        //with or without nums[loc]
        for(int i = loc; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            dfs(nums, i + 1, cur, ans);
            cur.pop_back();         
        }
    }
};