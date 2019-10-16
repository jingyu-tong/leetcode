//这题没到k是不要翻转的！！！
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* cur = head;
        ListNode* prev = &dummy;
        for(int i = 1; cur; ++i) {
            if(i % k == 0) { //找到分段
                prev = reverseOneGroup(prev, cur->next);
                cur = prev->next;
            } else {
                cur = cur->next;
            }
        }
        return dummy.next;
    }
    ListNode* reverseOneGroup(ListNode* pre, ListNode* next) {
        ListNode *last = pre->next, *cur = last->next;
        while(cur != next) {
            last->next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = last->next;
        }
        return last;
    }
};
