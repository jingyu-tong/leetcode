class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(str.empty()) return {};
        n = n % (str.size());
        
        if(n == 0) return str;
        
        string left = str.substr(0, n);
        string right = str.substr(n);
        
        return right + left;
    }
};