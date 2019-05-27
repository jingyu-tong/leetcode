class Solution {
public:
    int calculate(string s) {
        const int n = s.size();
        int ans = 0, cur_ans = 0, num = 0;
        char op = '+';
        for(int i = 0; i < n; ++i) {
            char ch = s[i];
            if(ch >= '0' && ch <= '9') {
                num = num * 10 + (ch - '0');
            }
            if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || i == n - 1) {
                switch (op) {
                    case '+': cur_ans += num; break;
                    case '-': cur_ans -= num; break;
                    case '*': cur_ans *= num; break;
                    case '/': cur_ans /= num; break;
                }
                if(ch == '+' || ch == '-' || i == n - 1) {
                    ans += cur_ans;
                    cur_ans = 0;
                }
                op = ch;
                num = 0;
            }
        }
        return ans;
    }
};