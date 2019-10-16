class Solution {
public:
    int maxArea(vector<int>& height) {
        int right = height.size() - 1;
        int left = 0;
        int ans = INT_MIN;
        while(left < right) {
            ans = max(ans, min(height[left], height[right]) * (right - left));
            height[left] < height[right] ? ++left : --right;
        }
        return ans;
    }
};
