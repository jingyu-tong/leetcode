class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }
    TreeNode* buildBST(vector<int>& nums, int left, int right) {
        if(left > right) return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = buildBST(nums, left, mid - 1);
        node->right = buildBST(nums, mid + 1, right);
        return node;
    }
};
