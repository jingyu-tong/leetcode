/*
**可以取出每一位进行判断
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        for(int i = 0; i < 32; ++i) {
            if( (n & 1) == 1)
                ++ans;
            else 
                ;
            n >>= 1;
        }
        return ans;
    }
};
/*
**利用n & (n - 1) 消去最后一位为1的位
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;

        while(n > 0) {
            n &= n - 1;
            ++ans;
            
        }
        
        return ans;
    }
};