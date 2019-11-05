class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < 32; ++i) {
            int sum = 0; //统计每bit出现1的次数，重复三次%3为0
            for(auto& num : nums) {
                sum += (num >> i) & 0x01;
            }
            ans |= (sum % 3) << i; //统计第i位
        }
        return ans;
    }
};
