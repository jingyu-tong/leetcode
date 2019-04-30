/*
**brute force TLE
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        for(int i = 0; i < height.size(); ++i) {
            for(int j = i + 1; j < height.size(); ++j) {
                int cur = (j - i) * min(height[i], height[j]);
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};
/*
**two pointers method
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int begin = 0, end = height.size() - 1;
        int ans = 0;
        while(begin < end) {
            int cur = min(height[begin], height[end]) * (end - begin);
            ans = max(ans, cur);
            height[begin] > height[end] ? --end : ++begin;
        }
        return ans;
    }
};