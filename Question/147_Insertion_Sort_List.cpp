class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return head;

        ListNode dummy(INT_MIN);
        dummy.next = head;
        ListNode* end = head;
        while(end->next) {
            ListNode* temp = end->next;
            ListNode* cur = &dummy;
            while(cur != end && cur->next->val < temp->val)
                cur = cur->next;

            if(cur == end) {
                end = temp;
                continue;
            }
            //将temp断开，连到cur之后
            end->next = temp->next;
            ListNode* next = cur->next;
            cur->next = temp;
            temp->next = next;
        }
        return dummy.next;
    }
};
