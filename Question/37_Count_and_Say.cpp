class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        while(--n) {
            string cur = "";
            for(int i = 0; i < ans.size(); ++i) {
                int count = 1;
                while(i < ans.size() - 1 && ans[i] == ans[i + 1]) {
                    ++count;
                    ++i;
                }
                cur += to_string(count) + ans[i];
            }
            ans = cur;
        }
        return ans;
    }
};
