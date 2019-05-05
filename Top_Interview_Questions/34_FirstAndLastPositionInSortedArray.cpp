class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1, -1};
        int start = startSearch(nums, target, 0, nums.size());
        if(start >= nums.size() || nums[start] != target)
            return {-1, -1};
        int end = endSearch(nums, target, start, nums.size());
        return {start, end};
    }
private:
    //find the starting point of the target
    int startSearch(vector<int>& nums, int target, int begin, int end) {
        if(begin >= end) {
            return begin;
        }   
        int mid = begin + (end - begin) / 2;
        if(nums[mid] < target)
            return startSearch(nums, target, mid + 1, end);
        else
            return startSearch(nums, target, begin, mid);
    }
	//find the ending point of the target
    int endSearch(vector<int>& nums, int target, int begin, int end) {
        if(begin >= end) {
            return begin - 1;
        }   
        int mid = begin + (end - begin) / 2;
        if(nums[mid] <= target)
            return endSearch(nums, target, mid + 1, end);
        else
            return endSearch(nums, target, begin, mid);        
    }
};