class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mem;
        string ans = "";
        int left = 0, count = 0, minlen = INT_MAX;
        
        for(const auto& i : t) ++mem[i];
        
        for(int i = 0; i < s.size(); ++i) {
            if(--mem[s[i]] >= 0) ++count;//数到三个字母
            
            while(count == t.size()) {
                if((i - left + 1) < minlen) {
                    minlen = i - left  + 1;
                    ans = s.substr(left, minlen);
                }
                if(++mem[s[left]] > 0) --count;//减掉的是字母
                ++left;
            }
        }
        return ans;
    }
};