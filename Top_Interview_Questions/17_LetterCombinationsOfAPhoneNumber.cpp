class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> letters = {"",    "",    "abc",  "def", "ghi",
                                  "jkl", "mno", "pqrs", "tuv", "wxyz"};
        const int n = digits.size();
        vector<string> ans{""};
        for (int i = 0; i < n; ++i) {
            vector<string> t;
            string str = letters[digits[i] - '0'];
            for (const auto& j : str) {
                for (const auto& k : ans) t.push_back(k + j);
            }
            ans = t;
        }
        return ans;
    }
};

// dfs
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> ans;
        vector<string> letters = {"",    "",    "abc",  "def", "ghi",
                                  "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string cur;
        dfs(digits, letters, 0, cur, ans);
        return ans;
    }
    void dfs(string& digits, vector<string>& letters, int loc, string& cur,
             vector<string>& ans) {
        if (loc == digits.size()) {
            ans.push_back(cur);
            return;
        }

        for (int i = 0; i < letters[digits[loc] - '0'].size(); ++i) {
            cur.push_back(letters[digits[loc] - '0'][i]);
            dfs(digits, letters, loc + 1, cur, ans);
            cur.pop_back();
        }
    }
};