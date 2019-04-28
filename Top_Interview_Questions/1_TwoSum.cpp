class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int> ans;
        unordered_map<int, int> mem;
        for(int i = 0; i < nums.size(); ++i) {
            mem[nums[i]] = i;
        }
      
        for(int i = 0; i < nums.size(); ++i) {
            if(mem.count(target - nums[i]) && mem[target - nums[i]] != i)
                return {i, mem[target - nums[i]]};
        }

        return {};
    }
};
