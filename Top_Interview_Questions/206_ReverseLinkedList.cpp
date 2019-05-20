/*
**就地翻转
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode *dummy = nullptr;
        while(head) {
            ListNode *temp = head->next;
            head->next = dummy;
            dummy = head;
            head = temp;
        }
        return dummy;
    }
};
/*
**recursion
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode *newhead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newhead;
    }
};