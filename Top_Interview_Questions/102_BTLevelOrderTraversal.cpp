/*
**BFS queue iteration
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        //BFS
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            vector<int> cur;
            for(int i = q.size(); i > 0; --i) {
                TreeNode* node = q.front(); q.pop();
                cur.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(cur);
        }
        return ans;
    }
};
/*
**BFS recursion 
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        //BFS
        if(!root) return {};
        vector<vector<int>> ans;
        levelOrder(root, 0, ans);
        return ans;
    }
private:
    void levelOrder(TreeNode* root, int level, vector<vector<int>>& ans) {
        if(!root) return;
        if(level == ans.size()) ans.push_back({});
        
        ans[level].push_back(root->val);
        levelOrder(root->left, level + 1, ans);
        levelOrder(root->right, level + 1, ans);
    }
};