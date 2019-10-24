class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;

        const int m = matrix.size();
        const int n = matrix[0].size();
        int left = 0;
        int right = m - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(matrix[mid][0] > target) right = mid - 1;
            else left = mid + 1;
        }
        int row = left - 1;
        if(row < 0) return false;
        left = 0; right = n - 1;
        while(left <= right) {
            int mid = left +(right - left) / 2;
            if(matrix[row][mid] == target) return true;
            if(matrix[row][mid] < target) left =  mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};
