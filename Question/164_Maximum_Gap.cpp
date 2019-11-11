class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;

        int min_val = INT_MAX;
        int max_val = INT_MIN;
        int n = nums.size();
        for(auto& num : nums) {
            min_val = min(min_val, num);
            max_val = max(max_val, num);
        }

        int size = (max_val - min_val) / n + 1; //capacity of the bucket
        int m = (max_val - min_val) / size + 1; //num of bucket

        //这题，桶内没必要排序，维护最大和最小即可，答案在pre的最大，和cur最小里取得
        vector<int> bucket_max(m, INT_MIN);
        vector<int> bucket_min(m, INT_MAX);
        for(auto& num : nums) {
            int idx = (num - min_val) / size;
            bucket_max[idx] = max(bucket_max[idx], num);
            bucket_min[idx] = min(bucket_min[idx], num);
        }

        int ans = 0;
        int pre = 0;
        for(int cur = 1; cur < m; ++cur) {
            if(bucket_max[cur] == INT_MIN || bucket_min[cur] == INT_MAX) continue;
            ans = max(ans, bucket_min[cur] - bucket_max[pre]);
            pre = cur;
        }
        return ans;
    }
};
