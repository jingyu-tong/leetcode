class Solution {
public:
    int myAtoi(string str) {
        int ans = 0;
        int sign = 1;
        int pos = 0;
        int n = str.size();
        while(pos < n && str[pos] == ' ') ++pos;
        if(pos < n && ((str[pos] == '+' || str[pos] == '-'))) {
            sign = (str[pos++] == '+') ? 1 : -1;
        }

        while(pos < n && str[pos] <= '9' && str[pos] >= '0') {
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && str[pos] - '0' > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            ans = ans * 10 + (str[pos++] - '0'); //important! avoid overflow
        }
        return ans * sign;
    }
};
