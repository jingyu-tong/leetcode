class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return sumPath(root, 0);
    }
    int sumPath(TreeNode* root, int sum) {
        if(!root) return 0;
        sum = sum * 10 + root->val;
        if(!root->left && !root->right) return sum;
        return sumPath(root->left, sum) + sumPath(root->right, sum);
    }
};
