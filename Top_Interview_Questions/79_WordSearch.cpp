class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        const int m = board.size();
        const int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(dfs(board, word, 0, i, j, visited)) return true;      
            }
        } 
        return false;
    }
private:
    bool dfs(vector<vector<char>>& board, string& word, int loc, int x, int y, vector<vector<bool>>& visited) {
        if(loc >= word.size()) return true;
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || visited[x][y] || board[x][y] != word[loc])
            return false;
        
        visited[x][y] = true;//对下屏蔽
        bool ans = (dfs(board, word, loc + 1, x + 1, y, visited) 
                    || dfs(board, word, loc + 1, x - 1, y, visited)
                    || dfs(board, word, loc + 1, x, y + 1, visited)
                    || dfs(board, word, loc + 1, x, y - 1, visited));
        visited[x][y] = false;//对上打开
        return ans;
    }
};