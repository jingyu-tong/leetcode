class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {};
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {return a[0] < b[0];});
        int n = intervals.size();
        int i = 0;
        int cur = 0;
        vector<vector<int>> ans({intervals[0]});
        for(int i = 1; i < n; ++i) {
            if(ans[cur][1] < intervals[i][0]) {
                ans.push_back(intervals[i]);
                ++cur;
            } else {
                ans[cur][1] = max(ans[cur][1], intervals[i][1]);
            }
        }
        return ans;
    }
};
