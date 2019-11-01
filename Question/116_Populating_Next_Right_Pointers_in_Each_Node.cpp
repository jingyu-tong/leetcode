class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        if(!root->left) return root;

        root->left->next = root->right;
        root->right->next = root->next ? root->next->left : nullptr;
        connect(root->left);
        connect(root->right);
        return root;
    }
};
