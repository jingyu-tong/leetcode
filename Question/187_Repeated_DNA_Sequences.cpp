class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<char, int> mem{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        unordered_map<int, int> hash;// str_key, count
        vector<string> ans;
        int cur = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(i < 9) {
                cur = cur << 2 | mem[s[i]];
            } else {
                cur = ( (cur & 0x3ffff) << 2) | (mem[s[i]]);
                if(hash.count(cur) && hash[cur] == 1) ans.push_back(s.substr(i - 9, 10));
                ++hash[cur];
            }
        }
        return ans;
    }
};
