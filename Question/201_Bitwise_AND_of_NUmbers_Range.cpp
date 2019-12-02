class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        unsigned int mask = INT_MAX;
        while( (m & mask) != (n & mask)) {
            mask <<= 1;
        }
        return mask & m;
    }
};