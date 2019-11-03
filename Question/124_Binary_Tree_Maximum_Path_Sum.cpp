class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxPathSum(root, ans);
        return ans;
    }
    int maxPathSum(TreeNode* root, int& ans) {
        if(!root) return 0;

        int left_sum = root->val + max(maxPathSum(root->left, ans), 0);
        int right_sum = root->val + max(maxPathSum(root->right, ans), 0);
        ans = max(ans, left_sum + right_sum - root->val);
        return max(left_sum, right_sum);
    }
};
