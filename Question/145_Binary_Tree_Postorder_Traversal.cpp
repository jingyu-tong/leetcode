class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};

        vector<int> ans;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* last = root;
        while(!s.empty()) {
            auto cur = s.top();
            //leaf or visited his children
            if( (!cur->left && !cur->right) || last == cur->left || last == cur->right) {
                s.pop();
                ans.push_back(cur->val);
                last = cur;
            } else {
                if(cur->right) s.push(cur->right);
                if(cur->left) s.push(cur->left);
            }
        }
        return ans;
    }
};
