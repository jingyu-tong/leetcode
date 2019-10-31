class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    TreeNode* buildTree(vector<int>& inorder, int i_left, int i_right, vector<int>& postorder, int p_left, int p_right) {
        if(i_left > i_right || p_left > p_right) return nullptr;

        int i = 0;
        for(i = i_left; i <= i_right; ++i) {
            if(inorder[i] == postorder[p_right]) break;
        }

        TreeNode* node = new TreeNode(postorder[p_right]);
        node->left = buildTree(inorder, i_left, i - 1, postorder, p_left, p_left + (i - i_left) - 1);
        node->right = buildTree(inorder, i + 1, i_right, postorder, p_left + (i - i_left), p_right - 1);
        return node;
    }
};
