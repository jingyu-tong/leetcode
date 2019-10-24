class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mem;
        for(auto& ele : t)
            ++mem[ele];

        int left = 0;
        int cur = 0;
        int count = 0;
        int length = INT_MAX;
        int start = 0;
        while(cur < s.size()) {
            if(--mem[s[cur]] >= 0) ++count; //统计窗口内字符

            while(count == t.size()) {
                if(cur - left + 1 < length) {
                    start = left;
                    length = cur - left + 1;
                }
                if(++mem[s[left]] > 0) --count; //t内字母被删
                ++left;
            }
            ++cur;
        }
        return length == INT_MAX ? "" : s.substr(start, length);
    }
};
