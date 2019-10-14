class Solution {
public:
    string intToRoman(int num) {
        vector<char> roman{'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        vector<int> value{1000, 500, 100, 50, 10, 5, 1};
        string ans;

        for(int i = 0; i < 7; i = i + 2) {
            int x = num / value[i];
            if(x < 4) {
                for (int n = 1; n <= x; ++n) ans += roman[i];
            } else if(x == 4) {
                ans = ans + roman[i] + roman[i - 1];
            } else if(x > 4 && x < 9) {
                ans += roman[i - 1];
                for (int n = 6; n <= x; ++n) ans += roman[i];
            } else {
                 ans = ans + roman[i] + roman[i - 2];
            }
            num %= value[i];
        }
        return ans;
    }
};
