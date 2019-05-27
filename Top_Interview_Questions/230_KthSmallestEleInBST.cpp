class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        inorder(root, k, ans);
        return ans;
    }
private:
    void inorder(TreeNode* root, int& k, int& ans) {
        if(!root) return;
        inorder(root->left, k, ans);
        if(k == 0) return;
        ans = root->val;
        --k;
        inorder(root->right, k, ans);
    }
};