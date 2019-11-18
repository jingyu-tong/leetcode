//为了避免符号位以为问题，选择了判断首位
//可以剪枝
class Solution {
public:
     int  NumberOf1(int n) {
         int ans = 0;
         for(int i = 0; i < 32; ++i) {
             if( (n & 0x80000000) == 0x80000000)
                 ++ans;
             n = n << 1;
         }
         return ans;
     }
};

//利用n & (n - 1) 置为最低位的1
class Solution {
public:
     int  NumberOf1(int n) {
         int ans = 0;
         while(n) {
             ++ans;
             n = n & (n - 1);
         }
         return ans;
     }
};