class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0,
                         inorder.size() - 1);
    }

private:
    TreeNode* buildTree(vector<int>& preorder, int p_left, int p_right,
                        vector<int>& inorder, int i_left, int i_right) {
        if (p_left > p_right || i_left > i_right) return nullptr;
        int i = 0;
        for (i = i_left; i <= i_right; ++i) {
            if (preorder[p_left] == inorder[i]) break;
        }

        TreeNode* node = new TreeNode(preorder[p_left]);
        node->left = buildTree(
            preorder, p_left + 1, p_left + i - i_left, inorder, i_left,
            i - 1);  //左半部分有i - i_left个， 在i_left到i - 1之间
        node->right = buildTree(preorder, p_left + i - i_left + 1, p_right,
                                inorder, i + 1, i_right);
        return node;
    }
};

// in-place 
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || preorder.size() != inorder.size())
            return nullptr;

        int val = preorder[0];

        // find the index
        int idx = 0;
        for (; idx < inorder.size(); ++idx) {
            if (inorder[idx] == val) break;
        }

        TreeNode* node = new TreeNode(val);
        // divide vectors
        vector<int> l_p(preorder.begin() + 1, preorder.begin() + 1 + idx);
        vector<int> l_i(inorder.begin(), inorder.begin() + idx);
        vector<int> r_p(preorder.begin() + idx + 1, preorder.end());
        vector<int> r_i(inorder.begin() + idx + 1, inorder.end());
        node->left = buildTree(l_p, l_i);
        node->right = buildTree(r_p, r_i);
        return node;
    }
};