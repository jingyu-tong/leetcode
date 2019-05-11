class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return nullptr;
        return sortedArrayToBST(nums, 0, nums.size());
    }
private:
    TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right) {
        if(left >= right) return nullptr;
        
        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = sortedArrayToBST(nums, left, mid);
        node->right = sortedArrayToBST(nums, mid + 1, right);
        return node;
    }
};