class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        for(int i = 0; i < 32; ++i) {
            ans += n & 0x01;
            n >>= 1;
        }
        return ans;
    }
};
