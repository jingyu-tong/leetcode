class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;  // val pos

        // build hashmap
        for (int i = 0; i < nums.size(); ++i) {
            map[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); ++i) {
            int less = target - nums[i];
            if (map.count(less) != 0 && map[less] != i) return {i, map[less]};
        }
        return {};
    }
};
