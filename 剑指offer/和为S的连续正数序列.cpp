class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        if(sum <= 2) return {};
        
        vector<vector<int>> ans;
        int left = 1;
        int right = 2;
        int mid = (sum + 1) / 2;
        while(left < mid) {
            int nsum = nSum(left, right);
            if(nsum == sum) {
                vector<int> cur;
                for(int i = left; i <= right; ++i)
                    cur.push_back(i);
                ans.push_back(std::move(cur));
                ++left;
            } else if(nsum < sum) {
                ++right;
            } else {
                ++left;
            }
        }
        return ans;
    }
    int nSum(int left, int right) {
        return (left + right) * (right - left + 1) / 2;
    }
};