class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.empty()) return true;
        
        unordered_map<int, int> mem1;
        unordered_map<int, int> mem2;
        for(int i = 0; i < s.size(); ++i) {
            if(mem1[s[i]] != mem2[t[i]]) return false;
            
            mem1[s[i]] = i + 1;
            mem2[t[i]] = i + 1;
        }
        return true;
    }
};