//利用trie-tree快速搜索
class Solution {
public:
    struct TrieNode {
    TrieNode():children_(26, nullptr) {

    }
    ~TrieNode() {
        for(auto child : children_) {
            if(child) delete child;
        }
    }
    string str_;
    vector<TrieNode*> children_;
    };
    struct Trie {
        TrieNode* root_;
        Trie(): root_(new TrieNode()) {};
        void insert(string s) {
            TrieNode* p = root_;
            for(auto i : s) {
                if(!p->children_[i - 'a']) p->children_[i - 'a'] = new TrieNode();
                p = p->children_[i - 'a'];
            }
            p->str_ = s;
        }
    };
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        const int m = board.size();
        const int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        Trie t;
        for(auto& word : words) t.insert(word);
        
        for(int x = 0; x < m; ++x) {
            for(int y = 0; y < n; ++y) {
                if(t.root_->children_[board[x][y] - 'a'])
                    search(board, t.root_->children_[board[x][y] - 'a'], x, y, visited, ans);
            }
        }
        return ans;
    }
    void search(vector<vector<char>>& board, TrieNode* p, int x, int y, vector<vector<int>>& visited, vector<string>& ans) {
        if(!p->str_.empty()) {
            ans.push_back(p->str_);
            p->str_.clear();//避免重复添加
        }
        visited[x][y] = 1;
        vector<int> dirs{-1, 0, 1, 0, -1};
        for(int i = 0; i < 4; ++i) {
            int nx = x + dirs[i];
            int ny = y + dirs[i + 1];
            if(nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && visited[nx][ny] != 1 && p->children_[board[nx][ny] - 'a'])
            search(board, p->children_[board[nx][ny] - 'a'], nx, ny, visited, ans);
        }
       visited[x][y] = 0;
    }
};