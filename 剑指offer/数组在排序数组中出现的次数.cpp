class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty()) return 0;
        
        int left = 0;
        int right = data.size() - 1;
        int mid;
        //找到左边界
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(data[mid] < k) 
                left = mid + 1;
            else
                right = mid - 1;
        }
        //判断是否在data里
        if(data[right + 1] != k) return 0;
        int l = right + 1;
        
        left = 0;
        right = data.size() - 1;
        //找右边界
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(data[mid] > k)
                right = mid - 1;
            else 
                left = mid + 1;
        }
        
        return left - 1 - l + 1;
    }
};