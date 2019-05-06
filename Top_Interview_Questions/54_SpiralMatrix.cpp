/*
**根据方向，每次访问后，减小该维度的规模
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return {};
        vector<int> ans;
        
        int dir = 0;// 0 行，1 列
        int up_down = 0; // 0 +, 1 -
        int x = 0, y = 0;
        int nx = matrix.size(), ny = matrix[0].size();
        while(nx > 0 && ny > 0) {
            int n = dir == 0 ? ny : nx;
            for(int i = 0; i < n; ++i) {
                if(dir == 0 && up_down == 0)
                    y += 1;
                else if(dir == 0 && up_down == 1)
                    y -= 1;
                else if(dir == 1 && up_down == 0) 
                    x += 1;
                else
                    x -= 1;
                ans.push_back(matrix[x][y - 1]);
            }
            if(dir == 0 && up_down == 0) {
                --nx;
                dir = 1;
            }   
            else if(dir == 0 && up_down == 1) {
                --nx;
                dir = 1;
            } else if(dir == 1 && up_down == 0) {
                --ny;
                dir = 0;
                up_down = 1;
            } else {
                --ny;
                dir = 0;
                up_down = 0;
            }         
        }
        return ans;
    }
};