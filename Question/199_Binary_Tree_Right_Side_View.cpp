class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};

        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            for(int i = q.size(); i > 0; --i) {
                TreeNode* node = q.front(); q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                if(i == 1) ans.push_back(node->val);
            }
        }
        return ans;
    }
};
