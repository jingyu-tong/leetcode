class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        const int n = digits.size();
        vector<string> ans{""};
        for(int i = 0; i < n; ++i) {
            vector<string> t;
            string str = letters[digits[i] - '0'];
            for(const auto& j : str) {
                for(const auto& k : ans)
                    t.push_back(k + j);
            }
            ans = t;
        }
        return ans;
    }
};