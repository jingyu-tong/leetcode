
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int n = heights.size();
        int ans = 0;
        stack<int> s;
        // int left = 0, right = 0;
        heights.push_back(0);
        for(int i = 0; i < heights.size(); ++i) {
            if(s.empty() || heights[s.top()] < heights[i]) {
                s.push(i);
            } else {
                int temp = s.top(); s.pop();
                ans = max(ans, heights[temp] * (s.empty() ? i : (i - s.top() - 1)));
                --i;
            }
        }
        return ans;
    }
};