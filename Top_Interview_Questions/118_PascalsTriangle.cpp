class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0) return {};
        if(numRows == 1) return {{1}};
        if(numRows == 2) return {{1}, {1, 1}};
        
        vector<vector<int>> ans{{1}, {1, 1}};
        for(int i = 2; i < numRows; ++i) {
            vector<int> cur(i + 1, 1);
            for(int j = 0; j < ans[i - 1].size() - 1; ++j) {
                cur[j + 1] = ans[i - 1][j] + ans[i - 1][j + 1];
            }
            ans.push_back(cur);
        }
        return ans;
    }
};