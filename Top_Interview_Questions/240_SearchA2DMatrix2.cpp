class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        const int m = matrix.size();
        const int n = matrix[0].size();
        int x = m - 1, y = 0;//初始在左下角
        while(1) {
            if(target > matrix[x][y]) ++y;
            else if(target < matrix[x][y]) --x;
            else return true;
            if(x < 0 || y >= n) return false;
        }
        return false;
    }
};