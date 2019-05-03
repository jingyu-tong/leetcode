class Solution {
public:
    bool isValid(string s) {
        stack<char> con;
        for(const auto& i : s) {
            if(i == '(') {con.push(i); continue;}
            if(i == '[') {con.push(i); continue;}
            if(i == '{') {con.push(i); continue;}
            
            if(con.empty()) return false;
            char t = con.top(); con.pop();
            if(i == ')' && t == '(') continue;
            if(i == ']' && t == '[') continue;
            if(i == '}' && t == '{') continue;
            return false;
        }
        return con.empty();
    }
};