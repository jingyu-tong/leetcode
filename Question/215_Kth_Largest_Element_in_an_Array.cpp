//利用快排的思想找第k大的数
//采用随机选取的方式
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        
        while(left < right) {
            int pos = partition(nums, left, right);
            if(pos == k - 1) return nums[pos];
            if(pos > k - 1) right = pos - 1;
            else left = pos + 1;
        }
        return nums[left];
    }
private:
    //由大到小排
    int partition(vector<int>& nums, int left, int right) {
        //随机选取pivot
        swap(nums[left], nums[left + rand() % (right - left + 1)]);
        int pivot = nums[left];
        while(left < right) {
            while(left < right && nums[right] <= pivot)
                --right;
            nums[left] = nums[right];
            while(left < right && nums[left] >= pivot)
                ++left;
            nums[right] = nums[left];
        }
        
        //归位pivot
        nums[left] = pivot;
        return left;
    }
};