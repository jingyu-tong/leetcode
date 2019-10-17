//
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s.empty() || words.empty()) return {};
        unordered_map<string, int> word_map;
        for(auto& word : words) ++word_map[word];

        int len = words[0].size();
        int n = words.size();
        vector<int> ans;
        for(int i = 0; i <= (int)s.size() - n * len; ++i) {
            auto count_map = word_map;
            int j = i;
            while(j <= i + n*len) {
                string sub_str = s.substr(j, len);
                if(!count_map.count(sub_str) || count_map[sub_str] == 0)
                    break;
                --count_map[sub_str];
                j += len;
            }
            if(j == (i + n*len))
                ans.push_back(i);
        }
        return ans;
    }
};

//sliding window
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s.empty() || words.empty()) return {};
        unordered_map<string, int> word_map;
        for(auto& word : words) ++word_map[word];

        int len = words[0].size();
        int n = words.size();
        vector<int> ans;
        for(int i = 0; i < len; ++i) {
            auto counts = word_map;
            int num = n;
            for(int j = i; j + len <= s.size(); j += len) {
                string cur = s.substr(j, len);
                if(counts[cur]-- > 0) --num;
                if(j - n * len >= 0) { //out of current window
                    string out = s.substr(j - n * len, len);
                    if(++counts[out] > 0) ++num; //回收左窗口
                }
                if(num == 0) ans.push_back(j - (n - 1) * len);
            }
        }
        return ans;
    }
};
