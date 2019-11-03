class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right) {
            if(notValid(s[left])) ++left;
            else if(notValid(s[right])) --right;
            else if( (s[left] + 32 - 'a')  % 32 != (s[right] + 32 - 'a')  % 32) return false;
            else {++left; --right;}
        }
        return true;
    }
    bool notValid(const char& ch) {
        if(ch <= 'z' && ch >= 'a') return false;
        if(ch <= 'Z' && ch >= 'A') return false;
        if(ch <= '9' && ch >= '0') return false;
        return true;
    }
};
