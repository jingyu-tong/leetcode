class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        const int m = board.size();
        const int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(dfs(board, i, j, 0, word, visited)) return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, int x, int y, int loc, string& word, vector<vector<bool>>& visited) {
        if(loc >= word.size()) return true;
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != word[loc] || visited[x][y]) return false;

        visited[x][y] = true;
        bool ans = (dfs(board, x + 1, y, loc + 1, word, visited)
                    || dfs(board, x - 1, y, loc + 1, word, visited)
                    || dfs(board, x, y + 1, loc + 1, word, visited)
                    || dfs(board, x, y - 1, loc + 1, word, visited));
        visited[x][y] = false;
        return ans;
    }
};
