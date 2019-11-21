//利用BST上下界的限制判断
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty()) return false;
        
        return isBst(sequence, 0, sequence.size() - 1, INT_MIN, INT_MAX);
    }
    bool isBst(vector<int>& nums, int left, int right, int min_val, int max_val) {
        if(left > right) return true;
        
        for(int i = left; i <= right; ++i) {
            if(nums[i] >= max_val || nums[i] <= min_val) return false;
        }
        
        int root = nums[right];
        int div = left;
        for(; div < right; ++div) {
            if(nums[div] > root) break;
        }
        if(div == left) {
            return isBst(nums, left, right - 1, root, max_val);
        } else {
            return isBst(nums, left, div - 1, min_val, root) && isBst(nums, div, right - 1, root, max_val);
        }
    }
};