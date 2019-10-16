class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        //少 全+ 全-
        if(nums.size() < 3 || nums.front() > 0 || nums.back() < 0) return ans;
        for(int i = 0; i < nums.size(); ++i) {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            int target = 0 - nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right) {
                if(target == nums[left] + nums[right]) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while(left < right && nums[left + 1] == nums[left]) ++left;
                    while(left < right && nums[right - 1] == nums[right]) --right;
                    ++left;
                    --right;
                } else if(nums[left] + nums[right] < target)
                    ++left;
                else
                    --right;
            }
        }
        return ans;
    }
};
