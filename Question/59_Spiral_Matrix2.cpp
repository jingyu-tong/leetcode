class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));

        int target = 1;
        int m = (n + 1) / 2;
        int range = n;
        for(int i = 0; i < m; ++i, range -= 2) {
            for(int col = i; col < i + range; ++col) {
                ans[i][col] = target++;
            }
            for(int row = i + 1; row < i + range; ++row) {
                ans[row][i + range - 1] = target++;
            }
            if(n == 1) break;
            for(int col = i + range -2; col >= i; --col) {
                ans[i + range - 1][col] = target++;
            }
            for(int row = i + range -2; row >= i + 1; --row) {
                ans[row][i] = target++;
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));

        int down = 0;
        int up = n - 1;
        int left = 0;
        int right = n - 1;
        int num = 1;
        while(true) {
            for(int i = left; i <= right; ++i) ans[down][i] = num++;
            if(++down > up) break;
            for(int i = down; i <= up; ++i) ans[i][right] = num++;
            if(--right < left) break;
            for(int i = right; i >= left; --i) ans[up][i] = num++;
            if(--up < down) break;
            for(int i = up; i >= down; --i) ans[i][left] = num++;
            if (++left > right) break;
        }
        return ans;
    }
};
