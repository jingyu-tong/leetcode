class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size() == 0) return 0;
        int left = 0;
        int right = s.size() - 1;
        while(s[left] == ' ') ++left;
        while(s[right] == ' ') --right;

        int ans = 0;
        for(int i = left; i <= right; ++i) {
            if(s[i] == ' ') ans = 0;
            else ++ans;
        }
        return ans;
    }
};
