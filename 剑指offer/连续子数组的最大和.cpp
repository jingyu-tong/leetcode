class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty()) return -1;
        
        const int n = array.size();
        if(n == 1) return array[0];
        vector<int> dp(n);
        dp[0] = array[0];
        for(int i = 1; i < n; ++i) {
            dp[i] = dp[i - 1] < 0 ? array[i] : array[i] + dp[i - 1];
        }
        return *max_element(dp.begin(), dp.end());
    }
};