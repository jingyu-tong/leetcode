class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {};
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {return a[0] < b[0];});
        vector<vector<int>> ans;     
        ans.push_back(intervals[0]);
        int cur = 0;
        //merge i i - 1
        for(int i = 1; i < intervals.size(); ++i) {
            //isn't overlap
            if(ans[cur][1] < intervals[i][0]) {
                ans.push_back(intervals[i]);
                ++cur;
            } else {
                ans[cur][1] = max(intervals[i][1], ans[cur][1]);
            }
        }
        return ans;
    }
};