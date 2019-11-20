class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(!pRoot) return;
        if(!pRoot->left && !pRoot->right) return;
        
        swap(pRoot->left, pRoot->right);
        if(pRoot->left) Mirror(pRoot->left);
        if(pRoot->right) Mirror(pRoot->right);
    }
};