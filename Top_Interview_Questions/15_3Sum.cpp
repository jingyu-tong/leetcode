/*
**dfs TLE  311/313
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, 0, cur, ans);
        return ans;
    }
private:
    void dfs(vector<int>& nums, int loc, int target, vector<int> cur, vector<vector<int>>& ans) {
        if(cur.size() == 3) {
            if(target == 0)
                ans.push_back(cur);
            return;
        }
        if(loc >= nums.size()) return;
        cur.push_back(nums[loc]);
        dfs(nums, loc + 1, target - nums[loc], cur, ans);
        cur.pop_back();
        while(loc < nums.size() - 1 && nums[loc + 1] == nums[loc])
            ++loc;
        dfs(nums, loc + 1, target, cur, ans);
    }
};
/*
**取第一个数后，加速判断后两个
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] > 0) return ans;
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int target = 0 - nums[i];
            int m = i + 1, n = nums.size() - 1;
            while(m < n) {
                if(nums[m] + nums[n] == target) {
                    ans.push_back({nums[i], nums[m], nums[n]});
                    while(m < nums.size() - 1 && nums[m + 1] == nums[m]) ++m;
                    while(n > 0 && nums[n - 1] == nums[n]) --n;
                    ++m; --n;
                } else if(nums[m] + nums[n] < target) ++m;
                else --n;
            }
        }
        return ans;
    }
};