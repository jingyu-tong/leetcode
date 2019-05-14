class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(!dict.count(endWord)) return 0;
        
        queue<string> q;
        unordered_map<string, int> words;
        words[beginWord] = -1;
        q.push(beginWord);
        
        int l = beginWord.length();//
        int step = 0;
        
        while(!q.empty()) {
            ++step;
            for(int size = q.size(); size > 0; size--) {
                string w = q.front(); q.pop();
                int loc = words[w];
                //遍历该string的每一位
                for(int i = 0; i < l; ++i) {
                    if(i == loc) continue;
                    char ch = w[i];
                    for(int j = 'a'; j < 'z'; ++j) {
                        w[i] = j;
                        if(w == endWord) return step + 1;
                        
                        if(!dict.count(w)) continue;//不在
                        
                        words[w] = i;
                        dict.erase(w);
                        q.push(w);
                        
                    }
                    w[i] = ch;//恢复原string，搜索同层的下一个字母
                }
            }
        }
        return 0;
    }
};