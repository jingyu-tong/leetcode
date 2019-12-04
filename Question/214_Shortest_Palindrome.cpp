class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.empty()) return {};
        
        //left找到前缀为回文的最大下标
        int left = 0;
        for(int right = s.size() - 1; right >= 0; --right) {
            if(s[left] == s[right]) ++left;
        }
        
        if(left == s.size()) return s;
        
        string ans = s.substr(left);
        reverse(ans.begin(), ans.end());
        return ans + shortestPalindrome(s.substr(0, left)) + s.substr(left);
    }
};