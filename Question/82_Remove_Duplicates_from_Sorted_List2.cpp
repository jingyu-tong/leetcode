class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        ListNode* cur = &dummy;


        while(head && head->next) {
            int flag  = false;
            while(head && head->next && head->val == head->next->val) {
                head = head->next;
                flag = true;
            }
            if(flag || !head) {head = head->next; continue;}

            ListNode* temp = head->next;
            head->next = nullptr;
            cur->next = head;
            cur = cur->next;
            head = temp;
        }
        if(head) cur->next = head;
        return dummy.next;
    }
};
