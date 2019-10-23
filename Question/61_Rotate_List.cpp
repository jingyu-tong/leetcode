/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode dummy(0);
        ListNode* prev = &dummy;
        prev->next = head;
        int length = 0;
        while(prev->next) {
            prev = prev->next;
            ++length;
        }
        if(length == 0 || length == 1) return head;

        ListNode* last = prev;
        prev = &dummy;
        int m = length - k % length;
        if(m == length) return head;

        while(m) {
            prev = prev->next;
            --m;
        }

        ListNode* newhead = prev->next;
        prev->next = nullptr;
        dummy.next = newhead;
        last->next = head;
        return dummy.next;
    }
};
//连成环，再断开，好
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) return NULL;
        int n = 1;
        ListNode *cur = head;
        while (cur->next) {
            ++n;
            cur = cur->next;
        }
        cur->next = head;
        int m = n - k % n;
        for (int i = 0; i < m; ++i) {
            cur = cur->next;
        }
        ListNode *newhead = cur->next;
        cur->next = NULL;
        return newhead;
    }
};
