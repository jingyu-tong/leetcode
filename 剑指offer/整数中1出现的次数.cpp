//第i位为0：第i为1的次数由最高位决定，等于高位数字*当前权重10i-1
//第i位为1：高位低位共同决定，等于高位数字*(10i-1+低位数字+1)
//第i为else：等于(高位+1)*10i-1 超过1的话，这位剩下的也就没用了
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int ans = 0;
        for(int i = 1; i <= n; i *= 10) {
            int a = n / i;
            int b = n % i;
            ans += (a + 8) / 10 * i + ( (a % 10 == 1) ? b + 1 : 0);
        }
        return ans;
    }
};
