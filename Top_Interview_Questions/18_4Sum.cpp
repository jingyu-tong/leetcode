/*
**和3sum类似
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = i + 1; j < nums.size(); ++j) {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = j + 1;
                int right = nums.size() - 1;
                while(left < right) {
                    int sum = nums[left] + nums[right] + nums[i] + nums[j];
                    if(sum == target) {
                        ans.insert({nums[i], nums[j], nums[left], nums[right]});
                        ++left;
                        --right;
                    } else if(sum < target)
                        ++left;
                    else
                        --right;
                }
            }
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};