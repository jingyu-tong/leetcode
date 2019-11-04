class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) return;

        const int m = board.size();
        const int n = board[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if( (i == 0 || i == m - 1 || j == 0 || j == n - 1) && board[i][j] == 'O')
                    dfs(board, i, j);
            }
        }

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(board[i][j] == '$') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
    void dfs(vector<vector<char>>& board, int i, int j) {
        if(i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] == 'X' || board[i][j] == '$') return;
        board[i][j] = '$';
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }
};
