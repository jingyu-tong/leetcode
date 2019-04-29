class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())//减治，num1取小数组
            return findMedianSortedArrays(nums2, nums1);
        const int k = (nums1.size() + nums2.size() + 1) / 2;
        //binary search
        int left = 0, right = nums1.size();
        while(left < right) {
            int mid = left + (right - left) / 2;
            int m2 = k - mid - 1;
            if(nums2[m2] > nums1[mid]) {
                left = mid + 1;
            } else {
                right = mid;
            }AC
        }
        
        int m1 = left, m2 = k - left;
        const int c1 = max(m1 <= 0 ? INT_MIN : nums1[m1 - 1],
                          m2 <= 0 ? INT_MIN : nums2[m2 - 1]);
        if((nums1.size() + nums2.size()) % 2 == 1)
            return c1;
        const int c2 = min(m1 >= nums1.size() ? INT_MAX : nums1[m1],
                          m2 >= nums2.size() ? INT_MAX : nums2[m2]);
        return (c1 + c2) * 0.5;       
    }
};
};