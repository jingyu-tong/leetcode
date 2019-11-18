//no delete, memory leakage
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(!pHead) return nullptr;
        
        ListNode dummy(0);
        ListNode* cur = &dummy;
        
        while(pHead) {
            ListNode* temp = pHead;
            while(pHead->next && pHead->next->val == pHead->val)
                pHead = pHead->next;
            if(temp == pHead) {
                cur->next = temp;
                cur = cur->next;
            }
            pHead = pHead->next;
        }
        cur->next = nullptr;
        return dummy.next;
    }
};