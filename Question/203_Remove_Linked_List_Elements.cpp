class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return nullptr;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* cur = head;
        
        while(cur) {
            if(cur->val == val) {
                ListNode* del = cur;
                cur = cur->next;
                prev->next = cur;
                delete del;
                continue;
            }
            prev = cur;
            cur = cur->next;
        }
        
        return dummy.next;
    }
};