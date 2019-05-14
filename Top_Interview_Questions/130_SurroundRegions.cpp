class Solution {
public:
    void solve(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                //边界处理
                if((i == 0 || i == board.size() - 1 || j == 0 || j == board[0].size() - 1) && board[i][j] == 'O')
                    dfs(board, i, j);
            }
        }
        
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '$') board[i][j] = 'O';
            }
        }
    }
private:
    void dfs(vector<vector<char>> &board, int x, int y) {
        if(x < 0 || x >= board.size() || y < 0 || y >= board[x].size() || board[x][y] == 'X' || board[x][y] == '$')//visited or X
            return;
        board[x][y] = '$';
        dfs(board, x + 1, y);
        dfs(board, x - 1, y);
        dfs(board, x, y + 1);
        dfs(board, x, y - 1);
    }
};