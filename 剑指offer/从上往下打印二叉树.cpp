class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        if(!root) return {};
        
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            for(int i = q.size(); i > 0; --i) {
                TreeNode* node = q.front(); q.pop();
                ans.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return ans;
    }
};