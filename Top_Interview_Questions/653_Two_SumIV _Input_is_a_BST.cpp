class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> mem;
        return findTargetWithMem(root, k, mem);
    }
    
    bool findTargetWithMem(TreeNode* root, int k, unordered_set<int>& mem) {
        if (!root) return false;

        if (mem.count(k - root->val) != 0) return true;
        mem.insert(root->val);
        return findTargetWithMem(root->left, k, mem) || findTargetWithMem(root->right, k, mem);
    }
};