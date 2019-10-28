class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(0);
        ListNode* pre = &dummy;
        pre->next = head;
        for(int i = 0; i < m - 1; ++i) {
            pre = pre->next;
        }
        ListNode *cur = pre->next;
        for(int i = m; i < n; ++i) {
            ListNode *t = cur->next;
            cur->next = t->next;
            t->next = pre->next;
            pre->next = t;
        }
        return dummy.next;
    }
};
