class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold < 0) return 0;
        if(rows <= 0 || cols <= 0) return 0;
        
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int ans = 0;
        count(rows, cols, 0, 0, threshold, visited, ans);
        return ans;
    }
private:
    void count(int rows, int cols, int x, int y, int threshold, vector<vector<bool>>& visited, int& ans) {
        if(x < 0 || x >= rows || y < 0 || y >= cols) return;
        if(visited[x][y] == 1) return;
        int temp = 0;
        int x_temp = x;
        while(x_temp) {
            temp += x_temp % 10;
            x_temp /= 10;
        }
        int y_temp = y;
        while(y_temp) {
            temp += y_temp % 10;
            y_temp /= 10;
        }
        if(temp > threshold) return;
        
        visited[x][y] = 1;
        ++ans;
        count(rows, cols, x + 1, y, threshold, visited, ans);
        count(rows, cols, x - 1, y, threshold, visited, ans);
        count(rows, cols, x, y + 1, threshold, visited, ans);
        count(rows, cols, x, y - 1, threshold, visited, ans);
    }
};