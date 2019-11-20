class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        return isEqual(pRoot, pRoot);
    }
    bool isEqual(TreeNode* node1, TreeNode* node2) {
        if(!node1 && !node2) return true;
        if(!node1 || !node2) return false;
        
        if(node1->val != node2->val) return false;
        return isEqual(node1->left, node2->right) && isEqual(node1->right, node2->left);
    }