class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(!pRoot) return 0;
        
        return inorder(pRoot, 1);
    }
    int inorder(TreeNode* pRoot, int level) {
        if(!pRoot->left && !pRoot->right) return level;
        
        int l = level + 1;
        int r = level + 1;
        if(pRoot->left) l = inorder(pRoot->left, level + 1); 
        if(pRoot->right) r = inorder(pRoot->right, level + 1);
        return max(l, r);
    }
};