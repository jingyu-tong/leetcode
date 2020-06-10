class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix.front().front();
        int right = matrix.back().back() + 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int total = 0;
            for (auto& row : matrix) {
                total += distance(row.begin(),
                                  upper_bound(row.begin(), row.end(), mid));
            }
            if (total < k)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};