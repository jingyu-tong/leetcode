//滑动窗
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> mem;
        
        //k大小滑动窗
        int left = 0;
        int right = 0;
        for( ; right < nums.size(); ++right) {
            if(right - left > k) mem.erase(nums[left++]);
            
            auto iter = mem.lower_bound(static_cast<long>(nums[right]) - t); // - t  <= num[i] - nums[j]
            if( (iter != mem.end()) && ( (*iter) - nums[right] <= t)) return true;
            mem.insert(nums[right]);
        }
        return false;
    }
};