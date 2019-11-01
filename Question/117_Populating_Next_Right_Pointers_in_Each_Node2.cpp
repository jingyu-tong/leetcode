class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;

        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            for(int i = q.size(); i >= 1; --i) {
                Node* node = q.front(); q.pop();
                if(i != 1) node->next = q.front();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return root;
    }
};
//
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;

        Node dummy(0);
        Node* cur = &dummy;
        Node* head = root;

        while(root) {
            if(root->left) {
                cur->next = root->left;
                cur = cur->next;
            }
            if(root->right) {
                cur->next = root->right;
                cur = cur->next;
            }
            root = root->next; //向右
            if(!root) {
                cur = &dummy;
                root = dummy.next;
                dummy.next = nullptr;
            }
        }
        return head;
    }
};
