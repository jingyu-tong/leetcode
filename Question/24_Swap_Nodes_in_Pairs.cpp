class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        ListNode* prev = &dummy;
        dummy.next = head;
        while(prev->next && prev->next->next) {
            ListNode* temp = prev->next->next;
            prev->next->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
            prev = temp->next;
        }
        return dummy.next;
    }
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* temp = head->next;
        head->next = swapPairs(temp->next);
        temp->next = head;
        return temp;
    }
};
