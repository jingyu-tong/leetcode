/*
**brute force
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        for(int i = 0; i < haystack.size(); ++i) {
            if(haystack[i] == needle[0]) {
                int cur1 = i, cur2 = 0;
                while(cur1 < haystack.size() && cur2 < needle.size()) {
                    if(haystack[cur1] != needle[cur2]) break;
                    ++cur1; ++cur2;
                }
                if(cur2 == needle.size()) return i;
            }
        }
        return -1;
    }
};
