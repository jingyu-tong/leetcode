class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.empty()) return -1;
        
        unordered_map<int, int> mem;
        for(int i = 0; i < str.size(); ++i) {
            ++mem[str[i]];
        }
        
        for(int i = 0; i < str.size(); ++i) {
            if(mem[str[i]] == 1) return i;
        }
        return -1;
    }
};