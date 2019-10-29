class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
    bool isValidBST(TreeNode* root, long min, long max) {
        if(!root) return true;
        if(root->val >= max || root->val <= min) return false;
        return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
    }
};
