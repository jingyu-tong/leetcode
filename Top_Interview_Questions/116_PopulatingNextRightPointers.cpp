/*
**iteration
*/
class Solution {
public:
    Node* connect(Node* root) {
        //BFS
        if(!root) return nullptr;
        
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            for(int i = q.size(); i > 0; --i) {
                Node* node = q.front(); q.pop();                
                if(i != 1)
                    node->next = q.front();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return root;
    }
};
/*
**recursion
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        
        if(root->left) root->left->next = root->right;
        if(root->right) root->right->next = root->next ? root->next->left : nullptr;
        connect(root->left);
        connect(root->right);
        return root;
    }
};