class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans = 0;
        stack<int> s;
        for(const auto& token : tokens) {
            if(token != "+" && token != "-" && token != "*" && token != "/") {
                s.push(stoi(token));
            } else {
                int num1 = s.top(); s.pop();
                int num2 = s.top(); s.pop();
                
                if(token == "+") s.push(num2 + num1);
                if(token == "-") s.push(num2 - num1); 
                if(token == "*") s.push(num2 * num1); 
                if(token == "/") s.push(num2 / num1); 
            }
        }
        return s.top();
    }
};