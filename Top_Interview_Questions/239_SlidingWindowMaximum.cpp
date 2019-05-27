/*
**brute force
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty()) return {};
        vector<int> ans;
        for(int i = 0; i < nums.size() - k + 1; ++i) {
            ans.push_back(*max_element(nums.begin() + i, nums.begin() + i + k));
        }
        return ans;
    }
};
/*
**BST
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty()) return {};
        vector<int> ans;
        multiset<int> window;
        for(int i = 0; i < nums.size(); ++i) {
            window.insert(nums[i]);
            if(i >= k - 1) {
                ans.push_back(*window.rbegin());
                window.erase(window.equal_range(nums[i - k + 1]).first);
            }
        }
        return ans;
    }
};