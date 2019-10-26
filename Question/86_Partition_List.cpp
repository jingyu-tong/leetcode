class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy1(0);
        ListNode dummy2(0);

        ListNode* head_less = &dummy1;
        ListNode* head_more = &dummy2;

        while(head) {
            if(head->val < x) {
                head_less->next = head;
                ListNode* temp = head->next;
                head->next = nullptr;
                head = temp;
                head_less = head_less->next;
            } else {
                head_more->next = head;
                ListNode* temp = head->next;
                head->next = nullptr;
                head = temp;
                head_more = head_more->next;
            }
        }
        head_less->next = dummy2.next;
        return dummy1.next;
    }
};
