class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;

        for(int i = 0; i < 31; ++i) {
            ans |= n & 0x01;
            n >>= 1;
            ans <<= 1;
        }
        ans |= n & 0x01;
        return ans;
    }
};
