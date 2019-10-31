class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
private:
    TreeNode* buildTree(vector<int>& preorder, int p_left, int p_right, vector<int>& inorder, int i_left, int i_right) {
        if(p_left > p_right || i_left > i_right) return nullptr;
        int i = 0;
        for(i = i_left; i <= i_right; ++i) {
            if(preorder[p_left] == inorder[i])
                break;
        }

        TreeNode* node = new TreeNode(preorder[p_left]);
        node->left = buildTree(preorder, p_left + 1, p_left + i - i_left, inorder, i_left, i - 1); //左半部分有i - i_left个， 在i_left到i - 1之间
        node->right = buildTree(preorder, p_left + i - i_left + 1, p_right, inorder, i + 1, i_right);
        return node;
    }
};
