class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur) {
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* new_head = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return new_head;
    }
};