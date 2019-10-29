class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return generateTrees(1, n);
    }
    vector<TreeNode*> generateTrees(int start, int end) {
        if (start > end) return {nullptr};

        vector<TreeNode*> ans;
        for(int i = start; i <= end; ++i) {
            auto left = generateTrees(start, i - 1);
            auto right = generateTrees(i + 1, end);
            for(auto& l : left) {
                for(auto& r : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};
