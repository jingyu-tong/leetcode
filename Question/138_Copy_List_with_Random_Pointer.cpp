class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;

        unordered_map<Node*, Node*> mem; //old, new
        mem[head] = new Node(head->val, nullptr, nullptr);
        Node* prev = head;
        Node* cur = head->next;
        while(cur) {
            if(mem.count(cur) == 0) {
                mem[cur] = new Node(cur->val, nullptr, nullptr);
            }
            mem[prev]->next = mem[cur];
            prev = cur;
            cur = cur->next;
        }

        cur = head;
        while(cur) {
            mem[cur]->random = mem[cur->random];
            cur = cur->next;
        }

        return mem[head];
    }
};
