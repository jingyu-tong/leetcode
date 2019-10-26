class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        const int m = matrix.size();
        const int n = matrix[0].size();
        int ans = 0;

        vector<int> height(n, 0);
        for(int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                height[j] = matrix[i][j] == '0' ? 0 : (1 + height[j]);
            }
            //height.pop_back();
            ans = max(ans, largestRect(height));
        }
        return ans;
    }
    int largestRect(vector<int>& height) {
        stack<int> s;
        int ans = 0;
        height.push_back(0);
        for(int i = 0; i < height.size(); ++i) {
            if(s.empty() || height[i] >= height[s.top()]) {
                s.push(i);
            } else {
                int temp = s.top(); s.pop();
                ans = max(ans, height[temp] * (s.empty() ? i : i - s.top() - 1));
                --i;
            }
        }
        return ans;
    }
};
