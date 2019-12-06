class Solution {
public:
    int calculate(string s) {
        stack<int> mem;
        int num = 0;
        int sign = 1;
        for(int i = 0; i < s.size(); ++i) {
            if(isNum(s[i])) {
                int temp = 0;
                while(i < s.size() && isNum(s[i])) {
                    temp *= 10;
                    temp += s[i++] - '0';
                }
                num += sign * temp;
                --i;
            } else if(s[i] == '-') {
                sign = -1;
            } else if(s[i] == '+') {
                sign = 1;
            } else if(s[i] == '(') {
                mem.push(num);
                mem.push(sign);
                num = 0;
                sign = 1;
            } else if(s[i] == ')') {
                num *= mem.top(); mem.pop();
                num += mem.top(); mem.pop();
            }
        }
        return num;
    }
private:
    bool isNum(const char& ch) {
        return ch >= '0' && ch <= '9';
    }
};