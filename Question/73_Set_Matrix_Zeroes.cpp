class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return;
        const int m = matrix.size();
        const int n = matrix[0].size();

        bool first_row = false;
        bool first_col = false;
        for(int i = 0;  i < m; ++i) {
            if(matrix[i][0] == 0)
                first_col = true;
        }
        for(int i = 0; i < n; ++i) {
            if(matrix[0][i] == 0)
                first_row = true;
        }

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                if(matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
            }
        }

        if(first_row) {
            for(int i = 0; i < n; ++i) {
                matrix[0][i] = 0;
            }
        }
        if(first_col) {
            for(int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};
