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
