class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size();
        int n = matrix[0].size();
        int rounds = (min(m, n) + 1) / 2;
        vector<int> ans;

        int nx = n;
        int ny = m;
        for(int i = 0; i < rounds; ++i, nx -= 2, ny -=2) {
            for(int col = i; col < i + nx; ++col) {
                ans.push_back(matrix[i][col]);
            }
            for(int row = i + 1; row < i + ny; ++row) {
                ans.push_back(matrix[row][i + nx - 1]);
            }
            if(nx == 1 || ny == 1) break;

            for(int col = i + nx - 2; col >= i; --col) {
                ans.push_back(matrix[i + ny - 1][col]);
            }
            for(int row = i + ny - 2; row >= i + 1; --row) {
                ans.push_back(matrix[row][i]);
            }
        }
        return ans;
    }
};
