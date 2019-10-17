class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        int m = haystack.size();
        int n = needle.size();
        if(m < n) return -1;
        for(int i = 0; i < m; ++i) {
            int j = 0;
            for(j = 0; j < n; ++j) {
                if(needle[j] != haystack[i + j])
                    break;
            }
            if(j == n)
                return i;
        }
        return -1;
    }
};
//try kmp

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        int n = haystack.size();
        int m = needle.size();
        if(n < m) return -1;
        //calculate next vector
        vector<int> next(m, 0);
        next[0] = -1;
        int i = 0; //main
        int t = -1; //mode
        while(i < m - 1) {
            if(t < 0 || needle[t] == needle[i]) {
                ++i;
                ++t;
                next[i] = t;
            } else{
                t = next[t];
            }
        }

        i = 0; t = 0;
        while(i < n && t < m) {
            if(t < 0 || haystack[i] == needle[t]) {
                ++i; ++t;
            } else {
                t = next[t];
            }
        }
        return i == n ? (t == m ? i - t : -1) : i - t;
    }
};
