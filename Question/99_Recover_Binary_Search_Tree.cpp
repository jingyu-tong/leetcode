//O(h)
class Solution {
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val, second->val);
    }
    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);
        if(!pre) pre = root;
        else {
            if(pre->val > root->val) {
                if (!first) first = pre; //第一个不符合的
                second = root;
            }
            pre = root;
        }
        inorder(root->right);
    }
private:
    TreeNode* pre = nullptr;
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
};
//O(1) Morris https://www.cnblogs.com/anniekim/archive/2013/06/15/morristraversal.html
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr, *parent = nullptr;
        //morris traversal
        TreeNode* pre;
        TreeNode* cur = root;
        while(cur){
            if(!cur->left){
                if(parent && parent->val > cur->val){
                    if(!first) first = parent;
                    second = cur;
                }

                parent = cur;
                cur = cur->right;
            }
            else{
                pre = cur->left;
                while(pre->right && pre->right != cur)
                    pre = pre->right;
                if(!pre->right){
                    pre->right = cur;
                    cur = cur->left;
                }
                else{
                    pre->right = nullptr;
                    if(parent && parent->val > cur->val){
                        if(!first) first = parent;
                        second = cur;
                    }
                    parent = cur;
                    cur = cur->right;
                }
            }
        }
        swap(first->val, second->val);
        // return root;
    }
};
