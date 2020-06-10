// dfs 超时 22/43
class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        if (beginWord.size() != endWord.size()) return -1;

        for (auto& s : wordList) {
            mem[s] = false;
        }

        int ans = INT_MAX;
        moveWord(beginWord, endWord, 0, ans);
        return ans == INT_MAX ? 0 : ans + 1;
    }

private:
    void moveWord(string beginWord, string endWord, int cur, int& ans) {
        if (beginWord == endWord) {
            ans = min(ans, cur);
            return;
        }

        // 循环更改第 i 位，从 a 变到 z
        for (int i = 0; i < beginWord.size(); ++i) {
            string temp = beginWord;
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                temp[i] = ch;
                if (mem.count(temp) != 0 && mem[temp] == false) {
                    mem[temp] = true;
                    moveWord(temp, endWord, cur + 1, ans);
                    mem[temp] = false;
                }
            }
        }
    }
    unordered_map<string, bool> mem;
};

class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;

        queue<string> q;
        unordered_map<string, int> words;
        words[beginWord] = -1;
        q.push(beginWord);

        int l = beginWord.length();  //
        int step = 0;

        while (!q.empty()) {
            ++step;
            for (int size = q.size(); size > 0; size--) {
                string w = q.front();
                q.pop();
                int loc = words[w];
                //遍历该string的每一位
                for (int i = 0; i < l; ++i) {
                    if (i == loc) continue;
                    char ch = w[i];
                    for (int j = 'a'; j < 'z'; ++j) {
                        w[i] = j;
                        if (w == endWord) return step + 1;

                        if (!dict.count(w)) continue;  //不在

                        words[w] = i;
                        dict.erase(w);
                        q.push(w);
                    }
                    w[i] = ch;  //恢复原string，搜索同层的下一个字母
                }
            }
        }
        return 0;
    }
};