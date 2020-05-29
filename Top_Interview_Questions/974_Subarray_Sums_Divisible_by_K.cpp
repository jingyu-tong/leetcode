class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> mem{
            {0, 1}};  // sum % k, count，这里放0，为了统计第一个整除
        int ans = 0;
        int sum = 0;

        for (auto& ele : A) {
            sum += ele;
            int left = (sum % K + K) % K;
            ans += mem[left]++;
        }
        return ans;
    }
};
