class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        if(A.size() <= 1) return {};
        
        const int n = A.size();
        vector<int> ans(n, 1);
        for(int i = 1; i < n; ++i) { //下三角
            ans[i] = ans[i - 1] * A[i - 1];
        }
        
        int temp = 1;
        for(int i = n - 2; i >= 0; --i) { //上三角
            temp *= A[i + 1];
            ans[i] *= temp;
        }
        return ans;
    }
};