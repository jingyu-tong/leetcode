class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        vector<bool> prime(n, true);
        for(int i = 2; i < n; ++i) {
            if(prime[i]) {
                ++ans;
                for(int j = 2; i * j < n; ++j) 
                    prime[i * j] = false;
            }
        }
        return ans;
    }
};
