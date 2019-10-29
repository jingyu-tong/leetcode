class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};

        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* cur = root;

        while(cur || !s.empty()) {
            while(cur) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top(); s.pop();
            ans.push_back(cur->val);
            cur = cur->right;
        }

        return ans;
    }
};
