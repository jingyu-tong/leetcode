class Solution {
public:
    int totalNQueens(int n) {
        board_ = vector<string>(n, string(n, '.'));
        cols_ = vector<bool>(n, false);
        dig1_ = vector<bool>(2 * n - 1, false);
        dig2_ = vector<bool>(2 * n - 1, false);

        dfs(0);
        return ans_;
    }
private:
    vector<string> board_;
    vector<bool> cols_;
    vector<bool> dig1_; //x + y
    vector<bool> dig2_; //x - y + n - 1
    int ans_;

    void dfs(int level) {
        if(level >= board_.size()) {
            ans_++;
            return;
        }
        for(int i = 0; i < board_.size(); ++i) {
            if(isUsed(level, i)) continue;
            updatePara(level, i, true);
            board_[level][i] = 'Q';
            dfs(level + 1);
            board_[level][i] = '.';
            updatePara(level, i, false);
        }
    }

    bool isUsed(int x, int y) {
        return !(!cols_[y]
            && !dig1_[x + y]
            && !dig2_[x - y + board_.size() - 1]);
    }
    void updatePara(int x, int y, bool state) {
        cols_[y] = state;
        dig1_[x + y] = state;
        dig2_[x - y + board_.size() - 1] = state;
    }
};
