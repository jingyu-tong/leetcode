/*
**利用hash构建前后链表的联系，从而给random赋值
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        
        Node dummy(0);
        Node *cur = &dummy, *pre_node = head;
        unordered_map<Node*, Node*> mem;
        
        while(pre_node) {
            Node *node = new Node(pre_node->val, nullptr, nullptr);
            cur->next = node;
            mem[pre_node] = node;
            cur = cur->next; 
            pre_node = pre_node->next;
        }
        
        cur = dummy.next;
        pre_node = head;
        
        while(pre_node) {
            cur->random = mem[pre_node->random];
            cur = cur->next;
            pre_node = pre_node->next;
        }
        return dummy.next;
    }
};