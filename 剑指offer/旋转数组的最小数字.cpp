class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty()) return 0;
        
        int left = 0;
        int right = rotateArray.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(rotateArray[mid] >= rotateArray[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return rotateArray[right];
    }
};

//recursion
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty()) return 0;
        
        return binarySearch(rotateArray, 0, rotateArray.size() - 1);
    }
    int binarySearch(vector<int>& nums, int left, int right) {
        if(left == right) return nums[left];
        int mid = left + (right - left) / 2;
        if(nums[mid] < nums[right]) {
            return binarySearch(nums, left, mid);
        } else {
            return binarySearch(nums, mid + 1, right);
        }
    }
};