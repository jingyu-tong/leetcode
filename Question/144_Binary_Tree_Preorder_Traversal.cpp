class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
    void preorder(TreeNode* root, vector<int>& ans) {
        if(!root) return;
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
};

//iteration
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(cur || !s.empty()) {
            while(cur) {
                ans.push_back(cur->val);
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top(); s.pop();
            cur = cur->right;
        }
        return ans;
    }
};
