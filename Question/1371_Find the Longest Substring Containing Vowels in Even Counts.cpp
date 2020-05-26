class Solution {
public:
    int findTheLongestSubstring(string s) {
        char vowels[] = "aeiou";
        vector<int> idx(1 << 5, INT_MAX);  // state -> first_index

        idx[0] = -1;
        int ans = 0;
        int state = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < 5; ++j) {
                if (s[i] == vowels[j]) state ^= 1 << j;
            }
            if (idx[state] == INT_MAX) idx[state] = i;
            ans = max(ans, i - idx[state]);
        }
        return ans;
    }
};