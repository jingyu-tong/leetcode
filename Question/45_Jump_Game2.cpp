//dfs TLE
class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = INT_MAX;
        dfs(nums, 0, 0, ans);
        return ans;
    }
    void dfs(vector<int>& nums, int cur, int step, int& ans) {
        if(cur >= nums.size() - 1) {
            ans = min(ans, step);
            return;
        }

        for(int i = 1; i <= nums[cur]; ++i) {
            dfs(nums, cur + i, step + 1, ans);
        }
    }
};
// like bfs
class Solution {
public:
    int jump(vector<int>& nums) {
        int start = 0;
        int end = 0;
        int cur = 0;
        int ans = 0;
        while(cur < nums.size() - 1) {
            ++ans;
            int max_end = 0;
            for(int i = start; i <= end; ++i) {
                if(i + nums[i] >= nums.size() - 1) return ans;
                max_end = max(max_end, i + nums[i]);
            }
            start = end + 1;
            end = max_end;
        }
        return ans;
    }
};
