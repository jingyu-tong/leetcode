class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        while(root) {
            s_.push(root);
            root = root->left;
        }
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* t = s_.top(); s_.pop();
        int ans = t->val;
        if(t->right) {
            t = t->right;
            while(t) {
                s_.push(t);
                t = t->left;
            }
        }
        return ans;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s_.empty();
    }
private:
    stack<TreeNode*> s_;
};
