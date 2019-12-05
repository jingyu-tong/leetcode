class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_map<int, int> mem;
        for(int i = 0; i < nums.size(); ++i) {
            if(mem.count(nums[i]) && i - mem[nums[i]] <= k) 
                return true;
            else
                mem[nums[i]] = i;
        }
        
        return false; 
    }
};