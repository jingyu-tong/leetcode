class Solution {
public:
  void gameOfLife(vector<vector<int>>& board) {
    int m = board.size();
    int n = m ? board[0].size() : 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        int lives = 0;
        // Scan the 3x3 region including (j, i).
        for (int y = max(0, i - 1); y < min(m, i + 2); ++y)
          for (int x = max(0, j - 1); x < min(n, j + 2); ++x)
            lives += board[y][x] & 1;
        if (lives == 3 || lives - board[i][j] == 3) board[i][j] |= 0b10;
      }
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) 
        board[i][j] >>= 1;
  }
};