class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(!root) return {};
        vector<int> cur;
        vector<vector<int>> ans;
        dfs(root, expectNumber, cur, ans);
        sort(ans.begin(), ans.end(), [](vector<int>& x, vector<int>& y) {return x.size() > y.size();});
        return ans;
    }
    void dfs(TreeNode* root, int target, vector<int>& cur, vector<vector<int>>& ans) {
        if(!root) return;
        if(!root->left && !root->right) {
            if(target == root->val) {
                cur.push_back(root->val);
                ans.push_back(cur);
                cur.pop_back();
            }
            return;
        }
        cur.push_back(root->val);
        dfs(root->left, target - root->val, cur, ans);
        dfs(root->right, target - root->val, cur, ans);
        cur.pop_back();
    }
};