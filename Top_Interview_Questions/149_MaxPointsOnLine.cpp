/*
**利用map统计两点斜率相同的个数   为了避免使用double，将dx和dy除以公约数后储存
*/
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i = 0; i < points.size(); ++i) {
            map<pair<int, int>, int> mem;
            int dup = 1;
            for(int j = i + 1; j < points.size(); ++j) {
                if(points[i][0]== points[j][0] && points[i][1] == points[j][1]) {
                    ++dup; 
                    continue;
                }
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                
                int d = getDivisior(dx, dy);
                ++mem[{dx / d, dy / d}];
            }
            ans = max(ans, dup);
            for(const auto& m : mem) {
                ans = max(ans, m.second + dup);
            }
        }
        return ans;
    } 
private:
    int getDivisior(int dx, int dy) {
        return (dy == 0) ? dx : getDivisior(dy, dx % dy);
    }
};