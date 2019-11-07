class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i = 0; i < points.size(); ++i) {
            map<pair<int, int>, int> mem; //<dx, dy> counts;
            int duplicates = 1;
            for(int j = i + 1; j < points.size(); ++j) {
                if(points[j][0] == points[i][0] && points[j][1] == points[i][1]) {
                    ++duplicates;
                    continue;
                }
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int d = gcd(dx, dy);
                ++mem[{dx / d, dy / d}];
            }
            ans = max(ans, duplicates);
            for(auto& ele : mem) {
                ans = max(ans, ele.second + duplicates);
            }
        }
        return ans;
    }
    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b); //余数为0了，a即为公约数
    }
};
