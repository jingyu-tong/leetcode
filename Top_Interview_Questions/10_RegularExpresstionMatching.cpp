/*
**recursion
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        //长度小于1
        if(p.empty()) return s.empty();
        if (p.size() == 1) {
            return (s.size() == 1 && (s[0] == p[0] || p[0] == '.'));
        }
        //长度大于等于2
        //不为*，减而治之
        if(p[1] != '*') {
            if(s.empty()) return false;
            return (p[0] == s[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }
        //为*,可0，可any
        while(!s.empty() && (s[0] == p[0] || p[0] == '.')) {
            //0 - n - 1次
            if(isMatch(s, p.substr(2))) return true;
            s = s.substr(1);
        }
        //n次
        return isMatch(s, p.substr(2));
    }
};
/*
**recursion
*/