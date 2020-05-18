class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        auto subarray_count = [&](int k) {
            vector<int> count(A.size() + 1);  // like fast hashmap
            int ans = 0;
            int i = 0;
            for (int j = 0; j < A.size(); ++j) {
                if (count[A[j]]++ == 0) --k;
                while (k < 0)
                    if (--count[A[i++]] == 0) ++k;
                ans += j - i + 1;
            }
            return ans;
        };
        return subarray_count(K) - subarray_count(K - 1);
    }
};