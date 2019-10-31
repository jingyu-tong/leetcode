//如果不断在前端插入，那么每次遍历都需要移动O(c) c为当前层数
//最后复杂度为O(1) + O(2) + ... + O(h) = O(h^2)
//如果在后头插入，最后逆序，插入只需要O(1)，逆序也只要O(h)的时间，快很多
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            vector<int> cur;
            for(int i = q.size(); i >= 1; --i) {
                TreeNode* node = q.front(); q.pop();
                cur.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.insert(ans.begin(), cur);
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            vector<int> cur;
            for(int i = q.size(); i >= 1; --i) {
                TreeNode* node = q.front(); q.pop();
                cur.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(cur);
        }
        return vector<vector<int>> (ans.rbegin(), ans.rend());
    }
};
