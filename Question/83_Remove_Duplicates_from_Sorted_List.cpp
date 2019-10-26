class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        ListNode* prev = &dummy;

        while(head) {
            prev->next = head;
            prev = prev->next;
            ListNode* cur = head;
            while(cur->next && cur->next->val == cur->val)
                cur = cur->next;
            head = cur->next;
        }
        prev->next = nullptr;
        return dummy.next;
    }
};
