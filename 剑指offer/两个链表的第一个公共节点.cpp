class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        stack<ListNode*> s1;
        stack<ListNode*> s2;
        
        while(pHead1) {
            s1.push(pHead1);
            pHead1 = pHead1->next;
        }
        while(pHead2) {
            s2.push(pHead2);
            pHead2 = pHead2->next;
        }
        
        ListNode* ans = nullptr;
        while(!s1.empty() && !s2.empty()) {
            if(s1.top() == s2.top()) {
                ans = s1.top();
                s1.pop();
                s2.pop();
            } else
                break;
        }
        return ans;
    }
};

class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int count1 = 0;
        int count2 = 0;
        
        ListNode* cur1 = pHead1;
        while(cur1) {
            ++count1;
            cur1 = cur1->next;
        }
        ListNode* cur2 = pHead2;
        while(cur2) {
            ++count2;
            cur2 = cur2->next;
        }
        
        if(count1 > count2) {
            int count = count1 - count2;
            while(count--) {
                pHead1 = pHead1->next;
            }
        } else if(count1 < count2) {
            int count = count1 - count2;
            while(count--) {
                pHead2 = pHead2->next;
            }
        } else 
            ;
        while(pHead1 && pHead2) {
            if(pHead1 == pHead2) return pHead1;
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        
        return nullptr;
    }
};