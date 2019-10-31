class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> cur;
            for(int i = q.size(); i >= 1; --i) {
                TreeNode* t = q.front(); q.pop();
                cur.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            ans.push_back(cur);
        }
        return ans;
    }
};
