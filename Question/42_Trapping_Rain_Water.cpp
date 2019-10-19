class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0 || n == 1) return 0;
        int ans = 0;

        vector<int> max_left(n, 0);
        max_left[0] = height[0];
        for(int i = 1; i < n; ++i) {
            max_left[i] = max(height[i], max_left[i - 1]);
        }

        vector<int> max_right(n, 0);
        max_right[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; --i) {
            max_right[i] = max(height[i], max_right[i + 1]);
        }

        for(int i = 0; i < n; ++i) {
            ans += min(max_left[i], max_right[i]) - height[i];
        }
        return ans;
    }
};
