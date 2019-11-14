class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.empty() || vin.empty()) return nullptr;
        if(pre.size() != vin.size()) return nullptr;
        return reconstruct(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
    }
    TreeNode* reconstruct(vector<int>& pre, int left_p, int right_p, vector<int>& vin, int left_v, int right_v) {
        if(left_p == right_p) {
            return new TreeNode(pre[left_p]);
        }
        if(left_p > right_p) return nullptr;
        
        int val = pre[left_p];
        int ind = left_v;
        while(ind <= right_v) {
            if(vin[ind] == val) break;
            ++ind;
        }
        TreeNode* node = new TreeNode(val);
        node->left = reconstruct(pre, left_p + 1, left_p + ind - left_v, vin, left_v, ind - 1);
        node->right = reconstruct(pre, left_p + ind - left_v + 1, right_p, vin, ind + 1, right_v);
        return node;
    }
};