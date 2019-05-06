/*
**统计每个串26个字母出现次数 136ms
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mem;
        
        for(const auto& str : strs) {
            vector<int> cnt(26, 0);
            
            for(const auto& i : str) ++cnt[i - 'a'];
            
            string key = "";
            for(const auto& i : cnt) key += to_string(i) + '|';//26字母次数加分隔
            mem[key].push_back(str);
        }
        
        for(const auto& i : mem) 
            ans.push_back(i.second);
        return ans;
    }
};
/*
**把字母排序后直接作为key 40ms
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mem;
        
        for(const auto& str : strs) {          
            string key = str;
            sort(key.begin(), key.end());
            mem[key].push_back(str);
        }
        
        for(const auto& i : mem) 
            ans.push_back(i.second);
        return ans;
    }
};