class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        int level = 0;
        while(n) {
            if(n % 26 == 0) {
                ans += 'Z';
                n -= 26;
            } else {
                ans += n % 26 - 1 + 'A';
                n -= n % 26;
            }
            n /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
