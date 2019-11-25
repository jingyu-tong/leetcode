class Solution {
public:
    int InversePairs(vector<int> data) {
        if(data.empty()) return 0;
        
        vector<int> nums(data);
        return mergeCount(nums, 0, nums.size() - 1);
    }
private:
    int mergeCount(vector<int>& nums, int left, int right) {
        if(left == right) return 0;
        if(left > right) return 0;
        
        int mid = left + (right - left) / 2;
        int l = mergeCount(nums, left, mid);
        int r = mergeCount(nums, mid + 1, right);
        
        //合并左右
        int ans = l + r + merge(nums, left, mid, right);
        
        return ans % 1000000007;
    }
    int merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp(right - left + 1);
        int i = left;
        int j = mid + 1;
        int k = 0;
        int count = 0;
        while(i <= mid && j <= right) {
            if(nums[i] < nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
                count += mid - i + 1; //i位置更大，说明右侧的都更大
            }
            if(count > 1000000007) count -= 1000000007;
        }
        
        while(i <= mid)
            temp[k++] = nums[i++];
        while(j <= right) 
            temp[k++] = nums[j++];
        
        for(int i = left; i <= right; ++i) {
            nums[i] = temp[i - left];
        }
        
        return count;
    }
};