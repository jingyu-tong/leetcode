/*
**recursion
*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return max(1 + maxDepth(root->left), 1 + maxDepth(root->right));
    }
};
/*
**iteration
*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            ++level;
            for(int i = q.size(); i > 0; --i) {
                TreeNode* node = q.front(); q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return level;
    }
};