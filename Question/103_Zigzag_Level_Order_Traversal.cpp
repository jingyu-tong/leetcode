class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while(!q.empty()) {
            vector<int> cur;
            ++level;
            for(int i = q.size(); i > 0; --i) {
                TreeNode* node = q.front(); q.pop();
                cur.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(level % 2 == 0) reverse(cur.begin(), cur.end());
            ans.push_back(cur);
        }
        return ans;
    }
};
