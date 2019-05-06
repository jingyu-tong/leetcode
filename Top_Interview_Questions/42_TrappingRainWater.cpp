/*
**brute force 164ms
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int max_left = 0;
        
        for(int i = 0; i < height.size(); ++i) {
            max_left = max(max_left, height[i]);
            int max_right = 0;
            for(int j = i; j < height.size(); ++j) {
                max_right = max(max_right, height[j]);
            }
            int cur = min(max_left, max_right);
            ans += cur - height[i];
        }
        return ans;
    }
};
/*
**dp 8ms
*/
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        const int n = height.size();
        int ans = 0;
        
        vector<int> max_left(n, 0);//max height from 0 to i
        vector<int> max_right(n, 0);//max height from n to i
        
        max_left[0] = height[0];
        for(int i = 1; i < n; ++i) {
            max_left[i] = max(max_left[i - 1], height[i]);
        }
        max_right[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; --i) {
            max_right[i] = max(max_right[i + 1], height[i]);
        }        
        
        for(int i = 0; i < n; ++i) {
            ans += min(max_left[i], max_right[i]) - height[i];
        }
        return ans;
    }
};