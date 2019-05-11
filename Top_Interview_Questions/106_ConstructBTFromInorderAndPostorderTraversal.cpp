class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
private:
    TreeNode* buildTree(vector<int>& inorder, int i_left, int i_right, vector<int>& postorder, int p_left, int p_right) {
        if(p_left > p_right || i_left > i_right) return nullptr;
        
        int cur = 0;
        for(cur = i_left; cur <= i_right; ++cur) {
            if(inorder[cur] == postorder[p_right])
                break;
        }
        
        TreeNode* node = new TreeNode(postorder[p_right]);
        node->left = buildTree(inorder, i_left, cur - 1, postorder, p_left, p_left + cur - i_left - 1);
        node->right = buildTree(inorder, cur + 1, i_right, postorder, p_left + cur - i_left, p_right - 1);
        return node;
    }
};