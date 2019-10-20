class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();

        for(int i = 0; i < n / 2; ++i) {
            for(int j = i; j < n - 1 - i; ++j) {
                int temp = matrix[i][j];//四个旋转点赋值，直至旋转点重复，到下一行
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n -  1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = temp;
            }
        }
    }
};
