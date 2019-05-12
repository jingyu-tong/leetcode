/*
**常数空间
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        Node dummy(0);//有些回答会new一个，最后就要记得释放，这里申请一个局部变量
        Node *cur = &dummy, *head = root;
        while(root) {
            //走向下一层
            if(root->left) {
                cur->next = root->left;
                cur = cur->next;
            }
            if(root->right) {
                cur->next = root->right;
                cur = cur->next;
            }
            root = root->next;//指向兄弟
            if(!root) { //走向下一层
                cur = &dummy;
                root = dummy.next;
                dummy.next = nullptr;
            }
        }
        return head;
    }
};