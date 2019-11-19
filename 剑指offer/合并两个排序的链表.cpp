class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode dummy(0);
        ListNode* cur = &dummy;
        
        while(pHead1 && pHead2) {
            if(pHead1->val > pHead2->val) {
                ListNode* node = pHead2->next;
                pHead2->next = nullptr;
                cur->next = pHead2;
                cur = cur->next;
                pHead2 = node;
            } else {
                ListNode* node = pHead1->next;
                pHead1->next = nullptr;
                cur->next = pHead1;
                cur = cur->next;
                pHead1 = node;
            }
        }
        if(pHead1) cur->next = pHead1;
        else cur->next = pHead2;
        return dummy.next;
    }
};