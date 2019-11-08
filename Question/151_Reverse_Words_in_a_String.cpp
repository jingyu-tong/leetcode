class Solution {
public:
    string reverseWords(string s) {
        istringstream is(s);
        string temp;
        is >> s; //空串
        while(is >> temp) s = temp + " " + s;
        if(!s.empty() && s[0] == ' ') s = "";
        return s;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        for(int i = s.size() - 1; i >= 0; --i) {
            if(s[i] == ' ') continue;
            int right = i;
            while(i >= 0 && s[i] != ' ') --i;
            ans = ans == "" ? s.substr(i + 1, right - i) : ans + " " + s.substr(i + 1, right - i);
        }
        return ans;
    }
};
