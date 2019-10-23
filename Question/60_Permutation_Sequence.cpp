class Solution {
public:
    string getPermutation(int n, int k) {
        string num = "123456789";
        vector<int> f(n, 1);
        for(int i = 1; i < n; ++i) f[i] = f[i - 1] * i;

        k = k - 1; //for index
        string ans;
        for(int i = n; i >= 1; --i) {
            int j = k / f[i - 1];
            k %= f[i - 1];
            ans.push_back(num[j]);
            num.erase(j, 1);
        }
        return ans;
    }
};
