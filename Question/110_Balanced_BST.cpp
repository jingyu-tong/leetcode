class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        bool balanced = true;
        height(root, balanced);
        return balanced;
    }
    int height(TreeNode* root, bool& balanced) {
        if(!root) return 0;
        int left_height = height(root->left, balanced);
        int right_height = height(root->right, balanced);
        if(left_height == -1 || right_height == -1) return -1;
        if(abs(left_height - right_height) > 1) {
            balanced = false;
            return -1;
        }
        return max(left_height, right_height) + 1;
    }
};
