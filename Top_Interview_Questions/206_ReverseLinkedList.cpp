/*
**就地翻转
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* dummy = nullptr;
        while (head) {
            ListNode* temp = head->next;
            head->next = dummy;
            dummy = head;
            head = temp;
        }
        return dummy;
    }
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* last = head;
        ListNode* cur = last->next;
        while (cur) {
            last->next = cur->next;
            cur->next = prev->next;
            prev->next = cur;
            cur = last->next;
        }
        return dummy.next;
    }
};
/*
**recursion
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* newhead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newhead;
    }
};