class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            ++level;
            for(int i = q.size(); i >= 1; --i) {
                TreeNode* t = q.front(); q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
        }
        return level;
    }
};
