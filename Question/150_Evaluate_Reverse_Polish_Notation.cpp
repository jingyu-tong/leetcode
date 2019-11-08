class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i = 0; i < tokens.size(); ++i) {
            auto token = tokens[i];
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
