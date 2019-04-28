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
        ListNode* ans = new ListNode(0);
        ListNode* dummy = ans;
        int carry = 0;
        
        while(l1 || l2) {
            //需要检查是否存在，不能直接访问
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int temp = val1 + val2 + carry;
            carry = temp / 10;
            ans->val = temp % 10;
            
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            
            if(l1 || l2) {
                ans->next = new ListNode(0);
                ans = ans->next;
            }
        }
        
        if(carry == 1)
            ans->next = new ListNode(1);
        return dummy;
    }
};