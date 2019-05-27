/*
**二分查找
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size();
        while(left < right) {
            int mid = left + (right - left) / 2;
            int cnt = 0;
            for(auto& num : nums)
                if(num <= mid) ++cnt;
            if(cnt <= mid) left = mid + 1;
            else right = mid;
        }
        return right;
    }
};
/*
**采用之前链表题里，快慢指针找环
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        while(1) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
        }
        fast = 0;   
        while(1) {
            slow = nums[slow];
            fast = nums[fast];
            if(slow == fast) break;
        }
        return slow;
    }
};