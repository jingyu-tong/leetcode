class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int mem[26] = {0};
        for(auto i : s) 
            ++mem[i - 'a'];
        
        for(auto i : t) {
            if(--mem[i - 'a'] < 0) return false;
        }
        return true;
    }
};