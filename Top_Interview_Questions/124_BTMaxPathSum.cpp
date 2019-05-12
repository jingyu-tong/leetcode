class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int ans = INT_MIN;
        maxPathSum(root, ans);
        return ans;
    }
private:
    int maxPathSum(TreeNode *root, int &ans) {
        if(!root) return 0;
        int left_sum = max(maxPathSum(root->left, ans), 0);
        int right_sum = max(maxPathSum(root->right, ans), 0);
        
        int sum = root->val + left_sum + right_sum;
        ans = max(ans, sum);//只有在更新答案时，才能左右都用，否则不成为路径
        return max(left_sum, right_sum) + root->val;
    }
};