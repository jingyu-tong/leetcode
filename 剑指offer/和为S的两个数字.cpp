//遍历 +二分搜索 O(nlogn)
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        if(array.size() < 2) return {};
        
        for(int i = 0; i < array.size(); ++i) {
            int ans1 = array[i];
            int ans2 = binarySearch(array, i, array.size() - 1, sum - ans1);
            if(ans2 == -1) continue;
            return {ans1, ans2};
        }
        return {};
    }
    int binarySearch(vector<int>& array, int left, int right, int target) {
        if(left > right) return -1;
        
        int mid = left + (right - left) / 2;
        if(array[mid] == target) return array[mid];
        if(array[mid] < target) {
            return binarySearch(array, mid + 1, right, target);
        } else {
            return binarySearch(array, left, mid - 1, target);
        }
    }
};

//左右指针 O(n)
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        if(array.size() < 2) return {};
        
        int left = 0;
        int right = array.size() - 1;
        while(left < right) {
            if(array[left] + array[right] == sum) return {array[left], array[right]};
            if(array[left] + array[right] < sum) {
                ++left;
            } else {
                --right;
            }
        }
        return {};
    }
};
