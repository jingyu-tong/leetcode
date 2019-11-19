class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(!pHead) return nullptr;
        
        ListNode* pre = pHead;
        ListNode* cur = pHead->next;
        pre->next = nullptr;
        while(cur) {
            ListNode* node = cur->next;
            cur->next = pre;
            pre = cur;
            cur = node;
        }
        return pre;
    }
};