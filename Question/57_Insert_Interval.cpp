class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty()) return {};
        vector<vector<int>> ans;
        int n = intervals.size();
        int cur = 0;

        for(int i = 0; i < n; ++i) {
            if(intervals[i][1] < newInterval[0]) {
                ans.push_back(intervals[i]);
                ++cur;
            } else if(intervals[i][0] > newInterval[1]) {
                ans.push_back(intervals[i]);
            } else { //overlapp
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        ans.insert(ans.begin() + cur, newInterval);
        return ans;
    }
};
