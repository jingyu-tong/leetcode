class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ind_1 = m - 1;
        int ind_2 = n - 1;
        int cur = m + n - 1;
        while(ind_1>= 0 && ind_2 >= 0) {
            if(nums1[ind_1] > nums2[ind_2]) nums1[cur--] = nums1[ind_1--];
            else nums1[cur--] = nums2[ind_2--];
        } 
        while(ind_2 >= 0) nums1[cur--] = nums2[ind_2--];
    }
};