class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mem;

        for(auto& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            mem[key].push_back(str);
        }

        for(auto& i : mem) {
            ans.push_back(i.second);
        }
        return ans;
    }
};
