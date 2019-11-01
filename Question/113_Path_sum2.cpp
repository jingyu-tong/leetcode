class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> cur;
        pathSum(root, sum, cur, ans);
        return ans;
    }
    void pathSum(TreeNode* root, int sum, vector<int>& cur, vector<vector<int>>& ans) {
        if(!root) return;

        cur.push_back(root->val);
        if(!root->left && !root->right) {
            if(sum == root->val)
                ans.push_back(cur);
        }
        pathSum(root->left, sum - root->val, cur, ans);
        pathSum(root->right, sum - root->val, cur, ans);
        cur.pop_back();
    }
};
