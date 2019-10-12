class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = INT_MIN;
        int left = -1;
        int right = 0;
        unordered_map<char, int> map; //char loc
        while(right < s.size()) {
            if(map.count(s[right]) && map[s[right]] > left) {
                left = map[s[right]];
            }
            map[s[right]] = right;
            ans = max(ans, right - left);
            ++right;
        }
        return ans;
    }
};
