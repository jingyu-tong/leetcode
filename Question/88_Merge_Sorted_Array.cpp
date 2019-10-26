class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int ind1 = m - 1;
        int ind2 = n - 1;
        int cur = m + n - 1;
        while(ind1 >= 0 && ind2 >= 0) {
            if(nums1[ind1] > nums2[ind2]) nums1[cur--] = nums1[ind1--];
            else nums1[cur--] = nums2[ind2--];
        }

        while(ind2 >= 0)
            nums1[cur--] = nums2[ind2--];
    }
};
