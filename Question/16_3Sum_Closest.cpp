class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        for(int i = 0; i < nums.size(); ++i) {
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right) {
                int sum = nums[left] + nums[right] + nums[i];
                if(abs(target - sum) < diff) {
                    diff = abs(target - sum);
                    ans = sum;
                }
                if(sum < target)
                    ++left;
                else
                    --right;
            }
        }
        return ans;
    }
};
