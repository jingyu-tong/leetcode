/*
**用了visited, O(mn)
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return;
        const int m = matrix.size();
        const int n = matrix[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(visited[i][j] == true) continue;
                visited[i][j] = true;
                if(matrix[i][j] == 0) {
                    for(int k = 0; k < matrix[i].size(); ++k) {
                        if(matrix[i][k] != 0)
                            visited[i][k] = true;
                        matrix[i][k] = 0;
                    }
                    for(int k = 0; k < matrix.size(); ++k) {
                        if(matrix[k][j] != 0)
                            visited[k][j] = true;
                        matrix[k][j] = 0;
                    }
                }
            }
        }
    }
};
/*
**就地采用矩阵首行首列作为label
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return;
        const int m = matrix.size();
        const int n = matrix[0].size();
        bool first_row = false, first_col = false;
        for(int i = 0; i < n; ++i) {
            if(matrix[0][i] == 0)
                first_row = true;
        }
        for(int i = 0; i < m; ++i) {
            if(matrix[i][0] == 0)
                first_col = true;
        }
        
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                if(matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
            }
        }
        if(first_row)
            for(auto& i : matrix[0])
                i = 0;
        if(first_col)
            for(int i = 0; i < m; ++i) 
                matrix[i][0] = 0;
    }
};

