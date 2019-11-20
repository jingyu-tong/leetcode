class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(!pRoot1 || !pRoot2) return false;
        
        return dfs(pRoot1, pRoot2) 
                || HasSubtree(pRoot1->left, pRoot2)
                || HasSubtree(pRoot1->right, pRoot2);
    }
    bool dfs(TreeNode* node1, TreeNode* node2) {
        if(!node2) return true;
        if(!node1) return false;
        if(node1->val != node2->val) return false;
        return dfs(node1->left, node2->left) && dfs(node1->right, node2->right);
    }
};