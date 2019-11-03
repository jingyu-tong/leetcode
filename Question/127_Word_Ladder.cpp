class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(!dict.count(endWord)) return 0;

        queue<string> q;
        q.push(beginWord);
        int step = 0;
        while(!q.empty()) {
            ++step;
            for(int i = q.size(); i >= 1; --i) {
                //取word，更改j位
                string word = q.front(); q.pop();
                for(int j = 0; j < word.size(); ++j) {
                    char ch = word[j];
                    for(char k = 'a'; k <= 'z'; ++k) {
                        word[j] = k;
                        if(word == endWord) return step + 1;
                        if(!dict.count(word)) continue;
                        q.push(word);
                        dict.erase(word);
                    }
                    word[j] = ch;
                }
            }
        }
        return 0;
    }
};
