class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        int cur = 0;
        string ans = "";
        while(1) {
            char last;
            if(cur >= strs[0].size())
                return ans;
            last = strs[0][cur];
            for(int i = 1; i < strs.size(); ++i) {           
                if(cur >= strs[i].size())
                    return ans;
                if(last != strs[i][cur])
                    return ans;
            }
            ans += last;
            ++cur;
        }
        return ans;
    }
};