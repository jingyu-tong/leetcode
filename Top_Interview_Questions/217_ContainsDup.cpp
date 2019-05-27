class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> mem;
        for(int i = 0; i < nums.size(); ++i) {
            if(mem.count(nums[i]))
                return true;
            mem.insert(nums[i]);
        }
        return false;
    }
};