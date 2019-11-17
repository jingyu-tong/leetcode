class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(str == nullptr) return true;
        
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(hasPath(matrix, rows, cols, i, j, str, 0, visited)) return true;
            }
        }
        return false;
    }
private:
    bool hasPath(char* matrix, int rows, int cols, int x, int y, char* str, int ind, vector<vector<int>>& visited) {
        if(str[ind] == '\0') return true;
        
        if(x < 0 || x >= rows || y < 0 || y >= cols) return false;
        if(visited[x][y] == 1) return false;
        if(str[ind] != matrix[x * cols + y]) return false;
        
        visited[x][y] = 1;
        bool ans = hasPath(matrix, rows, cols, x + 1, y, str, ind + 1, visited)
                    || hasPath(matrix, rows, cols, x - 1, y, str, ind + 1, visited)
                    || hasPath(matrix, rows, cols, x, y + 1, str, ind + 1, visited)
                    || hasPath(matrix, rows, cols, x, y - 1, str, ind + 1, visited);
        visited[x][y] = 0;
        return ans;
    }

};