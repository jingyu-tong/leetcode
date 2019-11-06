class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* fast = &dummy;
        ListNode* slow = fast;

        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        //反向链表, or using stack
        ListNode* prev = slow->next;
        ListNode* cur = prev->next;
        prev->next = nullptr;
        slow->next = nullptr;

        while(cur) {
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur  = temp;
        }

        //combine two list
        cur = prev;
        slow = head;
        while(slow && cur) {
            ListNode* temp1 = cur->next;
            ListNode* temp2 = slow->next;
            slow->next = cur;
            cur->next = temp2;
            slow = temp2;
            cur = temp1;
        }

    }
};
