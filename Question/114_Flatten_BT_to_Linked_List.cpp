class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        vector<TreeNode*> mem;
        preorder(root, mem);

        for(int i = 0; i < mem.size() - 1; ++i) {
            mem[i]->left = nullptr;
            mem[i]->right = mem[i + 1];
        }
    }
    void preorder(TreeNode* root, vector<TreeNode*>& mem) {
        if(!root) return;

        mem.push_back(root);
        preorder(root->left, mem);
        preorder(root->right, mem);
    }
};
//recursion
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        if(root->left) flatten(root->left);
        if(root->right) flatten(root->right);

        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = nullptr;
        while(root->right) root = root->right;
        root->right = temp;
    }
};
