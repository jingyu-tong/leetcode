class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(!pRoot || k == 0) return nullptr;
        
        return inorder(pRoot, k);
    }
    TreeNode* inorder(TreeNode* pRoot, int& k) {
        if(!pRoot) return nullptr;
        
        TreeNode* ans = nullptr;
        ans = inorder(pRoot->left, k);
        if(ans == nullptr) {
            if(k == 1) return pRoot;
            else 
                --k;
        } else
            return ans;
        
        ans = inorder(pRoot->right, k);
        return ans;
    }
    
};