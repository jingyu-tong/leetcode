class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int ans = 0;
        heights.push_back(0);
        for(int i = 0; i < heights.size(); ++i) {
            if(s.empty() || heights[s.top()] < heights[i])
                s.push(i);
            else {
                int ind = s.top(); s.pop();
                ans = max(ans, heights[ind] * (s.empty() ? i : i - s.top() - 1));
                --i;//取下一个
            }
        }
        return ans;
    }
};
