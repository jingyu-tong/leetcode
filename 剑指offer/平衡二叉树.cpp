class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(!pRoot) return true; //空树是不是？
        
        bool ans = true;
        //bottom up
        inorder(pRoot, ans);
        return ans;
    }
    
    //返回高度
    int inorder(TreeNode* pRoot, bool& ans) {
        if(!pRoot) return 0;
        if(ans == false) return -1;
        int l = inorder(pRoot->left, ans);
        int r = inorder(pRoot->right, ans);
        
        if(abs(l - r) > 1) ans = false;
        
        return max(l, r) + 1;
    }
};