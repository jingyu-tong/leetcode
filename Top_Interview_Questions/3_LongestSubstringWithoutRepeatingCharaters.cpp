class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int ans = INT_MIN;
        int left = -1;
        unordered_map<int, int> mem;//储存上次出现的位置
        for(int i = 0; i < s.size(); ++i) {
            if(mem.count(s[i]) && left < mem[s[i]]) {
                left = mem[s[i]];
            }
            mem[s[i]] = i;
            ans = max(i - left, ans);
        }
        return ans;
    }
};