class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(!pHead) return nullptr;
        
        ListNode* fast = pHead;
        ListNode* slow = pHead;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast) break;
        }
        if(!fast || !fast->next) return nullptr; //没环
        
        //有环
        slow = pHead;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};