class Solution {
public:
    int calculate(string s) {
        if(s.empty()) return 0;
        
        stack<int> mem;
        int num = 0;
        char op = '+';
        for(int i = 0; i < s.size(); ++i) {
            if(isNum(s[i])) {
                num *= 10;
                num += (s[i] - '0');
            }
            
            if( (s[i] < '0' && s[i] != ' ') || i == s.size() - 1) {
                if(op == '+') mem.push(num);
                if(op == '-') mem.push(-num);
                if(op == '*' || op == '/') {
                    int temp = op == '*' ? mem.top() * num : mem.top() / num;
                    mem.pop();
                    mem.push(temp);
                }
                op = s[i];
                num = 0;
            }
        }
        
        int ans = 0;
        while(!mem.empty()) {
            ans += mem.top();
            mem.pop();
        }
        return ans;
    }
private:
    bool isNum(const char& ch) {
        return ch <= '9' && ch >= '0';
    }
}; 