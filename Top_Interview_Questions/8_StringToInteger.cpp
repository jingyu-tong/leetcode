class Solution {
public:
    int myAtoi(string str) {
        if(str.empty()) return 0;
        
        int cur = 0;
        while(cur < str.size() && str[cur] == ' ')
            ++cur;
        int sign = 1;// 1 +, -1 -
        if(str[cur] == '-') {
            sign = -1;
            ++cur;
        } else if(str[cur] == '+')
            ++cur;
        
        int ans = 0;
        while(cur < str.size() && isNum(str[cur])) {
            //同时需要判断末位是否溢出
			if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && str[cur] - '0' > 7)) return sign == -1 ? INT_MIN : INT_MAX;
            
            ans = ans * 10 + (str[cur] - '0');//这里需要括号，否则*10 + ASCII可能会溢出
            ++cur;
        }
        return ans * sign;
    }
private:
    bool isNum(const char c) {
        return c >= '0' && c <= '9';
    }
};