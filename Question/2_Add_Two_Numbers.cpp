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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;

        int flag = 0; //进位标志
        while(l1 || l2) {
            int num = l1 ? l1->val : 0;
            num += l2 ? l2->val : 0;
            num += flag;
            flag = num / 10;

            cur->next = new ListNode(num % 10);
            cur = cur->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(flag) cur->next = new ListNode(flag);
        return dummy.next;
    }
};
