class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* right = head;
        int count = n;
        while(count) {
            right = right->next;
            --count;
        }

        ListNode* left = head;
        ListNode* prev = left;
        while(right) {
            right = right->next;
            prev = left;
            left = left->next;
        }
        if(prev == left) {
            ListNode* temp  = head;
            head = head->next;
            delete temp;
        } else {
            prev->next = left->next;
            delete left;
        }

        return head;
    }
};
