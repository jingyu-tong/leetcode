class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans{""};
        for(int i = 0; i < digits.size(); ++i) {
            string letter = letters[digits[i] - '0'];
            vector<string> t;
            for(auto& ele : letter) {
                for(auto& k : ans)
                    t.push_back(k + ele);
            }
            ans = t;
        }
        return ans;
    }
};

//dfs
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        dfs(digits, letters, ans, "", 0);
        return ans;
    }
    void dfs(string& digits, vector<string>& letters, vector<string>& ans, string cur, int level) {
        if(level == digits.size()) {
            ans.push_back(cur);
            return;
        }
        string str = letters[digits[level] - '0'];
        for(int i = 0; i < str.size(); ++i) {
            dfs(digits, letters, ans, cur + str[i], level + 1);
        }
    }
};
